#include "../header.hpp"

Sphere::Sphere () : Primitive () {
	_origin = Vector3 ();
	_radius = 1.0;
}

Sphere::Sphere (Vector3 origin, float radius, Color color, bool isLight) : Primitive (color, isLight) {
	_origin = origin;

	if (radius > 0.0) {
		_radius = radius;
	} else {
		_radius = 1.0;
	}
}

Sphere::Sphere (const Sphere& other) : Primitive (other) {
	_origin = other._origin;
	_radius = other._radius;
}

Sphere::~Sphere () {

}

Vector3 Sphere::getOrigin () {
	return _origin;
}

float Sphere::getRadius () {
	return _radius;
}

void Sphere::setOrigin (Vector3 origin) {
	_origin = origin;
}

void Sphere::setRadius (float radius) {
	if (radius > 0.0) {
		_radius = radius;
	} else {
		_radius = 1.0;
	}
}

Vector3 Sphere::getNormalAt (Vector3 position) {
	Vector3 normal;
	normal = position - _origin;
	normal.normalize ();
	
	return normal;
}

float Sphere::findIntersectionWith (Ray3D ray, float maxDistance) {
	//Ray - Sphere intersection test
	//taken from Graphics Gems
	//For a diagram (and naming convention)
	//see the above book (I will also try to
	//post a similar diagram on my website).
	
	float distanceToIntersection;	//this is the value we return

	Vector3 EO = _origin - ray.getOrigin ();
	float v = EO.dotProduct (ray.getDirection ());

	float disc = _radius * _radius - ((EO.dotProduct (EO)) - v * v);

	//the test below is done because squaring two floating point numbers
	//should! be faster than finding a square root of one float!
	if ((disc > 0.000001) && (disc * disc < maxDistance * maxDistance)) {	//we have an intersection!
		disc = sqrt (disc);
		
		distanceToIntersection = v - disc;
	}
	else {
		distanceToIntersection = -1.0;
	}

	return distanceToIntersection;

}

