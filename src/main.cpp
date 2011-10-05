#include <cstdlib>

#include "raytracer.hpp"
#include "bitmap.hpp"

int main () {
	srand (static_cast<unsigned> (time(NULL)));
	RayTracer tracer;

	tracer.initScene ();
	tracer.render ();

	tracer.getBitmap ()->saveAsTGA ("render.tga");

	return 0;
}
