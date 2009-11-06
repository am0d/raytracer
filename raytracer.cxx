#include "header.hpp"

RayTracer::RayTracer () {
	_left = -4;
	_right = 4;
	_top = 3;
	_bottom = -3;

	_bitmap = new Bitmap ();

	_scene = new Scene (5, _left, _right, _bottom, _top, -5, 20, 3);
}

RayTracer::~RayTracer () {
	if (_scene) {
		delete _scene;
	}

	if (_bitmap) {
		delete _bitmap;
	}
}

Bitmap* RayTracer::getBitmap () {
	return _bitmap;
}

bool RayTracer::done () {
	return _done;
}

void RayTracer::initScene () {
	_deltaX = (float) (_right - _left) / (float) _bitmap->getWidth ();
	_deltaY = (float) (_bottom - _top) / (float) _bitmap->getHeight ();

	_sigmaX = _left;
	_sigmaY = _top;

	_curScanLine = 0;

	_done = false;
}

bool RayTracer::render () {
	Ray3D ray;

	ray.setOrigin (Vector3 (0, 0, 5));

	for (; _curScanLine < _bitmap->getHeight (); _curScanLine++) {
		for (_x = 0; _x < _bitmap->getWidth (); _x++) {
			ray.setDirection (Vector3 (_sigmaX, _sigmaY, 0) - ray.getOrigin ());	//no need to normalize - Ray3D does this automatically for us!

			Color pixelColor = traceRay (ray, 999999999.0);
			
			if (_bitmap->putPixel (_x, _curScanLine, pixelColor) != E_SUCCESS) {
				cerr << "An error occurred while trying to put the pixel at " << _x << ", " << _curScanLine << std::endl;
				return (_done = false);
			}

			_sigmaX += _deltaX;
		}

		_sigmaX = _left;
		_sigmaY += _deltaY;
	}

	_done = true;

	return _done;
}

Color RayTracer::traceRay (Ray3D ray, float distance) {
	Primitive* closestPrim = NULL;
	float newDistance;
	Color color (0.0, 0.0, 0.0);

	for (int i = 0; i < _scene->getNumberOfPrimitives (); i++) {
		newDistance = _scene->getPrimitive (i)->findIntersectionWith (ray, distance);
		if ((newDistance >= 0.0) && (newDistance < distance)) {
			closestPrim = _scene->getPrimitive (i);
			distance = newDistance;
		}
	}

	if (!closestPrim) {
		return color;
	}
		
	//calculate diffuse lighting
	Vector3 pointOfInters = ray.getDirection () * distance + ray.getOrigin ();
	Vector3 normal = closestPrim->getNormalAt (pointOfInters);
	for (int i = 0; i < _scene->getNumberOfPrimitives (); i++) {
		Primitive* light = _scene->getPrimitive (i);
		if (!light->getIsLight ()) { 
			continue;
		}
		if (light == closestPrim) {
			color = light->getColor ();
			break;
		}
		Vector3 lightDir = light->getOrigin () - pointOfInters;
		lightDir.normalize();
		float lightCoef = normal.dotProduct (lightDir);
		color = color + closestPrim->getColor () * lightCoef;
	}

	return color;
}
