SRCEXT      := cpp
OBJEXT      := o
HEADEREXT   := hpp

# directories

SRC_DIR     := ../src
BIN_DIR     := ../bin
LIB_DIR     := ../lib
EXAMPLE_DIR := ../examples
INCLUDE_DIR := ../include

# compiler options

CC          := clang++ $(WALL)
CPPFLAGS    := -Ofast
CPPDBGFLAGS := -g -ggdb

INCLUDE     := -I $(INCLUDE_DIR) -I $(LIB_DIR)

OBJECTS     := $(patsubst %.$(SRCEXT), %.$(OBJEXT), $(wildcard *.$(SRCEXT)))

## release build

all: mkdirp $(OBJECTS) cpobj

%.$(OBJEXT): %.$(SRCEXT)
	$(CC) $(CPPFLAGS) $(INCLUDE) -c -o $@ $<

## debug build

DBG_OBJECTS := $(pathsubst %.$(SRCEXT), %-dbg.$(OBJEXT), $(wildcard *.$(SRCEXT)))

dbg: mkdirp $(DBG_OBJECTS) cpobj

%-dbg.$(OBJEXT): %.$(SRCEXT)
	$(CC) $(CPPDBGFLAGS) $(INCLUDE) -c -o $@ $<

cpobj:
	@cp *.$(OBJEXT) $(BIN_DIR)

mkdirp:
	@mkdir -p $(BIN_DIR)

clean:
	@rm -f *.$(OBJEXT)

cleaner: clean
	@rm -f $(BIN_DIR)/*.$(OBJEXT)
