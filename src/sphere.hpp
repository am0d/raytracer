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
