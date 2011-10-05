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

#ifndef vector3_hpp
#define vector3_hpp

class Vector3 {
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
    Vector3& operator = (const Vector3 other);
    protected:
        float _x;
        float _y;
        float _z;
};

#endif
