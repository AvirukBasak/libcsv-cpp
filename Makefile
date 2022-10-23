SRCEXT      := cpp
OBJEXT      := o
HEADEREXT   := hpp

# directories

SRC_DIR     := src
BIN_DIR     := bin
LIB_DIR     := lib
EXAMPLE_DIR := examples
INCLUDE_DIR := include

# compiler options

CC          := clang++ $(WALL)
CPPFLAGS    := -Ofast
CPPDBGFLAGS := -g -ggdb

INCLUDE     := -I $(INCLUDE_DIR) -I $(LIB_DIR)
LIB         := -L$(LIB_DIR) -lcsv -lm

# targets

TARGET      := $(LIB_DIR)/libcsv.a
DBG_TARGET  := $(LIB_DIR)/libcsv-dbg.a

SOURCES     := $(shell find $(SRC_DIR)/ -name "*."$(SRCEXT))
TESTSRC     := $(shell find $(EXAMPLE_DIR)/ -name "*."$(SRCEXT))
HEADERS     := $(shell find $(INCLUDE_DIR)/ -name "*.$(HEADEREXT)")

## release build

all: mkdirp $(LIB_DIR)/libcsv.hpp $(TARGET)

OBJECTS     := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BIN_DIR)/%.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*.$(SRCEXT)"))

$(OBJECTS): $(SOURCES)
	@cd $(SRC_DIR) && $(MAKE)

$(TARGET): $(OBJECTS)
	ar rcs $(TARGET) $(BIN_DIR)/*.$(OBJEXT)

## debug build

dbg: mkdirp $(LIB_DIR)/libcsv.hpp $(DBG_TARGET)

DBG_OBJECTS := $(patsubst $(SRC_DIR)/%.$(SRCEXT), $(BIN_DIR)/%-dbg.$(OBJEXT), $(shell find $(SRC_DIR)/ -name "*.$(SRCEXT)"))

$(DBG_OBJECTS): $(SOURCES)
	@cd $(SRC_DIR) && $(MAKE) dbg

$(DBG_TARGET): $(DBG_OBJECTS)
	ar rcs $(DBG_TARGET) $(BIN_DIR)/*-dbg.$(OBJEXT)

$(LIB_DIR)/libcsv.hpp: $(HEADERS)
	@grep --no-filename -v '^#\s*include\s*"' $(HEADERS) > $(LIB_DIR)/libcsv.hpp
	$(info make $(LIB_DIR)/libcsv.hpp)

## execution

test: $(TARGET) $(TESTSRC)
	@$(CC) $(CPPFLAGS) $(INCLUDE) $(EXAMPLE_DIR)/*.cpp -o $(BIN_DIR)/test $(LIB)
	./$(BIN_DIR)/test

testdbg: $(DBG_TARGET) $(TESTSRC)
	@$(CC) $(CPPDBGFLAGS) $(INCLUDE) $(EXAMPLE_DIR)/*.cpp -o $(BIN_DIR)/test-dbg $(LIB)
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
	@rm -f $(LIB_DIR)/libcsv.hpp
