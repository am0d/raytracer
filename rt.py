from buildit import Unix
from buildit import CXX

raytracer = Unix("raytracer")
raytracer.compiler = CXX()
raytracer.add(['graphics', 'math', 'primitives', '.'])
raytracer.run()
