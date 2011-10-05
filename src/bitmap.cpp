/* Author: Damien Schoof
 * Date created: June 2008
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <fstream>
#include <string.h>
#include "bitmap.hpp"

Bitmap::Bitmap ():
    _width(640), _height(480),
    _pixelData (NULL) {
    _pixelData = new Color [_width * _height];
}

Bitmap::Bitmap (int width, int height):
    _width (width), _height (height),
    _pixelData (NULL) {
    //validate the width
    if (width <= 0) {
        _width = 640;	//default to 640 wide
    }
    //validate the height
    if (height <= 0) {
        _height = 480;	//default to 480 high
    }
    
    _pixelData = new Color [_width * _height];
}

Bitmap::Bitmap (const Bitmap& other):
    _width (other._width),
    _height (other._height),
    _pixelData (NULL) {
    _pixelData = new Color [_width * _height];
    for (int y=0; y<_height; y++) {
        for (int x=0; x<_width; x++) {
            _pixelData[y*_width + x] = other._pixelData[y*_width + x];
        }
    }
}

Bitmap& Bitmap::operator = (Bitmap other) {
    if (_pixelData) delete[] _pixelData;

    _width = other._width;
    _height = other._height;
    _pixelData = new Color [_width * _height];
    for (int y=0; y<_height; y++) {
        for (int x=0; x<_width; x++) {
            _pixelData[y*_width + x] = other._pixelData[y*_width + x];
        }
    }

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

    _pixelData[y*_width + x] = color;

    return E_SUCCESS;
}

Color Bitmap::getPixel (int x, int y) {
    return _pixelData[y*_width + x];
}

ErrorCode Bitmap::saveAsTGA (std::string fileName) {
    char tgaHeader [12] = {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char header [6];
    std::ofstream file;

    header [0] = static_cast<char> (_width  % 256);
    header [1] = static_cast<char> (_width  / 256);
    header [2] = static_cast<char> (_height % 256);
    header [3] = static_cast<char> (_height / 256);
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
    for (int y=0; y<_height; y++) {
        for (int x=0; x<_width; x++) {
            unsigned char r, g, b;
            r = static_cast<char> (_pixelData[y*_width + x].getR () * 256);
            g = static_cast<char> (_pixelData[y*_width + x].getG () * 256);
            b = static_cast<char> (_pixelData[y*_width + x].getB () * 256);
            file <<  b << g << r;
        }
    }

    if (file.fail ()) {
        file.close();
        return E_FAILURE;
    }

    file.close();
    return E_SUCCESS;
}
