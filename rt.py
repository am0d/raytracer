from buildit import Unix
from buildit import CXX

raytracer = Unix("raytracer")
raytracer.add(['graphics', 'math', 'primitives', '.'])
raytracer.compiler = CXX()
raytracer.run()
