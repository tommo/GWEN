/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#ifndef MOAIGWENRENDERER_H
#define MOAIGWENRENDERER_H

#include "Gwen/Gwen.h"
#include "Gwen/BaseRender.h"

// #include "moai-sim/MOAIScissorRect.h"

namespace Gwen
{
	namespace Renderer
	{

		class MOAIRenderer : public Gwen::Renderer::Base
		{
			private:
				// MOAIScissorRect* mScissorRect;
				
			public:

				MOAIRenderer();
				~MOAIRenderer();

				void Init();

				void Begin();
				void End();

				void SetDrawColor  ( Gwen::Color color );
				void DrawFilledRect( Gwen::Rect rect );
				void DrawLineRect  ( Gwen::Rect rect );
				
				void StartClip();
				void EndClip  ();

				void DrawTexturedRect( Gwen::Texture* pTexture, Gwen::Rect pTargetRect, float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f );
				void LoadTexture( Gwen::Texture* pTexture );
				void FreeTexture( Gwen::Texture* pTexture );
				Gwen::Color PixelColour( Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color & col_default );

				void RenderText    ( Gwen::Font* pFont, Gwen::Point pos, const Gwen::UnicodeString& text );
				Gwen::Point MeasureText   ( Gwen::Font* pFont, const Gwen::UnicodeString& text );
				void LoadFont( Gwen::Font* pFont );
				void FreeFont( Gwen::Font* pFont );
				
			public:

				//
				// Self Initialization
				//

				virtual bool InitializeContext( Gwen::WindowProvider* pWindow );
				virtual bool ShutdownContext( Gwen::WindowProvider* pWindow );
				virtual bool PresentContext( Gwen::WindowProvider* pWindow );
				virtual bool ResizedContext( Gwen::WindowProvider* pWindow, int w, int h );
				virtual bool BeginContext( Gwen::WindowProvider* pWindow );
				virtual bool EndContext( Gwen::WindowProvider* pWindow );

				void*	m_pContext;
		};

	}
}

#endif
