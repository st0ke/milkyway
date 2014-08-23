//
// video-context.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once


#include <deque>
#include <memory>


#include "../res-objs/texture-data.hpp"

#include "vertex-buffer.hpp"

#include "texture.hpp"
#include "shader.hpp"


class Texture;
class Shader;


class IVideoContext {
	public:
		virtual ~VideoContext() {}

		virtual bool init(int width, int height, bool fullscreen) = 0;
		virtual void destroy() = 0;


		virtual Texture *regTexture(const TextureData &txtData) = 0;
		virtual Shader *regShader(const ShaderData &shaderData) = 0;
		virtual VertexBuffer *regVertexBuffer(const VertexBufferData &vbData) = 0;


		virtual void startFrame() = 0;
		virtual void endFrame() = 0;

//		virtual void setWorldViewMatrix(const Matrix4 &mat) = 0;
//		virtual void setProjectionMatrix(const Matrix4 &mat) = 0;


		virtual void setClearColor(float r, float g, float b, float a) = 0;
		virtual void setClearDepth(float v) = 0;
		virtual void setClearStencil(float v) = 0;
		virtual void clear(bool colorBuffer, bool depthBuffer, bool stencilBuffer) = 0;
		
//		virtual void bindShader(const Shader &shader) = 0;
//		virtual void unbindShader() = 0;

//		virtual void bindTexture(const Texture &txt, int layerNum) = 0;
//		virtual void unbindTexture(int layerNum) = 0;


		struct RenderUnit {
			std::deque<std::shared_ptr<Shader>> shaders;
			std::deque<std::shared_ptr<Texture>> textures;
			std::shared_ptr<VertexBuffer> vb;
		};

		virtual void render(const RenderUnit &runit) = 0;

};

