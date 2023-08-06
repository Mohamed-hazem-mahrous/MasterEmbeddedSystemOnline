CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g

#includes
INCS=-I .

#libraries
LIBS= 

# 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

ProjectName = unt3_lab3_cortex_m4


all: $(ProjectName).bin
	@echo -e "===================== Build is Done =====================\n"

path:
	export PATH=/d/....C_Programs/ST/STM32CubeIDE_1.4.0/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.7-2018-q2-update.win32_1.4.0.202007081208/tools/bin:$PATH
	export PATH=$PATH:/d/....C_Programs/Qemu/

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	@echo -e "====================== "$@" is Done ======================\n"

%.o:%.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	@echo -e "====================== "$@" is Done ======================\n"

$(ProjectName).elf: $(OBJ) $(AsOBJ) linker_script.ld 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(ProjectName).elf $(ProjectName).axf
	@echo -e "====================== "$@" is Done ======================\n"

$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo -e "====================== "$@" is Done ======================"


clean_all:
	rm *.o *.bin *.elf *.map
	@echo -e "=================== EveryThing is clean ==================="


clean:
	rm *.bin *.elf
