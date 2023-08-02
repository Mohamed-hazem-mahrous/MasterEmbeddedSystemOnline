CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
#includes
INCS=-I .
#libraries
LIBS= 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
ProjectName = unt3_lab1

all: $(ProjectName).bin
	@echo "===================== Build is Done ====================="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	@echo "====================== "$@" is Done ======================"

%.o:%.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	@echo "====================== "$@" is Done ======================"

$(ProjectName).elf: $(OBJ) $(AsOBJ) linker_script.ld 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@
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
