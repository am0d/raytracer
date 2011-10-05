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

#ifndef primitive_hpp
#define primitive_hpp

#include "color.hpp"
#include "vector3.hpp"
#include "ray3d.hpp"

class Primitive {
    public:
    Primitive ();
    Primitive (Color color, bool isLight = false);
    Primitive (const Primitive& other);

    virtual ~Primitive ();

    virtual Vector3 getNormalAt (Vector3 position) = 0;
    virtual Vector3 getOrigin () = 0;
    virtual Color getColorAt (Vector3 position);
    virtual float findIntersectionWith (Ray3D ray, float minDistance) = 0;

    bool getIsLight ();
    void setIsLight (bool isLight);

    Color getColor ();
    void setColor (Color color);

    private:
    Color _color;
    bool _isLight;
};

#endif
