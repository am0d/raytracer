/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: May 2008
 * License: GPL version 2.0 or later
 */

#ifndef sphere_hpp
#define sphere_hpp

#include "primitive.hpp"

class Sphere : public Primitive {
	public:
		Sphere ();
		Sphere (Vector3 origin, float radius = 1.0, Color color = Color (1.0,1.0,1.0), bool isLight=false);
		Sphere (const Sphere& other);

		~Sphere ();

		Vector3 getOrigin ();
		float getRadius ();

		void setOrigin (Vector3 origin);
		void setRadius (float radius);
		
		Vector3 getNormalAt (Vector3 position);
		float findIntersectionWith (Ray3D ray, float minDistance);
	private:
		Vector3 _origin;
		float _radius;
};	

#endif
