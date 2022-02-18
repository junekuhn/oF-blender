# these are the notes for the scripting for artists videos

### Video 1: Collections

Open the python console from the editor dropdowns, under 'scripting'.  I modified the timeline to become the scripting console.

iterating over an existing collecton

Scene object - Collection property (new in 2.8)
C.scene.collection
C.scene.collection.name
C.scene.collection.objects
list(C.scene.collection.objects)
list(C.scene.collection.all_objects)
D.collections['Collections 1']

Creating a collection using python

myCol = D.collections.new('NEW_Collection')
C.scene.collection.children.link(myCol)
C.scene.collection.objects.link(object_name)

Writing a script

open the 'text editor'
import bpy
D = bpy.data
C = bpy.context

Where's the system console?
https://blender.stackexchange.com/questions/102860/how-to-open-system-console-to-get-output-from-blender-on-mac-os-10
such a painnn

### Video 2: While Loops

Getting a mesh

mesh = C.active_object.data
len(mesh.vectices)

in and out of edit mode

bpy.ops.object.mode_set(mode='EDIT')
bpy.ops.mesh.select_all(action='SELECT')
bpy.ops.mesh.subdivide()

*** note that you can get these commands by cmd+C while hovering over a drop-down item ***

### Video 3: Operator

you need a class to make a new operator

3 primary methods, execute, modal, invoke

when you create the operator
bpy.ops.mesh.monkey_grid() will execute the new operator

go to Text -> Register in the window to manually register it

BL_OPTIONS you can add the panels, like undo and register
you can add default properties

the context object get inherited from the parent
context.selected_pose_bones

@classmethod
def poll(cls, context):
    return True

    context.area.type

same as C (bpy.context)

C.area.type returns the console

this is used to make it only show up where you want to









