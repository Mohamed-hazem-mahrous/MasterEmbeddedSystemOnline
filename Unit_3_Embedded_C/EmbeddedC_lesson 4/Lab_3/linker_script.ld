/*
Linker_Script_Arm_Cortex_M3
Eng.Mohamed Hazem Yahya
*/


MEMORY
{
FLASH(RX) 	: ORIGIN = 0x00000000 , LENGTH = 512M
SRAM(RWX) 	: ORIGIN = 0x20000000 , LENGTH = 512M
}


SECTIONS
{
    .text : {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = .;
    }> FLASH


    .data : {
        _S_Data = .;
        *(.data)
        . = ALIGN(4);
        _E_Data = .;
    }> SRAM AT> FLASH

    .bss : {
        _S_Bss = .;
        *(.bss)
        _E_Bss = .;
    }> SRAM

}