###############################################################################
#                       Copyright (c) 2012 by
#                               Simon Pratt
#                         (All rights reserved)
###############################################################################
# Makefile for the LEDA Point Location project
###############################################################################

# don't use built in targets
makepp_no_builtin = 1

###############################################################################
# Quiet Compile
###############################################################################
QUIET_CC	=
# comment next line for verbose compile
#QUIET_CC	= @echo '    ' CC $@;

%.o: %.cpp
	$(QUIET_CC)$(COMPILE.cpp) $(OUTPUT_OPTION) $<

%: %.cpp
	$(QUIET_CC)$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

###############################################################################
# Makefile Configuration
###############################################################################

.PHONY: all clean

###############################################################################
# Compiler Configuration
###############################################################################

LEDAROOT = /home2bak/spratt/Projects/PrioritySearchTree/LEDA/6.3-x64
LD_LIBRARY_PATH = $(LD_LIBRARY_PATH):$(LEDAROOT)
CXX	     = g++
CXXFLAGS = 	-g -std=c++98 -pedantic-errors -Wall -Werror \
			-L$(LEDAROOT) -I$(LEDAROOT)/incl -lleda -lX11 -lm

###############################################################################
# Targets
###############################################################################

all: leda_test

leda_test: leda_test.cpp

clean:
	@rm -f leda_test