//
// gl-video-context.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once

#include "video-context.hpp"

#include <SDL2/SDL.h>

class GLVideoContext: public VideoContext {
	public:
		GLVideoContext();
		~GLVideoContext();

		bool init(int width, int height, bool fullscreen);
		void destroy();


		Texture *regTexture(const TextureData &txtData);
		Shader *regShader(const ShaderData &shaderData);
		VertexBuffer *regVertexBuffer(const VertexBufferData &vbData);


		void startFrame();
		void endFrame();

		void setClearColor(float r, float g, float b, float a);
		void setClearDepth(float v);
		void setClearStencil(float v);
		void clear(bool colorBuffer, bool depthBuffer, bool stencilBuffer);
		

		
		void render(const RenderUnit &runit);


	private:
		SDL_Window *window;
		SDL_GLContext glContext;



	private:
		class GLTexture: public Texture {
		};

		class GLShader: public Shader {
		};

		class GLVertexBuffer: public VertexBuffer {
		};


//		void bindShader(const Shader &shader);
//		void unbindShader();

//		void bindTexture(const Texture &txt, int layerNum);
//		void unbindTexture(int layerNum);


};

