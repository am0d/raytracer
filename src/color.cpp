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

#include "color.hpp"

Color::Color ():
    _r (0.0),
    _g (0.0), 
    _b (0.0) {

}

Color::Color (float r, float g, float b) :
    _r (r), _g (g), _b (b) {
    //confine 0.0 <= _r <= 1.0
    if (r >= 0.0) {
        if (r <= 1.0) {
            _r = r;
        } else {
            _r = 1.0;
        }
    } else {
        _r = 0.0;
    }

    //confine 0.0 <= _g <= 1.0
    if (_g >= 0.0) {
        if (g <= 1.0) {
            _g = g;
        } else {
            _g = 1.0;
        }
    } else {
        _g = 0.0;
    }

    //confine 0.0 <= _b <= 1.0
    if (_b >= 0.0) {
        if (b <= 1.0) {
            _b = b;
        } else {
            _b = 1.0;
        }
    } else {
        _b = 0.0;
    }
}

Color::Color (const Color& other) :
    _r (other._r),
    _g (other._g),
    _b (other._b) {

}

Color::~Color () {

}

float Color::getR () {
    return _r;
}

float Color::getG () {
    return _g;
}

float Color::getB () {
    return _b;
}

void Color::setR (float r) {
    if (r <= 0.0) {
        _r = 0.0;
    }
    else if (r >= 1.0) {
        _r = 1.0;
    }
    else {
        _r = r;
    }
}

void Color::setG (float g) {
    if (g <= 0.0) {
        _g = 0.0;
    }
    else if (g >= 1.0) {
        _g = 1.0;
    }
    else {
        _g = g;
    }
}

void Color::setB (float b) {
    if (b <= 0.0) {
        _b = 0.0;
    }
    else if (b >= 1.0) {
        _b = 1.0;
    }
    else {
        _b = b;
    }
}

Color Color::operator + (const Color& other) {
    Color newColor (_r + other._r,
            _g + other._g,
            _b + other._b);

    return newColor;
}

Color Color::operator * (float factor) {
    Color newColor (_r * factor,
            _g * factor,
            _b * factor);

    return newColor;
}

Color Color::operator * (Color other) {
    Color newColor (_r * other._r,
            _g * other._g,
            _b * other._b);

    return newColor;
}

Color& Color::operator = (const Color& other) {
    _r = other._r;
    _g = other._g;
    _b = other._b;

    return *this;
}
