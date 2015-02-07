#include "moai-gwen/MOAIGwenRenderer.h"

#include "Gwen/Utility.h"
#include "Gwen/Font.h"
#include "Gwen/Texture.h"
#include "Gwen/WindowProvider.h"

#include <math.h>

#include "moai-sim/pch.h"
#include "moai-sim/MOAIDraw.h"
#include "moai-sim/MOAIGfxDevice.h"



namespace Gwen
{
	namespace Renderer
	{
		MOAIRenderer::MOAIRenderer()
		{
			// this->mScissorRect = new MOAIScissorRect();
		}

		MOAIRenderer::~MOAIRenderer()
		{			
			// delete this->mScissorRect;
		}

		void MOAIRenderer::Init()
		{
		}

		void MOAIRenderer::Begin()
		{			
		}

		void MOAIRenderer::End()
		{
		}
		
		void MOAIRenderer::DrawFilledRect( Gwen::Rect rect )
		{
			// MOAIDraw& draw = MOAIDraw::Get ();
			Translate( rect );
			MOAIDraw::DrawRectFill( rect.x, -rect.y , rect.x + rect.w, -rect.y - rect.h );
			// MOAIDraw::DrawRectFill( rect.x, rect.y + rect.h, rect.x + rect.w, rect.y, true );
		}

		void MOAIRenderer::DrawLineRect( Gwen::Rect rect )
		{
			Translate( rect );
			MOAIDraw::DrawRectOutline( rect.x, - rect.y , rect.x + rect.w, -rect.y - rect.h );
		}

		void MOAIRenderer::SetDrawColor( Gwen::Color color )
		{
			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();

			gfx.SetPenColor( 
					((float)color.r)/255.0f, 
					((float)color.g)/255.0f, 
					((float)color.b)/255.0f, 
					((float)color.a)/255.0f
				);
		}

		void MOAIRenderer::StartClip()
		{
			Gwen::Rect rect = ClipRegion();
			ZLRect rect1;
			rect1.Init( rect.x, - rect.y, rect.x+rect.w, - rect.y-rect.h );

			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();
			ZLMatrix4x4 mtx = gfx.GetVertexTransform( MOAIGfxDevice::VTX_WORLD_TRANSFORM );
			mtx.Append( gfx.GetWorldToWndMtx() );
			
			mtx.Transform( rect1 );
			// printf("%f, %f, %f, %f \n", rect1.mXMin, rect1.mYMin, rect1.mXMax, rect1.mYMax );
			gfx.SetScissorRect( rect1 );
		};

		void MOAIRenderer::EndClip()
		{
			MOAIGfxDevice& gfx = MOAIGfxDevice::Get ();
			gfx.SetScissorRect();
		};

		void MOAIRenderer::DrawTexturedRect( Gwen::Texture* pTexture, Gwen::Rect rect, float u1, float v1, float u2, float v2 )
		{
		}

		void MOAIRenderer::LoadTexture( Gwen::Texture* pTexture )
		{
			//TODO
		}

		void MOAIRenderer::FreeTexture( Gwen::Texture* pTexture )
		{
			//PASS
		}

		Gwen::Color MOAIRenderer::PixelColour( Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color & col_default )
		{
			//TODO
			return col_default;
		}

		bool MOAIRenderer::InitializeContext( Gwen::WindowProvider* pWindow )
		{
			//PASS
			return true;
		}

		bool MOAIRenderer::ShutdownContext( Gwen::WindowProvider* pWindow )
		{
			//PASS
			return true;
		}

		bool MOAIRenderer::PresentContext( Gwen::WindowProvider* pWindow )
		{
			//PASS
			return true;
		}

		bool MOAIRenderer::ResizedContext( Gwen::WindowProvider* pWindow, int w, int h )
		{
			//PASS
			return true;
		}

		bool MOAIRenderer::BeginContext( Gwen::WindowProvider* pWindow )
		{
			//PASS
			return true;
		}

		bool MOAIRenderer::EndContext( Gwen::WindowProvider* pWindow )
		{
			//PASS
			return true;
		}

	}
}