# Python Crash Course in Blender
https://www.youtube.com/watch?v=XqX5wh4YeRw

### Setup

Blender Preferences -> Interface -> Python Tooltips
tells you import info to script in python
the info window does the same thing
copy/paste!

Text Editor
enable syntax highlighting
you can save files after naming them

### Modules

import bpy

using custom modules?

### Objects

ops
a selection of useful commands
utility really
ops.mesh.primitive_cube_add
the created object will be automatically selected

so = bpy.context.active_object

so.location[0] = 5 # moves the object along x axis

option P executes script

from math import *
so.rotation_euler[0] += radians(45)

### Modifiers

### Smoothing

### textures

### Materials

### operators

