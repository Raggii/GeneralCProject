#foreach *.c

BUILD_LOCATION = build/
# Make sure we autoamtically get new folders when they are added
SRC = src/ src/utils/
SRC_FILES = $(foreach dir,$(SRC),$(wildcard $(dir)*.c))

DEL = del


.PHONY: all
all:
	gcc $(SRC_FILES) -o build/program
	
program:
	build\program.exe

#REMEMER THE BACKWARDS SLASH
.PHONY: clean
clean:
	-$(DEL) build\program.exe


