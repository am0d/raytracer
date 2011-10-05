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

#include "primitive.hpp"

Primitive::Primitive ():
    _color (Color ()), _isLight (false) {
        
}

Primitive::Primitive (Color color, bool isLight):
    _color(color), _isLight (isLight) {

}

Primitive::Primitive (const Primitive& other):
    _color (other._color),
    _isLight (other._isLight) {

}

Primitive::~Primitive () {

}

Color Primitive::getColorAt (Vector3 position) {
    return _color;
}

bool Primitive::getIsLight () {
    return _isLight;
}

void Primitive::setIsLight (bool isLight) {
    _isLight = isLight;
}

void Primitive::setColor (Color color) {
    _color = color;
}

Color Primitive::getColor () {
    return _color;
}
