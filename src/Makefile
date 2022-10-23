SRCEXT      := cpp
OBJEXT      := o
HEADEREXT   := hpp

# directories

SRC_DIR     := ../src
BUILD_DIR   := ../build
BIN_DIR     := ../bin
LIB_DIR     := ../lib
TEST_DIR    := ../tests
INCLUDE_DIR := ../include

# compiler options

CC          := clang++ $(WALL)
CPPFLAGS    := -Ofast
CPPDBGFLAGS := -g -ggdb -D DEBUG
DBG         := gdb -q

INCLUDE     := -I $(INCLUDE_DIR)

## release build

OBJECTS     := $(patsubst %.$(SRCEXT), %.$(OBJEXT), $(wildcard *.$(SRCEXT)))

all: mkdirp $(OBJECTS) cpobj

%.$(OBJEXT): %.$(SRCEXT)
	$(CC) $(CPPFLAGS) $(INCLUDE) -c -o $@ $<

## debug build

DBG_OBJECTS := $(patsubst %.$(SRCEXT), %-dbg.$(OBJEXT), $(wildcard *.$(SRCEXT)))

dbg: mkdirp $(DBG_OBJECTS) cpobj

%-dbg.$(OBJEXT): %.$(SRCEXT)
	$(CC) $(CPPDBGFLAGS) $(INCLUDE) -c -o $@ $<

cpobj:
	@cp *.$(OBJEXT) $(BUILD_DIR)

mkdirp:
	@mkdir -p $(BUILD_DIR)/

clean:
	@rm -f *.$(OBJEXT)

cleaner: clean
	@rm -f $(BUILD_DIR)/*.$(OBJEXT)
