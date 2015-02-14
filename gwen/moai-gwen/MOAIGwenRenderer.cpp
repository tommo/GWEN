#include "moai-gwen/MOAIGwenRenderer.h"
#include "moai-gwen/MOAIGwenMgr.h"

#include "Gwen/Utility.h"
#include "Gwen/Font.h"
#include "Gwen/Texture.h"
#include "Gwen/WindowProvider.h"

#include <math.h>

#include "moai-sim/pch.h"
#include "moai-sim/MOAIDraw.h"
#include "moai-sim/MOAIGfxDevice.h"
#include <moai-sim/MOAIShaderMgr.h>
#include <moai-sim/MOAIVertexFormatMgr.h>
#include <moai-sim/MOAITexture.h>
#include <moai-sim/MOAIQuadBrush.h>


void BeginDrawString ( float scale, MOAIFont& font, float fontSize, float shadowOffsetX, float shadowOffsetY );
void DrawString ( cc8* text, float x, float y, float width, float height );
void EndDrawString ();


struct GlyphPlacement {
	MOAIGlyph* glyph;
	float x;
	float y;
};

struct TextDrawContext {
	// Text
	STLList < GlyphPlacement > mGlyphs;

	// Text data
	MOAIFont* mFont;
	float mScale;
	float mFontSize;
	float mShadowOffsetX;
	float mShadowOffsetY;

	float mOffsetX;
	float mOffsetY;
};

static TextDrawContext g_TextDrawContext;
static TextDrawContext* g_CurrentTextDrawContext = 0;

//----------------------------------------------------------------//
void BeginDrawString ( float scale, MOAIFont& font, float fontSize, float shadowOffsetX, float shadowOffsetY ) {
	
	assert ( g_CurrentTextDrawContext == 0 );
	g_CurrentTextDrawContext = &g_TextDrawContext;

	g_CurrentTextDrawContext->mFont = &font;
	g_CurrentTextDrawContext->mFontSize = fontSize;
	g_CurrentTextDrawContext->mScale = scale;
	g_CurrentTextDrawContext->mShadowOffsetX = shadowOffsetX;
	g_CurrentTextDrawContext->mShadowOffsetY = shadowOffsetY;
}

//----------------------------------------------------------------//
void DrawString ( cc8* text, float x, float y, float width, float height ) {

	// Sanity check
	size_t textLength = strlen ( text );
	if ( textLength <= 0 ) return;
	
	// Get the context data
	assert ( g_CurrentTextDrawContext );

	// Extract the 'state'
	MOAIFont& font = *g_CurrentTextDrawContext->mFont;
	float scale = g_CurrentTextDrawContext->mScale;
	float fontSize = g_CurrentTextDrawContext->mFontSize;

	// g_CurrentTextDrawContext->mOffsetX = x;
	// g_CurrentTextDrawContext->mOffsetY = y;
	
	MOAIGlyphSet* glyphSet = &font.AffirmGlyphSet ( fontSize );

	// Let's draw the string!
	float cursorX = x;
	float cursorY = y + glyphSet->GetAscent() * scale;
	MOAIGlyph* prevGlyph = 0;
	
	// Update the glyph cache
	for ( size_t i = 0; i < textLength; i++ ) {

		cc8 c = text [ i ];
		if ( c != '\n' ) {

			font.AffirmGlyph ( fontSize, c );
		}
	}
	font.ProcessGlyphs ();

	glyphSet = font.GetGlyphSet ( fontSize );
	assert ( glyphSet );

	for ( size_t i = 0; i < textLength; i++ ) {

		cc8 c = text [ i ];
		if ( c == '\n' ) {

			// Move to the next line
			cursorX = x;
			cursorY += glyphSet->GetHeight () * scale;
			prevGlyph = 0;

			if ( height > 0 && (cursorY - y) > height ) {
				break;
			}
		}
		else {

			if ( width > 0 && (cursorX - x) > width ) {
				continue;
			}

			// Get the glyph for the current character
			MOAIGlyph* glyph = glyphSet->GetGlyph ( c );
			if ( glyph && glyph->GetCode() != 0xffffffff ) {

				// Draw the current glyph
				MOAITextureBase* glyphTexture = font.GetGlyphTexture ( *glyph );
				if ( glyphTexture ) {

					GlyphPlacement placement = { glyph, cursorX, cursorY };
					g_CurrentTextDrawContext->mGlyphs.push_back( placement );
				}

				// Apply kerning
				if ( prevGlyph ) {

					MOAIKernVec kern = prevGlyph->GetKerning ( glyph->GetCode () );
					cursorX += kern.mX * scale;
				}

				// Move the cursor
				cursorX += glyph->GetAdvanceX () * scale;
			}

			prevGlyph = glyph;
		}
	}
}

//----------------------------------------------------------------//
void EndDrawString () {
	ZLRect padding;
	padding.Init( 0.0f, 0.0f, 0.0f, 0.0f );
	// Setup for drawing
	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get ();

	// Get current state
	const ZLMatrix4x4& orgWorldTransform = gfxDevice.GetVertexTransform ( MOAIGfxDevice::VTX_WORLD_TRANSFORM );
	u32 orgVtxModeInput, orgVtxModeOutput;
	gfxDevice.GetVertexMtxMode ( orgVtxModeInput, orgVtxModeOutput );

	// TODO
	//GLint orgSrcBlend, orgDestBlend;
	//glGetIntegerv ( GL_BLEND_SRC, &orgSrcBlend );
	//glGetIntegerv ( GL_BLEND_DST, &orgDestBlend );

	// Apply render state
	gfxDevice.SetShaderPreset ( MOAIShaderMgr::DECK2D_SHADER );

	gfxDevice.SetVertexMtxMode ( MOAIGfxDevice::VTX_STAGE_WORLD, MOAIGfxDevice::VTX_STAGE_MODEL );
	gfxDevice.SetBlendMode ( ZGL_BLEND_FACTOR_ONE, ZGL_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA );
	MOAIQuadBrush::BindVertexFormat ( gfxDevice );

	// Get the context data
	assert( g_CurrentTextDrawContext );
	
	MOAIFont& font = *g_CurrentTextDrawContext->mFont;
	float scale = g_CurrentTextDrawContext->mScale;

	u32 numPasses = 1;

	STLList < GlyphPlacement >::const_iterator it;
	for ( it = g_CurrentTextDrawContext->mGlyphs.begin (); it != g_CurrentTextDrawContext->mGlyphs.end (); ++it ) {

		const GlyphPlacement& glyphPlacement = *it;
		MOAIGlyph* glyph = glyphPlacement.glyph;
		MOAITextureBase* glyphTexture = font.GetGlyphTexture ( *glyph );
		glyph->Draw ( *glyphTexture, 
			glyphPlacement.x, -glyphPlacement.y, scale, -scale, padding );
	}

	MOAIDraw::Bind ();
	gfxDevice.SetVertexPreset ( MOAIVertexFormatMgr::XYZWC );
	gfxDevice.SetVertexTransform ( MOAIGfxDevice::VTX_WORLD_TRANSFORM, orgWorldTransform );
	gfxDevice.SetVertexMtxMode ( orgVtxModeInput, orgVtxModeOutput );
	// gfxDevice.SetBlendMode ( orgSrcBlend, orgDestBlend ); // TODO
	
	gfxDevice.Flush();

	// Clear context
	g_CurrentTextDrawContext->mFont = 0;
	g_CurrentTextDrawContext->mGlyphs.clear();
	g_CurrentTextDrawContext = 0;
}

namespace Gwen
{
	namespace Renderer
	{
		MOAIRenderer::MOAIRenderer() {
			// this->mScissorRect = new MOAIScissorRect();
		}

		MOAIRenderer::~MOAIRenderer() {			
			// delete this->mScissorRect;
		}

		void MOAIRenderer::Init() {
		}

		void MOAIRenderer::Begin() {			
		}

		void MOAIRenderer::End() {
		}
		
		void MOAIRenderer::DrawFilledRect( Gwen::Rect rect ) {
			Translate( rect );
			MOAIDraw::DrawRectFill( rect.x, -rect.y , rect.x + rect.w, -rect.y - rect.h );
		}

		void MOAIRenderer::DrawLineRect( Gwen::Rect rect ) {
			Translate( rect );
			MOAIDraw::DrawRectOutline( rect.x, - rect.y , rect.x + rect.w, -rect.y - rect.h );
		}

		void MOAIRenderer::SetDrawColor( Gwen::Color color ) {
			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();

			gfx.SetPenColor( 
					((float)color.r)/255.0f, 
					((float)color.g)/255.0f, 
					((float)color.b)/255.0f, 
					((float)color.a)/255.0f
				);
		}

		void MOAIRenderer::StartClip() {
			Gwen::Rect rect = ClipRegion();
			// Translate( rect );
			ZLRect rect1;
			rect1.Init( rect.x, -rect.y, rect.x + rect.w, -rect.y - rect.h  );

			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();
			ZLMatrix4x4 mtx;
			mtx = gfx.GetVertexTransform( MOAIGfxDevice::VTX_WORLD_TRANSFORM );
			mtx.Append( gfx.GetWorldToWndMtx() );
			mtx.Transform( rect1 );
			gfx.SetScissorRect( rect1 );
		};

		void MOAIRenderer::EndClip() {
			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();
			gfx.SetScissorRect();
		};

		void MOAIRenderer::DrawTexturedRect( Gwen::Texture* pTexture, Gwen::Rect rect, float u0, float v0, float u1, float v1 ) {
			float tw, th;
			float x0, y0, x1, y1;
			
			if( !pTexture->data )	return;
			MOAITextureBase* texture = static_cast< MOAITextureBase* >( pTexture->data );
			tw = texture->GetWidth();
			th = texture->GetHeight();

			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();
			gfx.SetTexture ( texture );
			gfx.SetShaderPreset ( MOAIShaderMgr::DECK2D_SHADER );
			MOAIQuadBrush::BindVertexFormat ( gfx );
			MOAIQuadBrush quad;

			Translate( rect );
			x0 = rect.x ;
			y0 = -rect.y ;
			x1 = rect.x + rect.w ;
			y1 = -rect.y - rect.h ;
		
			quad.SetVerts ( x0, y0, x1, y1 );
			quad.SetUVs ( u0, v0, u1, v1 );		
			quad.Draw ();

			gfx.Flush();

		}

		void MOAIRenderer::LoadTexture( Gwen::Texture* pTexture ) {
			//TODO
			MOAIGwenMgr::Get().LoadTexture( pTexture );
		}

		void MOAIRenderer::FreeTexture( Gwen::Texture* pTexture ) {
			//PASS
			MOAIGwenMgr::Get().ReleaseTexture( pTexture );
		}

		void MOAIRenderer::LoadFont( Gwen::Font* pFont ) {
		}

		void MOAIRenderer::FreeFont( Gwen::Font* pFont ) {
		}

		void MOAIRenderer::RenderText( Gwen::Font* pFont, Gwen::Point pos, const Gwen::UnicodeString& text ) {
			MOAIFont* font = MOAIGwenMgr::Get().FindFont( pFont );
			if( !font ) return;
			int x, y;
			x = pos.x;
			y = pos.y;
			Translate( x, y );

			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();
			BeginDrawString( 1, *font, pFont->size, 0.0f, 0.0f );
			cc8* cstring =  Gwen::Utility::UnicodeToString( text ).c_str();
			DrawString( cstring, x, y, 0, 0 );
			EndDrawString();
			// Gwen::Renderer::Base::RenderText( pFont, pos, text );
		}

		Gwen::Point MOAIRenderer::MeasureText( Gwen::Font* pFont, const Gwen::UnicodeString& text ) {
			Gwen::Point p;
			p.x = pFont->size * Scale() * ( float ) text.length() * 2;
			p.y = pFont->size * Scale() + 4;
			return p;
		}

		Gwen::Color MOAIRenderer::PixelColour( Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color & col_default ) {
			//TODO
			return col_default;
		}

		bool MOAIRenderer::InitializeContext( Gwen::WindowProvider* pWindow ) {
			//PASS
			return true;
		}

		bool MOAIRenderer::ShutdownContext( Gwen::WindowProvider* pWindow ) {
			//PASS
			return true;
		}

		bool MOAIRenderer::PresentContext( Gwen::WindowProvider* pWindow ) {
			//PASS
			return true;
		}

		bool MOAIRenderer::ResizedContext( Gwen::WindowProvider* pWindow, int w, int h ) {
			//PASS
			return true;
		}

		bool MOAIRenderer::BeginContext( Gwen::WindowProvider* pWindow ) {
			//PASS
			return true;
		}

		bool MOAIRenderer::EndContext( Gwen::WindowProvider* pWindow ) {
			//PASS
			return true;
		}

	}
}