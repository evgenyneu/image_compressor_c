#
# Makefile for building and testing image compressor
# --------------------------------------------------
#
# Build executable build/compressor:
# > make
#
# Build and run tests build/test:
# > make test
#
# Remove build files:
# > make clean
#
# This Makefile is based on: https://stackoverflow.com/a/30142139/297131
#

CXX = gcc
CXX_FLAGS = -O2 -ffast-math -g -std=c99 -Wall -Wextra -Wshadow -Wwrite-strings -Werror-implicit-function-declaration -Wundef -Wpointer-arith -Waggregate-return  -Wswitch-default -Wunreachable-code -Wformat=2 -Wmissing-prototypes -Wstrict-prototypes -Wconversion

# Final binary
BIN = compressor

# Put all auto generated stuff to this build dir.
BUILD_DIR = ./build

# List of all .c source files.
CFILES_ALL = $(wildcard src/*.c) $(wildcard src/**/*.c)

# List all *.c files excluding tests
CFILES = $(filter-out %_test.c, $(CFILES_ALL))

# List all unit test .c files
CTESTS = $(filter-out %main.c, $(CFILES_ALL))

ifeq ($(MAKECMDGOALS), test)
# Build tests
  CFILES_TO_BUILD=$(CTESTS)
  BIN = test
else
# Build the program
  CFILES_TO_BUILD=$(CFILES)
endif

# All .o files go to build dir.
OBJ = $(CFILES_TO_BUILD:%.c=$(BUILD_DIR)/%.o)

# Gcc/Clang will create these .d files containing dependencies.
DEP = $(OBJ:%.o=%.d)

# Default target named after the binary.
compressor : $(BUILD_DIR)/$(BIN)

# Build and run tests
test : $(BUILD_DIR)/$(BIN)
	$(BUILD_DIR)/test

# Actual target of the binary - depends on all .o files.
$(BUILD_DIR)/$(BIN) : $(OBJ)
# Create build directories - same structure as sources.
	mkdir -p $(@D)
# Link all the object files and make the executable.
	$(CXX) $(CXX_FLAGS) $^ -o $@

# Include all .d files
-include $(DEP)

# Build target for every single object file.
# The potential dependency on header files is covered
# by calling `-include $(DEP)`.
$(BUILD_DIR)/%.o : %.c
	mkdir -p $(@D)
# Complile *.c files into the object files.
# The -MMD flags additionaly creates a .d file with
# the same name as the .o file.
	$(CXX) $(CXX_FLAGS) -MMD -c $< -o $@

.PHONY : clean

clean :
# This should remove all generated files.
	-rm -rf $(BUILD_DIR)