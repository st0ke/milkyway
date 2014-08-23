//
// gl-video-context.cpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//


//#define GL3_PROTOTYPES 1
//#define GL_GLEXT_PROTOTYPES 1
//#include <GL/glcorearb.h>
//#include <GL/gl.h>
//#include <GL/glext.h>
#include <GL/glew.h>

#include "gl-video-context.hpp"



GLVideoContext::GLVideoContext() 
	: window(nullptr) {
}

GLVideoContext::~GLVideoContext() {
	destroy();
}

bool GLVideoContext::init(int width, int height, bool fullscreen) {
	if (window != nullptr) {
		return false;
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	int flags;

	flags = SDL_WINDOW_OPENGL;
	flags |= SDL_WINDOW_SHOWN;
	if (fullscreen) {
		flags |= SDL_WINDOW_FULLSCREEN;
	}


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	window = SDL_CreateWindow("TODO FIXME", 
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height, flags);

	if (!window) {
		return false;
	}

	glContext = SDL_GL_CreateContext(window);
//	const char *err = SDL_GetError();
//	if (err)
//	xV	printf("%s\n", err);


	if (glewInit() != GLEW_OK) {
		return false;
	}


//	glShadeModel(GL_SMOOTH);
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	return true;
}
void GLVideoContext::destroy() {
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void GLVideoContext::startFrame() {
}
void GLVideoContext::endFrame() {
	SDL_GL_SwapWindow(window);
}

void GLVideoContext::setClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}
void GLVideoContext::setClearDepth(float v) {
	glClearDepth(v);
}
void GLVideoContext::setClearStencil(float v) {
	glClearStencil(v);
}

void GLVideoContext::clear(bool colorBuffer, bool depthBuffer, bool stencilBuffer) {
	GLbitfield mask = 0;

	if (colorBuffer) {
		mask |= GL_COLOR_BUFFER_BIT;
	}
	if (depthBuffer) {
		mask |= GL_DEPTH_BUFFER_BIT;
	}
	if (stencilBuffer) {
		mask |= GL_STENCIL_BUFFER_BIT;
	}
	glClear(mask);
}

Texture *GLVideoContext::regTexture(const TextureData &txtData) {
	// TODO
	return nullptr;
}
Shader *GLVideoContext::regShader(const ShaderData &shaderData) {
	// TODO
	return nullptr;
}
VertexBuffer *GLVideoContext::regVertexBuffer(const VertexBufferData &vbData) {
	// TODO
	return nullptr;
}

void GLVideoContext::render(const RenderUnit &runit) {
	// TODO
}

