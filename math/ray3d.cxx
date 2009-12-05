/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: May 2008
 * License: GPL version 2.0 or later
 */

#include "../header.hpp"

Ray3D::Ray3D ():
    _origin (Vector3 ()), _direction (Vector3 ()) {
}

Ray3D::Ray3D (Vector3 origin, Vector3 direction):
    _origin (origin), _direction (direction) {
}

Ray3D::Ray3D (const Ray3D& other):
    _origin (other._origin), _direction (other._direction) {
}

Ray3D::~Ray3D () {

}

Vector3 Ray3D::getOrigin () {
    return _origin;
}

Vector3 Ray3D::getDirection () {
    return _direction;
}

void Ray3D::setOrigin (Vector3 origin) {
    _origin = origin;
}

void Ray3D::setDirection (Vector3 direction) {
    _direction = direction;
    _direction.normalize ();
}
