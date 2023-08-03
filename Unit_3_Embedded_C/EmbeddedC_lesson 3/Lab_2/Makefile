CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
#includes
INCS=-I .
#libraries
LIBS= 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
ProjectName = unt3_lab2_cortex_m3

all: $(ProjectName).bin
	@echo "===================== Build is Done ====================="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	@echo "====================== "$@" is Done ======================"

%.o:%.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	@echo "====================== "$@" is Done ======================"

$(ProjectName).elf: $(OBJ) $(AsOBJ) linker_script.ld 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	@echo "====================== "$@" is Done ======================"

$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo "====================== "$@" is Done ======================"


build:
	qemu-system-arm.exe -M versatilepb -m 128M -nographic -kernel $(ProjectName).bin


clean_all:
	rm *.o *.bin *.elf
	@echo "=================== EveryThing is clean ==================="


clean:
	rm *.bin *.elf










path:
	export PATH=/d/....C_Programs/ST/STM32CubeIDE_1.4.0/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.7-2018-q2-update.win32_1.4.0.202007081208/tools/bin:$PATH
	export PATH=$PATH:/d/....C_Programs/Qemu/