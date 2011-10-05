/* Author: a_m0d <a_m0d@hotmail.com>
 * Date: June 2008
 * License: GPL version 2.0 or later
 */

#ifndef bitmap_hpp
#define bitmap_hpp

#include <string>
#include "color.hpp"
#include "errors.hpp"

class Bitmap {
    public:
        Bitmap ();
        Bitmap (int width, int height);
        Bitmap (const Bitmap& other);
        Bitmap& operator = (Bitmap other);

        ~Bitmap ();

        int getWidth ();
        int getHeight ();

        void setWidth (int width);	//WARNING: calling this function erases all data in the bitmap
        void setHeight (int height);	//WARNING: calling this function erases all data in the bitmap

        ErrorCode saveAsTGA (std::string fileName);
        ErrorCode putPixel (int x, int y, Color& color);
        Color getPixel (int x, int y);

    private:
        int _width, _height;
        Color* _pixelData;


};

#endif
