CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2 -g
# Directories
SRC_DIR=src
OBJ_DIR=object_file
LINKER_DIR=linker_script
OUTPUT_DIR=output_project
# Includes
INCS=-I$(SRC_DIR)
# Libraries
LIBS=
# Collect source files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

AS = $(wildcard $(SRC_DIR)/*.s)
ASOBJ = $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(AS))

ProjectName = First_Term_Project_1

all: $(OUTPUT_DIR)/$(ProjectName).bin
	@echo "===================== Build is Done ====================="

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	$(CC)as.exe $(CFLAGS) $< -o $@
	@echo "====================== "$@" is Done ======================"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	@echo "====================== "$@" is Done ======================"

$(OUTPUT_DIR)/$(ProjectName).elf: $(OBJ) $(ASOBJ) $(LINKER_DIR)/linker_script.ld
	@mkdir -p $(OUTPUT_DIR)
	$(CC)ld.exe -T $(LINKER_DIR)/linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=$(OUTPUT_DIR)/Map_file.map
	cp $(OUTPUT_DIR)/$(ProjectName).elf $(OUTPUT_DIR)/$(ProjectName).axf
	@echo "====================== "$@" is Done ======================"

$(OUTPUT_DIR)/$(ProjectName).bin: $(OUTPUT_DIR)/$(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo "====================== "$@" is Done ======================"


clean_all:
	rm -rf $(OBJ_DIR) $(OUTPUT_DIR)
	@echo "=================== EveryThing is clean ==================="


clean:
	rm -rf $(OBJ_DIR)/*.o $(OUTPUT_DIR)/*.bin $(OUTPUT_DIR)/*.elf $(OUTPUT_DIR)/*.map
