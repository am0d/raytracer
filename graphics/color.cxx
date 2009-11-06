#include "../header.hpp"

Color::Color () {
	_r = 0.0;
	_g = 0.0;
	_b = 0.0;
}

Color::Color (float r, float g, float b) {
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

Color::Color (const Color& other) {
	_r = other._r;
	_g = other._g;
	_b = other._b;
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
	if (r >= 0.0) {
		_r = r;
	} else {
		_r = 0.0;
	}
}

void Color::setG (float g) {
	if (g >= 0.0) {
		_g = g;
	} else {
		_g = 0.0;
	}
}

void Color::setB (float b) {
	if (b >= 0.0) {
		_b = b;
	} else {
		_b = 0.0;
	}
}

Color Color::operator + (const Color& other) {
	_r += other._r;
	_g += other._g;
	_b += other._b;

	if (_r > 1.0) {
		_r = 1.0;
	}

	if (_g > 1.0) {
		_g = 1.0;
	}

	if (_b > 1.0) {
		_b = 1.0;
	}

	return *this;
}

Color Color::operator * (float factor) {
	_r *= factor;
	_g *= factor;
	_b *= factor;

	if (_r > 1.0) {
		_r = 1.0;
	}

	if (_g > 1.0) {
		_g = 1.0;
	}

	if (_b > 1.0) {
		_b = 1.0;
	}
}

Color Color::operator = (const Color& other) {
	_r = other._r;
	_g = other._g;
	_b = other._b;

	return *this;
}
