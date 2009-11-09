/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: May 2008
 * License: GPL version 2.0 or later
 */

#ifndef ray3d_hpp
#define ray3d_hpp

#include "../header.hpp"

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
