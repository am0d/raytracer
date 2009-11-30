from buildit import Unix
from buildit import CXX

raytracer = Unix("raytracer")
raytracer.compiler = CXX()
raytracer.compiler.add_flags(['-pedantic', '-Wall', '-ansi',
                              '-Warray-bounds',
                              '-Wclobbered', '-Wconversion', '-Wdeprecated',
                              '-Weffc++', '-Wenum-compare', '-Wextra',
                              '-Wreorder'])
raytracer.add(['graphics', 'math', 'primitives', '.'])
raytracer.run()
