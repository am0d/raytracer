/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: May 2008
 * License: GPL version 2.0 or later
 */

#ifndef vector3_hpp
#define vector3_hpp

#include "../header.hpp"

typedef class Vector3 {
	public:
		Vector3 ();
		Vector3 (float x, float y, float z);
		Vector3 (const Vector3& other);

		~Vector3 ();

		float getX ();
		float getY ();
		float getZ ();

		void setX (float x);
		void setY (float y);
		void setZ (float z);

		float dotProduct (const Vector3& other);
		void normalize ();

		Vector3 operator + (const Vector3& other);
		Vector3 operator - (const Vector3& other);
		Vector3 operator * (float factor);
	private:
		float _x, _y, _z;
};

#endif
