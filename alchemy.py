from buildit import *

raytracer = Project("Raytracer")
with raytracer.add_target(Executable()) as executable:
    executable.printout()
raytracer.run()
