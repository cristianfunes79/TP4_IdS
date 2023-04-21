SRC_DIR = ./src
INC_DIR = ./inc
OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
$(info $(SRC_FILES))

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
$(info $(OBJ_FILES))

.DEFAULT_GOAL := all

-include $(patsubst %.o,%.d,$(OBJ_FILES))

all: $(OBJ_FILES)
	@echo "Enlazando $<"
	@gcc $(OBJ_FILES) -o $(OUT_DIR)/app.elf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@echo "Compilando $<"
	@gcc -o $@ -c $< -I$(INC_DIR) -MMD -DGPIO_COUNT=8

$(OBJ_DIR): $(OUT_DIR)
	@mkdir -p $@

$(OUT_DIR):
	@mkdir -p $@

.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf $(OUT_DIR)