//
// entry.cpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//

/*
#include "video/gl-video-context.hpp"
*/

#include <iostream>

#include "res/value-parser.hpp"
#include "res/native-fs.hpp"

int main(int argc, char **argv) {

	/*
	NativeFileSystem fs;

	auto file = fs.loadFile(L"test-file.prt.df.qwww.");
	std::wcout << file->getFileExtension() << std::endl;
	*/
	/*
	std::cout << file->isOk() <<std::endl;
	std::cout << std::endl;

	uint8_t buf[4];
	file->read(buf, 4);
	std::cout << buf[0] << std::endl;
	std::cout << buf[1] << std::endl;
	std::cout << buf[2] << std::endl;
	std::cout << buf[3] << std::endl;

	uint32_t value = parseAsBigEndian<uint32_t>(buf);
	std::cout << value << std::endl;
	*/

	/*
	uint16_t t = 255;
	uint8_t *buf = (uint8_t *)&t;

	uint16_t retLE = parseAsLittleEndian<uint16_t>(buf);
	uint16_t retBE = parseAsBigEndian<uint16_t>(buf);
	
	std::cout << sizeof(t) << std::endl;
	std::cout << "LE: " << retLE;
	std::cout << std::endl;
	std::cout << "BE: " << retBE;
	std::cout << std::endl;
*/
	/*
	VideoContext *context = new GLVideoContext;

	if (!context->init(800, 600, false)) {
		return 666;
	}

	context->startFrame();
	context->clear(true, false, false);
	context->endFrame();

	SDL_Delay(2000);

	context->destroy();
	delete context;
	*/

	return 0;
}

