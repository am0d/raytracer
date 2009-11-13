#include <fstream>
#include <string.h>
#include "bitmap.hpp"

Bitmap::Bitmap ():
    _width(640), _height(480) {
    _pixelData = new unsigned char [_width * _height * 3];

    memset (_pixelData, 0, _width*_height*3);
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
    
    _pixelData = new unsigned char [_width * _height * 3];
    memset (_pixelData, 0, _width*_height*3);
}

Bitmap::Bitmap (const Bitmap& other) {
    _width = other._width;
    _height = other._height;
    _pixelData = new unsigned char [_width * _height * 3];
    memcpy (_pixelData, other._pixelData, _width*_height*3);
}

Bitmap& Bitmap::operator = (Bitmap other) {
    if (_pixelData) delete _pixelData;

    _width = other._width;
    _height = other._height;
    _pixelData = new unsigned char [_width * _height * 3];
    memcpy (_pixelData, other._pixelData, _width*_height*3);

    return *this;
}

Bitmap::~Bitmap () {
    if (_pixelData) {
        delete[] _pixelData;
    }
    _pixelData = NULL;
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
    if ((x >= _width) || (x < 0)
            || (y >= _height) || (y < 0)) {
        return E_OUT_OF_RANGE;
    }

    _pixelData [y*_width*3 + x*3 + 0] = (char) (color.getB () * 255);
    _pixelData [y*_width*3 + x*3 + 1] = (char) (color.getG () * 255);
    _pixelData [y*_width*3 + x*3 + 2] = (char) (color.getR () * 255);

    return E_SUCCESS;
}

Color Bitmap::getPixel (int x, int y) {
    Color color (
            (_pixelData [y*_width*3 + x*3 + 2]) / 255.0,
            (_pixelData [y*_width*3 + x*3 + 1]) / 255.0,
            (_pixelData [y*_width*3 + x*3 + 0]) / 255.0
            );

    return color;
}

ErrorCode Bitmap::saveAsTGA (std::string fileName) {
    char tgaHeader [12] = {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char header [6];
    std::ofstream file;

    header [0] = _width  % 256;
    header [1] = _width  / 256;
    header [2] = _height % 256;
    header [3] = _height / 256;
    header [4] = 24;	//bpp
    header [5] = 0;

    file.open (fileName.c_str(), std::ios::out | std::ios::binary);
    if (file.fail ()) {
        return E_FAILURE;
    }

    //write the first header to disk
    file.write (tgaHeader, sizeof (tgaHeader));
    if (file.fail ()) {
        file.close();
        return E_FAILURE;
    }

    //write the second header to disk
    file.write (header, sizeof (header));
    if (file.fail ()) {
        file.close();
        return E_FAILURE;
    }

    //now write the pixel data to disk
    file.write ((char *) _pixelData, _width * _height * 3);
    if (file.fail ()) {
        file.close();
        return E_FAILURE;
    }

    file.close();
    return E_SUCCESS;
}
