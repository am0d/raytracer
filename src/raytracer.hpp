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

#ifndef raytracer_hpp
#define raytracer_hpp

#include "color.hpp"
#include "bitmap.hpp"
#include "scene.hpp"
#include "ray3d.hpp"

class RayTracer {
    public:
    RayTracer ();
    RayTracer (int left, int right, int top, int bottom);
    RayTracer (const RayTracer& other);

    ~RayTracer ();

    void initScene ();
    bool render ();

    Bitmap* getBitmap ();

    bool done ();

    private:

    Color traceRay (Ray3D ray, float minDistance);
    RayTracer operator = (const RayTracer&);


    int _left, _right, _top, _bottom;	//holds the co-ords of our current viewport

    float _deltaX, _deltaY;	//holds the amount to move our rays by
    float _sigmaX, _sigmaY;	//holds the current x and y of the ray
    int _curScanLine;	//holds our position on the bitmap

    bool _done;		//are we finished this render yet?

    Bitmap* _bitmap;	//holds our render surface

    Scene* _scene;	//list of the spheres in the scene
    //TODO: Change this to a list of primitives!
};

#endif
