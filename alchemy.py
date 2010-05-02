from buildit import *

raytracer = Project("Raytracer")
raytracer.require_lib('lib_jpeg')
with raytracer.add_target(Executable()) as executable:
    executable.add(['.', 'math', 'graphics', 'primitives'])
raytracer.run()
