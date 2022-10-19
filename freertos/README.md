# FreeRTOS

Implementations for both cores can be found here. They can be used on one core only or both at the same time taking advantage of the dualcore.

When M0 core FreeRTOS is used, the `RIT Timer` is the chosen timer to act as a substitute for the SysTick on the M0 core, so this resource cannot be used either on the M4 or M0 core.