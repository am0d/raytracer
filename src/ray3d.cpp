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

#include "ray3d.hpp"

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
