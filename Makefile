SRCEXT      := cpp
OBJEXT      := o
HEADEREXT   := hpp

# directories

SRC_DIR     := ./src
BIN_DIR     := ./bin
LIB_DIR     := ./lib
EXAMPLE_DIR := ./examples
INCLUDE_DIR := ./include

# compiler options

CC          := clang++ $(WALL)
CPPFLAGS    := -Ofast
CPPDBGFLAGS := -g -ggdb

INCLUDE     := -I $(INCLUDE_DIR)
LIB         := -L$(LIB_DIR) -lcsv -lm

# targets

TARGET      := $(LIB_DIR)/libcsv.a
DBG_TARGET  := $(LIB_DIR)/libcsv-dbg.a

SOURCES     := $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT))
TESTSRC     := $(shell find $(EXAMPLE_DIR)/ -name "*."$(SRCEXT))

## release build

all: mkdirp $(TARGET)

$(TARGET): SOURCES
	@cd $(SRC_DIR) && $(MAKE)
	ar rcs $(TARGET) $(BIN_DIR)/*.$(OBJEXT)

## debug build

dbg: mkdirp $(DBG_TARGET)

$(DBG_TARGET): $(SOURCES)
	@cd $(SRC_DIR) && $(MAKE) dbg
	ar rcs $(DBG_TARGET) $(BIN_DIR)/*-dbg.$(OBJEXT)

## execution

test: $(TARGET) $(TESTSRC)
	$(CC) $(CPPFLAGS) $(EXAMPLE_DIR)/*.cpp -o $(BIN_DIR)/exe $(LIB)
	./$(BIN_DIR)/test

testdbg: $(DBG_TARGET) $(TESTSRC)
	$(CC) $(CPPDBGFLAGS) $(EXAMPLE_DIR)/*.cpp -o $(BIN_DIR)/exe-dbg $(LIB)
	$(DBG) $(BIN_DIR)/test-dbg

## mkdirp

mkdirp:
	@mkdir -p $(BIN_DIR)

## Clean

clean:
	@cd $(SRC_DIR) && $(MAKE) clean

cleaner:
	@cd $(SRC_DIR) && $(MAKE) cleaner
	@rm -f $(BIN_DIR)/*
	@rm -f $(TARGET)
	@rm -f $(DBG_TARGET)
