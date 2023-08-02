// startup.c
// Eng.Mohamed Hazem Yahya

#include "stdint.h"
extern int main();
extern unsigned int _Stak_Top;

void Reset_Handler ();
void Default_Handler(){
    Reset_Handler();
}
void NMI_Handler () __attribute__((weak, alias ("Default_Handler")));;
void H_Fault_Handler () __attribute__((weak, alias ("Default_Handler")));;
void MM_Fault_Handler () __attribute__((weak, alias ("Default_Handler")));;
void Bus_Fault () __attribute__((weak, alias ("Default_Handler")));;
void Usage_Fault_Handler () __attribute__((weak, alias ("Default_Handler")));;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t) &_Stak_Top,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &H_Fault_Handler,
    (uint32_t) &MM_Fault_Handler,
    (uint32_t) &Bus_Fault,
    (uint32_t) &Usage_Fault_Handler    
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














