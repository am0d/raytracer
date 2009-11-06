#include "../header.hpp"

Primitive::Primitive () {
	_color = Color ();
	_isLight = false;
}

Primitive::Primitive (Color color, bool isLight) {
	_color = color;
	_isLight = isLight;
}

Primitive::Primitive (const Primitive& other) {
	_color = other._color;
	_isLight = other._isLight;
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
