CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3

#includes
INCS=-I .

#libraries
LIBS= 

# 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

ProjectName = unt6_lsn4_lab1


all: $(ProjectName).bin
	@echo -e "===================== Build is Done =====================\n"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	@echo -e "====================== "$@" is Done ======================\n"

%.o:%.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	@echo -e "====================== "$@" is Done ======================\n"

$(ProjectName).elf: $(OBJ) $(AsOBJ) linker_script.ld 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	@echo -e "====================== "$@" is Done ======================\n"

$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo -e "====================== "$@" is Done ======================\n"


build:
	qemu-system-arm.exe -M versatilepb -m 128M -nographic -kernel $(ProjectName).bin


clean_all:
	rm *.o *.bin *.elf *.axf *.map
	@echo -e "=================== EveryThing is clean ===================\n"


clean:
	rm *.bin *.elf
