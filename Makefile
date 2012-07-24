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
QUIET_CC	= @echo '    ' CC $@;

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
CXX	     = g++
CXXFLAGS = 	-g -std=c++98 -pedantic-errors -Wall -Werror \
			-L$(LEDAROOT) -I$(LEDAROOT)/incl -lleda -lX11 -lm

###############################################################################
# Targets
###############################################################################

TARGETS = leda_test leda_rational leda_random leda_locate_points

all: $(TARGETS)

clean:
	@rm -f $(TARGETS) *.node *.ele