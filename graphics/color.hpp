/* Author: a_m0d <am0d@hotmail.com>
 * Date: May 2008
 * License: GPL version 2.0 or later
 */

#ifndef color_hpp
#define color_hpp

class Color {
    public:
        Color ();
        Color (float r, float g, float b);
        Color (const Color& other);

        ~Color ();

        float getR ();
        float getG ();
        float getB ();

        void setR (float r);
        void setG (float g);
        void setB (float b);

        Color operator + (const Color& other);
        Color operator * (float factor);
        Color operator = (const Color& other);

    private:
        float _r, _g, _b;
};

#endif
