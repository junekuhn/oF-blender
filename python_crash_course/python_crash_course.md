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

so = bpy.context.active_object
so.modifiers.new("my Mod", 'SUBSURF')
^ will create a new modifier, in the cube case is makes it like a sphere

then rotate the scene to update the scne

then go to the modifiers panel for the object
should be there with the new you gave it

bpy.context.object.modifiers["my Mod"].levels = 2
changes the specific attribute

you can store the modifier as a variable

smoothing with a for loop

mesh = so.data

for face in mesh.polygons:

### textures

Creating a texture programmatically

texture = bpy.data.textures.new("my texture", 'DISTORTED_NOISE')

texture.noise_scale = 2.0

mod.displace.texture = texture



### Materials

new_mat = bpy.data.materials.new(name = "my material")
so.data.materials.append(new_mat)

new_mat.use_nodes = true

new_mat.node_tree.nodes

### operators

