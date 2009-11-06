/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: May 2008
 * License: GPL version 2.0 or later
 */

#ifndef primitive_hpp
#define primitive_hpp

#include "../header.hpp"

typedef class Primitive {
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
		bool _isLight;
		Color _color;
};

#endif
