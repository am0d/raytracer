#include "header.hpp"

int main (int argc, char* argv []) {
	srand ((unsigned) time(NULL));
	RayTracer tracer;

	tracer.initScene ();
	tracer.render ();

	tracer.getBitmap ()->saveAsTGA ("render.tga");

	return 0;
}
