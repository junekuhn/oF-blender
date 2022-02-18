import bpy
D = bpy.data
C = bpy.context

move_from = D.collections['Collection']
move_to = D.collections['NEW_Collection.001']

to_unlink = []

#link the objects in the new scene first
for ob in move_from.objects:
    try:
        move_to.objects.link(ob)
    except RuntimeError:
        pass
    to_unlink.append(ob)

# unlink the objects where they were from
for ob in to_unlink:
    move_from.objects.unlink(ob)

