/*
Linker_Script_Arm_Cortex_M3
Eng.Mohamed Hazem Yahya
*/


MEMORY
{
FLASH(RX) 	: ORIGIN = 0x08000000 , LENGTH = 128K
SRAM(RWX) 	: ORIGIN = 0x20000000 , LENGTH = 20K
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
        _E_Data = .;
        . = ALIGN(4);
    }> SRAM AT> FLASH

    .bss : {
        _S_Bss = .;
        *(.bss)
        _E_Bss = .;
        
        . = ALIGN(4);
        . = . + 0x1000;
        _Stak_Top = .;
    }> SRAM

}