//
// texture.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

#include "../res/resource-object.hpp"


class TextureData : public ResourceObject {
	public:
};


//class TextureData: public ResourceObject {
//	public:
//		enum TextureTypes {
//		};
//
//	public:
//		TextureData(std::wstring filename, 
//				int _width, int _height, int _bpp, TextureTypes _type,
//				void *_data)
//			: ResourceObject(filename),
//			width(_width),
//			height(_height),
//			bpp(_bpp),
//			type(_type),
//			data(_data)
//		{
//		}
//		~TextureData() {
//			if (data) {
//				free(data);
//			}
//		}
//
//		int getWidth() const { return width; }
//		int getHeight() const { return height; }
//		int getBPP() const { return bpp; }
//		TextureTypes getType() const { return type; }
//		void *getData() const { return data; }
//
//	private:
//		int width;
//		int height;
//		int bpp;
//		TextureTypes type;
//		void *data;
//
//};

