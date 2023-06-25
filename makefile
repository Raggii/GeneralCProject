#foreach *.c
CC = gcc
CCTAGS = -L.
DEPFLAGS = -MMD -MF

BUILD_LOCATION = build/
LOC_REPO = C:\Users\allredj\C_Logger\GeneralCProject\build

SRC_FOLDER = src
SRC_T := src\modules src\utils
# SRC := src\utils $(foreach dir, $(SRC_T),$(shell dir /B /AD $(dir)))
# # Make sure we autoamtically get new folders when they are added
SRC = src/modules/folderTest src/utils
SRC_FILES = src/main.c $(foreach dir,$(SRC),$(wildcard $(dir)/*.c))

DEP_FILES = $(patsubst %.c,%.d,$(SRC_FILES))
DEP_SAVE = $(addprefix $(BUILD_LOCATION), $(DEP_FILES))
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
OBJ_SAVE = $(addprefix $(BUILD_LOCATION), $(OBJ_FILES))

EXECUTABLE = program

all: $(EXECUTABLE)
	
#Ok this is a pattern
#For any .o file in the build location (HAS to be in build location)
#It will run this rule when converting a C file to a .o file
$(BUILD_LOCATION)%.o: %.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) -c $< -o $@

$(BUILD_LOCATION)%.d: %.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(DEPFLAGS) $@ -c $<

$(EXECUTABLE): $(OBJ_SAVE) 
	$(CC) -MMD $^ -v -o $@

test:
	echo $(DEP_SAVE)

clean:
	rd /s /q $(LOC_REPO)


.PHONY:
