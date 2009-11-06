#include "../header.hpp"

Bitmap::Bitmap () {
	_width = 640;
	_height = 480;

	_pixelData = new char [_width * _height * 3];

	for (int i = 0; i < _width * _height * 3; i++) {
		_pixelData [i] = 0;
	}
}

Bitmap::Bitmap (int width, int height) {
	//validate the width
	if (width > 0) {
		_width = width;
	} else {
		_width = 640;	//default to 640 wide
	}
	//validate the height
	if (height > 0) {
		_height = height;
	} else {
		_height = 480;	//default to 480 high
	}
	  
}

Bitmap::Bitmap (const Bitmap& other) {
	_width = other._width;
	_height = other._height;

}

Bitmap::~Bitmap () {
	if (_pixelData) {
		delete[] _pixelData;
	}
}

int Bitmap::getWidth () {
	return _width;
}

int Bitmap::getHeight () {
	return _height;
}

void Bitmap::setWidth (int width) {
	if (width > 0) {
		_width = width;
	} else {
		_width = 640;
	}

}

void Bitmap::setHeight (int height) {
	if (height > 0) {
		_height = height;
	} else {
		_height = 480;
	}

}

ErrorCode Bitmap::putPixel (int x, int y, Color& color) {
	if ((x > _width) or (y > _height)) {
		return E_OUT_OF_RANGE;
	}

	_pixelData [y * _width * 3 + x * 3 + 0] = (char) (color.getB () * 255);
	_pixelData [y * _width * 3 + x * 3 + 1] = (char) (color.getG () * 255);
	_pixelData [y * _width * 3 + x * 3 + 2] = (char) (color.getR () * 255);

	return E_SUCCESS;
}

ErrorCode Bitmap::putPixel (int x, int y, unsigned char r, unsigned char g, unsigned char b) {
	if ((x > _width) or (y > _height)) {
		return E_OUT_OF_RANGE;
	}

	_pixelData [y * _width * 3 + x * 3 + 0] = b;
	_pixelData [y * _width * 3 + x * 3 + 1] = g;
	_pixelData [y * _width * 3 + x * 3 + 2] = r;

	return E_FAILURE;
}

ErrorCode Bitmap::saveAsTGA (char* fileName) {
	char tgaHeader [12] = {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char header [6];
	ofstream file;

	header [0] = _width  % 256;
	header [1] = _width  / 256;
	header [2] = _height % 256;
	header [3] = _height / 256;
	header [4] = 24;	//bpp
	header [5] = 0;

	file.open (fileName, ios::out | ios::binary);
	if (file.fail ()) {
		return E_FAILURE;
	}

	//write the first header to disk
	file.write (tgaHeader, sizeof (tgaHeader));
	if (file.fail ()) {
		return E_FAILURE;
	}

	//write the second header to disk
	file.write (header, sizeof (header));
	if (file.fail ()) {
		return E_FAILURE;
	}

	//now write the pixel data to disk
	file.write (_pixelData, _width * _height * 3);
	if (file.fail ()) {
		return E_FAILURE;
	}

	return E_SUCCESS;
}
