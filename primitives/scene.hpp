/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: June 2008
 * License: GPL version 2.0 or later
 */

#ifndef scene_hpp
#define scene_hpp

#include "../header.hpp"

typedef class Scene {
	public:
		Scene ();
		Scene (int numberOfPrimitives, int minX, int maxX, int minY, int maxY, int minZ, int maxZ, int maxRadius);
		//Scene (const Scene& other);

		~Scene ();

		int getNumberOfPrimitives ();
		Primitive* getPrimitive (int number);

	private:
		Primitive** _primitives;
		int _numberOfPrimitives;
};

#endif
