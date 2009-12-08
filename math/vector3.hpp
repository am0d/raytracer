/* Author: a_m0d <a_m0d@hotmail.com>
* Date: May 2008
* License: GPL version 2.0 or later
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
    void operator = (const Vector3 other);
    protected:
    union {
        float _x, _r;
    };
    union {
        float _y, _g;
    };
    union {
        float _z, _b;
    };
};

#endif
