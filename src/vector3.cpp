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
