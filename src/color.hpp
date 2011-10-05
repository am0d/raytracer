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
        Color operator * (Color other);
        Color& operator = (const Color& other);

    private:
        float _r, _g, _b;
};

#endif
