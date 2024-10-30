#!/usr/bin/env python
# ir_layer.py
# License: GPLv3

from gimpfu import *

def python_ir_layer(image, drawable):
    pdb.gimp_image_undo_group_start(image)
    prev_layer = image.active_layer
    pdb.gimp_edit_copy(image.active_layer)
    fsel = pdb.gimp_edit_paste(drawable, False)
    pdb.gimp_floating_sel_to_layer(fsel)
    pdb.gimp_invert(fsel)
    pdb.gimp_layer_set_mode(fsel, 26)
    pdb.gimp_image_undo_group_end(image)

register(
    "python_fu_ir_color_swap",
    "Create new layer, swap color, and set layer mode to HSL color",
    "Create new layer, swap color, and set layer mode to HSL color",
    "Mike Bing",
    "Mike Bing",
    "2022",
    "<Image>/Filters/IR RB channel swap equivalent ...",
    "RGB*, GRAY*",
    [],
    [],
    python_ir_layer
)

main()
