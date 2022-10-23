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

CC          := clang++ -Wall
CPPFLAGS    := -Ofast
CPPDBGFLAGS := -g -ggdb -D DEBUG
DBG         := gdb -q

INCLUDE     := -I $(INCLUDE_DIR) -I $(LIB_DIR)
LIB         := -L$(LIB_DIR) -lcsv -lm

# targets

TARGET      := $(LIB_DIR)/libcsv.a
DBG_TARGET  := $(LIB_DIR)/libcsv-dbg.a

SOURCES     := $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT))
TESTSRC     := $(shell find $(TEST_DIR)/ -name "*."$(SRCEXT))
HEADERS     := $(shell find $(INCLUDE_DIR)/ -name "*.$(HEADEREXT)")

## release build

all: mkdirp $(LIB_DIR)/libcsv.hpp $(TARGET)

OBJECTS     := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BUILD_DIR)/%.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*.$(SRCEXT)"))

$(OBJECTS): $(SOURCES)
	@cd $(SRC_DIR) && $(MAKE)

$(TARGET): $(OBJECTS)
	ar rcs $(TARGET) $(BUILD_DIR)/*.$(OBJEXT)

## debug build

dbg: mkdirp $(LIB_DIR)/libcsv.hpp $(DBG_TARGET)

DBG_OBJECTS := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BUILD_DIR)/%-dbg.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*.$(SRCEXT)"))

$(DBG_OBJECTS): $(SOURCES)
	@cd $(SRC_DIR) && $(MAKE) dbg

$(DBG_TARGET): $(DBG_OBJECTS)
	ar rcs $(DBG_TARGET) $(BUILD_DIR)/*-dbg.$(OBJEXT)

$(LIB_DIR)/libcsv.hpp: $(HEADERS)
	@grep --no-filename -v '^#\s*include\s*"' $(HEADERS) > $(LIB_DIR)/libcsv.hpp
	$(info make $(LIB_DIR)/libcsv.hpp)

## execution

test: mkdirp $(TARGET) $(TESTSRC)
	@$(CC) $(CPPFLAGS) $(INCLUDE) $(TEST_DIR)/*.cpp -o $(BIN_DIR)/test $(LIB)
	./$(BIN_DIR)/test

testdbg: mkdirp $(DBG_OBJECTS) $(TESTSRC)
	@$(CC) $(CPPDBGFLAGS) $(INCLUDE) $(DBG_OBJECTS) $(TEST_DIR)/*.cpp -o $(BIN_DIR)/test-dbg
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
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(LIB_DIR)
