#include <cstdlib>

#include "raytracer.hpp"
#include "graphics/bitmap.hpp"

int main () {
	srand ((unsigned) time(NULL));
	RayTracer tracer;

	tracer.initScene ();
	tracer.render ();

	tracer.getBitmap ()->saveAsTGA ("render.tga");

	return 0;
}
