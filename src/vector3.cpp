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

#include <math.h>
#include "vector3.hpp"

Vector3::Vector3 ():
    _x (0.0), _y (0.0), _z (0.0) {

}

Vector3::Vector3 (float x, float y, float z):
    _x (x), _y (y), _z (z) {

}

Vector3::Vector3 (const Vector3& other):
    _x (other._x),
    _y (other._y),
    _z (other._z) {

}

Vector3::~Vector3 () {

}

float Vector3::getX () {
    return _x;
}

float Vector3::getY () {
    return _y;
}

float Vector3::getZ () {
    return _z;
}

void Vector3::setX (float x) {
    _x = x;
}

void Vector3::setY (float y) {
    _y = y;
}

void Vector3::setZ (float z) {
    _z = z;
}

float Vector3::dotProduct (const Vector3& other) {
    return (_x * other._x + _y * other._y + _z * other._z);
}

void Vector3::normalize () {
    float magnitude = static_cast<float> (sqrt (dotProduct (*this)));

    _x /= magnitude;
    _y /= magnitude;
    _z /= magnitude;
}

Vector3 Vector3::operator + (const Vector3& other) {
    return Vector3 (_x + other._x, _y + other._y, _z + other._z);
}

Vector3 Vector3::operator - (const Vector3& other) {
    return Vector3 (_x - other._x, _y - other._y, _z - other._z);
}

Vector3 Vector3::operator * (float factor) {
    return Vector3 (_x * factor, _y * factor, _z * factor);
}

Vector3& Vector3::operator = (const Vector3 other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;

    return *this;
}
