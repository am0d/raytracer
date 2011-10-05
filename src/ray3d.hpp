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

#ifndef ray3d_hpp
#define ray3d_hpp

#include "vector3.hpp"

class Ray3D {
    public:
        Ray3D ();
        Ray3D (Vector3 origin, Vector3 direction);
        Ray3D (const Ray3D& other);

        ~Ray3D ();

        Vector3 getOrigin ();
        Vector3 getDirection ();

        void setOrigin (Vector3 origin);
        void setDirection (Vector3 direction);

    private:
        Vector3 _origin;
        Vector3 _direction;
};

#endif
