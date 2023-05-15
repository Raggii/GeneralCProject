#foreach *.c
CC = gcc
CCTAGS = -L.

BUILD_LOCATION = ../build/
LOC_REPO = C:\Users\allredj\C_Logger\GeneralCProject\build
# # Make sure we autoamtically get new folders when they are added
SRC = module
SRC_FILES = main.c $(foreach dir,$(SRC),$(wildcard $(dir)/*.c))

OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
OBJ_SAVE = $(addprefix $(BUILD_LOCATION), $(OBJ_FILES))

EXECUTABLE = program

all: $(EXECUTABLE)

#Ok this is a pattern
#For any .o file in the build location (HAS to be in build location)
#It will run this rule when converting a C file to a .o file
$(BUILD_LOCATION)%.o: %.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) -c $< -o $(BUILD_LOCATION)$@

$(EXECUTABLE): $(OBJ_SAVE)
	$(CC) $^ -o $(BUILD_LOCATION)$@


clean:
	rd /s /q $(LOC_REPO)