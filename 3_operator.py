import bpy

# inherit from the the blender operator class
class MESH_OT_monkey_grid(bpy.types.Operator):
    #tooltip
    """Spreading Joy"""

    #built in constants for names
    bl_idname = "mesh.monkey_grid"
    bl_label = "Monkey Grid"
    bl_options = {'REGISTER', 'UNDO'}

    # adding properties to the operator
    count_x: bpy.props.IntProperty(
        name = "X",
        description = "Number of Monkey in X direction",
        default="3",
        min = 1
    )


    # adding properties to the operator
    count_y: bpy.props.IntProperty(
        name = "y",
        description = "Number of Monkey in y direction",
        default="2",
        min = 1
    )

    size: bpy.props.FloatProperty(
        name = "Size",
        description = "Size of the Monkey",
        default = "0.5",
        min=0, max = 1
    )


    def execute(self, context):
        # the code that creates the monkey grid
        for idx in range(self.count_x * self.count_y):
            x = idx % self.count_x
            y = idx // self.count_x
            bpy.ops.mesh.primitive_monkey_add(
                size=self.size,
                location=(x,y,1)
            )

        # do this when done
        return {'FINISHED'}


    # def invoke(self, context):
    #     ...
    # def modal(self, context, event):
    #     ...


def register():
    bpy.utils.register_class(MESH_OT_monkey_grid)

def unregister():
    bpy.utils.register_class(MESH_OT_monkey_grid)

#magic to register on run
if __name__ == '__main__':
    register()