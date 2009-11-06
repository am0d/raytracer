/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: June 2008
 * License: GPL version 2.0 or later
 */

#ifndef raytracer_hpp
#define raytracer_hpp

#include "header.hpp"

typedef class RayTracer {
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

		int _left, _right, _top, _bottom;	//holds the co-ords of our current viewport

		Scene* _scene;	//list of the spheres in the scene
					//TODO: Change this to a list of primitives!

		Bitmap* _bitmap;	//holds our render surface

		float _deltaX, _deltaY;	//holds the amount to move our rays by
		float _sigmaX, _sigmaY;	//holds the current x and y of the ray
		int _curScanLine, _x;	//holds our position on the bitmap

		bool _done;		//are we finished this render yet?
};

#endif
