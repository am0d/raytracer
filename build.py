from buildit import Unix
from buildit import CXX

raytracer = Unix("raytracer")
raytracer.compiler = CXX()
raytracer.add_flag(['-pedantic', '-Wall', '-ansi',
                              '-Warray-bounds',
                              '-Wclobbered', '-Wconversion', '-Wdeprecated',
                              '-Weffc++', '-Wenum-compare', '-Wextra',
                              '-Wreorder', '-Wold-style-cast', '-Wabi'])
raytracer.add(['graphics', 'math', 'primitives', '.'])
raytracer.run()
