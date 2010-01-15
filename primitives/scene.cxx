/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: June 2008
 * License: GPL version 2.0 or later
 */

#include "../header.hpp"

Scene::Scene ():
    _numberOfPrimitives (0),
    _primitives (NULL) {

        _primitives = new Primitive* [_numberOfPrimitives];
        _primitives [0] = new Sphere (Vector3 (-1.0, 0.0, 0.0));
        _primitives [1] = new Sphere (Vector3 ( 0.0, 0.0, 0.0));
        _primitives [2] = new Sphere (Vector3 ( 1.0, 0.0, 0.0));

        _primitives [0]->setColor (Color (1.0, 0.0, 0.0));
}

Scene::Scene (int numberOfPrimitives, int minX, int maxX, int minY, int maxY, int minZ, int maxZ, int maxRadius):
    _numberOfPrimitives (3),
    _primitives (NULL) {

        _primitives = new Primitive* [_numberOfPrimitives];

        _primitives [0] = new Sphere (Vector3 (-3, 0, -2), 2, Color(1.0, 0.0, 1.0));
        _primitives [1] = new Sphere (Vector3 (3, 0, -2), 2, Color(1.0, 0.0, 0.0));
        _primitives [2] = new Sphere (Vector3 (0, -2, 2), 1, Color(1.0, 1.0, 1.0));
        _primitives [2]->setIsLight (true);
}

Scene::~Scene () {
    if (_primitives) {
        for (int i=0; i < _numberOfPrimitives; i++) delete _primitives [i];
        delete[] _primitives;
    }
}

int Scene::getNumberOfPrimitives () {
    return _numberOfPrimitives;
}

Primitive* Scene::getPrimitive (int number) {
    if (number > _numberOfPrimitives) {
        cout << "Error: primitive number requested to high" << endl;
        return NULL;
    }

    return _primitives [number];
}
