// startup.c
// Eng.Mohamed Hazem Yahya

#include "stdint.h"
extern int main();

void Reset_Handler ();
void Default_Handler(){
    Reset_Handler();
}
void NMI_Handler () __attribute__((weak, alias ("Default_Handler")));;
void H_Fault_Handler () __attribute__((weak, alias ("Default_Handler")));;


// booking 1024 Bytes located by .bss through un intialized array of int of 256 element (256*4=1024)
static unsigned long Stack_Top[256];

void (* const g_p_fn_vectors[])()__attribute__((section(".vectors"))) = {
    (void(*)())     ((unsigned long)Stack_Top + sizeof(Stack_Top)),
    &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler
};

extern unsigned int _E_text;

extern unsigned int _S_Data;
extern unsigned int _E_Data;

extern unsigned int _S_Bss;
extern unsigned int _E_Bss;


void Reset_Handler(void){

    // copy data from flash to sram
    unsigned int Data_Size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data;  // know the size of the data

    unsigned char* P_SRC = (unsigned char*)&_E_text;  //know the source of the data which is end of text at FLASH
    unsigned char* P_DST = (unsigned char*)&_S_Data;  //know the destnation of the data which is start of data at SRAM

    for (int i = 0; i < Data_Size; i++)
    {
        *((unsigned char*)P_DST++) = *((unsigned char*)P_SRC++); //copy data from source to destnation
    }



    // Init BSS section by 0
    unsigned int Bss_Size = (unsigned char*)&_E_Bss - (unsigned char*)&_S_Bss;  // know the size of the bss

    P_DST = (unsigned char*)&_S_Bss;

    for (int i = 0; i < Bss_Size; i++)
    {
        *((unsigned char*)P_DST++) = (unsigned char)0; //make it all 0
    }


    // call main()
    main();
}














