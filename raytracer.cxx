#include "raytracer.hpp"

RayTracer::RayTracer () :
    _left (-4), _right (4),
    _top (3), _bottom (-3),
    _deltaX (0.0), _deltaY (0.0),
    _sigmaX (0.0), _sigmaY (0.0),
    _curScanLine (0), _done (false),
    _bitmap (NULL),
    _scene (NULL) {

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
    _deltaX = static_cast<float> (_right - _left) / static_cast<float> (_bitmap->getWidth ());
    _deltaY = static_cast<float> (_bottom - _top) / static_cast<float> (_bitmap->getHeight ());

    _sigmaX = static_cast<float> (_left);
    _sigmaY = static_cast<float> (_top);

    _curScanLine = 0;

    _done = false;
}

bool RayTracer::render () {
    Ray3D ray;

    ray.setOrigin (Vector3 (0, 0, 5));

    for (; _curScanLine < _bitmap->getHeight (); _curScanLine++) {
        for (int x = 0; x < _bitmap->getWidth (); x++) {
            ray.setDirection (Vector3 (_sigmaX, _sigmaY, 0) - ray.getOrigin ());	//no need to normalize - Ray3D does this automatically for us!

            Color pixelColor = traceRay (ray, 999999999.0f);

            if (_bitmap->putPixel (x, _curScanLine, pixelColor) != E_SUCCESS) {
                return (_done = false);
            }

            _sigmaX += _deltaX;
        }

        _sigmaX = static_cast<float> (_left);
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

    if (closestPrim == NULL) {
        return color;
    }

    if (closestPrim->getIsLight ()) {
        color = closestPrim->getColor ();
        return color;
    }

    // calculate diffuse lighting
    Vector3 pointOfIntersection = ray.getDirection () * distance + ray.getOrigin ();
    Vector3 normal = closestPrim->getNormalAt (pointOfIntersection);
    for (int i = 0; i < _scene->getNumberOfPrimitives (); i++) {
        Primitive* light = _scene->getPrimitive (i);
        if (!light->getIsLight ()) { 
            // wait, this isn't actually a light ...
            continue;
        }

        Vector3 lightDir = light->getOrigin () - pointOfIntersection;
        lightDir.normalize();
        float lightCoef = normal.dotProduct (lightDir);
        color = color + closestPrim->getColor () * light->getColor () * lightCoef;
    }

    return color;
}
