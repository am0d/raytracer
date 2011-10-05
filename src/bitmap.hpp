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
