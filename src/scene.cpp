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

#include <iostream>

#include "scene.hpp"
#include "sphere.hpp"

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
        std::cout << "Error: primitive number requested to high" << std::endl;
        return NULL;
    }

    return _primitives [number];
}
