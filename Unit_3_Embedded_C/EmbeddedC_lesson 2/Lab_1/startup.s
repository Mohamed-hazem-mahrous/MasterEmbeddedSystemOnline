.global reset

reset:
    ldr sp, =stack_top
    bl main

endless_loop:
    b endless_loop