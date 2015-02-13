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
			ZLRect rect1;
			rect1.Init( rect.x, - rect.y, rect.x+rect.w, - rect.y-rect.h );

			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();
			ZLMatrix4x4 mtx = gfx.GetVertexTransform( MOAIGfxDevice::VTX_WORLD_TRANSFORM );
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
			MOAIGwenMgr::Get().LoadFont( pFont );
		}

		void MOAIRenderer::FreeFont( Gwen::Font* pFont ) {
			MOAIGwenMgr::Get().ReleaseFont( pFont );
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