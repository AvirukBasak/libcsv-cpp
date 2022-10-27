SRCEXT      := cpp
OBJEXT      := o
HEADEREXT   := hpp

# directories

SRC_DIR     := src
BUILD_DIR   := build
BIN_DIR     := bin
LIB_DIR     := lib
TEST_DIR    := tests
INCLUDE_DIR := include

# compiler options

LIB_NAME    := csv

CC          := g++
CFLAGS      := -Wall -Ofast
CDBGFLAGS   := -Wall -g -ggdb -D DEBUG
DBG         := gdb -q

INCLUDE     := -I $(INCLUDE_DIR) -I $(LIB_DIR)
LIB         := -L$(LIB_DIR) -l$(LIB_NAME) -lm

# targets

TARGET_NAME := lib$(LIB_NAME)
TARGET      := $(LIB_DIR)/$(TARGET_NAME).a
DBG_TARGET  := $(LIB_DIR)/$(TARGET_NAME)-dbg.a

SOURCES     := $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT))
TESTSRC     := $(shell find $(TEST_DIR)/ -name "*."$(SRCEXT))
HEADERS     := $(shell find $(INCLUDE_DIR)/ -name "*."$(HEADEREXT))

## release build

all: mkdirp $(LIB_DIR)/$(TARGET_NAME).$(HEADEREXT) $(TARGET)

OBJECTS     := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BUILD_DIR)/%.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT)))

$(OBJECTS): $(SOURCES)
	@cd $(SRC_DIR) && $(MAKE)

$(TARGET): $(OBJECTS)
	ar rcs $(TARGET) $(BUILD_DIR)/*.$(OBJEXT)

## debug build

dbg: mkdirp $(LIB_DIR)/$(TARGET_NAME).$(HEADEREXT) $(DBG_TARGET)

DBG_OBJECTS := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BUILD_DIR)/%-dbg.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT)))

$(DBG_OBJECTS): $(SOURCES)
	@cd $(SRC_DIR) && $(MAKE) dbg

$(DBG_TARGET): $(DBG_OBJECTS)
	ar rcs $(DBG_TARGET) $(BUILD_DIR)/*-dbg.$(OBJEXT)

$(LIB_DIR)/$(TARGET_NAME).$(HEADEREXT): $(HEADERS)
	@grep --no-filename -v '^#\s*include\s*"' $(HEADERS) > $(LIB_DIR)/$(TARGET_NAME).$(HEADEREXT)
	$(info make $(LIB_DIR)/$(TARGET_NAME).$(HEADEREXT))

## execution

test: mkdirp $(TARGET) $(TESTSRC)
	@$(CC) $(CFLAGS) $(INCLUDE) $(TEST_DIR)/*.$(SRCEXT) -o $(BIN_DIR)/test $(LIB)
	./$(BIN_DIR)/test

testdbg: mkdirp $(DBG_OBJECTS) $(TESTSRC)
	@$(CC) $(CDBGFLAGS) $(INCLUDE) $(DBG_OBJECTS) $(TEST_DIR)/*.$(SRCEXT) -o $(BIN_DIR)/test-dbg
	$(DBG) $(BIN_DIR)/test-dbg

## mkdirp

mkdirp:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(LIB_DIR)

## Clean

clean:
	@cd $(SRC_DIR) && $(MAKE) clean

cleaner:
	@cd $(SRC_DIR) && $(MAKE) cleaner
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(LIB_DIR)
