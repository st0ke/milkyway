//
// file.hpp - TODO
//
// Copyright (C) 2013 Alexander Boldyrev
//


#pragma once

#include <string>
#include <memory>
#include <cstdint>


class File {
	public:
		File(std::wstring _filename)
			: filename(_filename) {}

		virtual ~File() {}

		std::wstring getFilename() const { return filename; }
		std::wstring getFileExtension() const {
			size_t extPos = filename.find_last_of(L'.');

			if (extPos == std::wstring::npos)
				return L"";
			return filename.substr(extPos, std::wstring::npos);
		}

		enum SeekTypes {
			SEEK_FORWARD,
			SEEK_BACKWARD,
			SEEK_START
		};

		virtual bool read(void *buf, size_t size) = 0;
		virtual size_t seek(size_t size, SeekTypes type) = 0;
		virtual bool isEOF() const = 0;
		virtual bool isOk() const = 0;

	private:
		std::wstring filename;
};

/*
class File {
	public:
		File(std::wstring _filename, size_t _size, unsigned char *_data) 
			: filename(_filename), size(_size), data(_data) {
		}
		~File() {
			if (data) {
				delete [] data;
				data = nullptr;
			}
		}


		std::wstring getFilename() const { return filename; }
		size_t getSize() const { return size; }
		unsigned char *getData() const { return data; }

	private:
		std::wstring filename;
		size_t size;
		unsigned char *data;

};
*/

/*
class FileReader {
	public:
		FileReader(std::shared_ptr<File> _file) 
			: file(_file), offset(0) {
		}

		size_t getOffset() const { return offset; }

		bool isEOF() const { return offset >= file->getSize(); }

		enum SeekTypes {
			SEEK_FORWARD,
			SEEK_BACKWARD,
			SEEK_START
		};

		size_t seek(size_t _offset, SeekTypes seekType) {
			size_t newOffset;
			size_t retval;

			switch(seekType) {
				case SEEK_FORWARD:
					newOffset = offset + _offset;
					if (newOffset > file->getSize())
						newOffset = file->getSize();
					retval = newOffset - offset;
					break;
				case SEEK_BACKWARD:
					if (offset < _offset) {
						newOffset = 0;
					} else {
						newOffset = offset - _offset;
					}
					retval = offset - newOffset;
					break;
				case SEEK_START:
					newOffset = _offset;
					if (newOffset > file->getSize())
						newOffset = file->getSize();
					retval = newOffset;
					break;
			}

			offset = newOffset;
			return retval;
		}


		int8_t readInt8() {
			if (isEOF()) {
				return 0; 
			}

			int8_t retval = *(reinterpret_cast <int8_t *> (&(file->getData()[offset])));
			++offset;
			return retval;
		}
		uint8_t readUint8() {
			if (isEOF()) {
				return 0; 
			}

			uint8_t retval = *(reinterpret_cast <uint8_t *> (&(file->getData()[offset])));
			++offset;
			return retval;
		}
		int16_t readInt16() {
			if (isEOF()) {
				return 0; 
			}

			int16_t retval = *(reinterpret_cast <int16_t *> (&(file->getData()[offset])));
			offset += 2;
			return retval;
		}
		uint16_t readUInt16() {
			if (isEOF()) {
				return 0; 
			}

			uint16_t retval = *(reinterpret_cast <uint16_t *> (&(file->getData()[offset])));
			offset += 2;
			return retval;
		}
		int32_t readInt32() {
			if (isEOF()) {
				return 0; 
			}

			int32_t retval = *(reinterpret_cast <int32_t *> (&(file->getData()[offset])));
			offset += 4;
			return retval;
		}
		uint32_t readUInt32() {
			if (isEOF()) {
				return 0; 
			}

			uint32_t retval = *(reinterpret_cast <uint32_t *> (&(file->getData()[offset])));
			offset += 4;
			return retval;
		}
		int64_t readInt64() {
			if (isEOF()) {
				return 0; 
			}

			int64_t retval = *(reinterpret_cast <int64_t *> (&(file->getData()[offset])));
			offset += 8;
			return retval;
		}
		uint64_t readUInt64() {
			if (isEOF()) {
				return 0; 
			}

			uint64_t retval = *(reinterpret_cast <uint64_t *> (&(file->getData()[offset])));
			offset += 8;
			return retval;
		}


	private:
		std::shared_ptr<File> file;
		size_t offset;

};

*/

