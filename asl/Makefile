# =================================================
#	@(#)makefile	1.3		AKK/ACT		20170507
#	@(#)makefile	1.2		AKK/ACT		20170329
# =================================================
#    This makefile assumes all files in this
#  directory belong to the one and only program.
# It also assumes you only have one grammar file.
# =================================================

# ----------
# VARIABLES
# ----------

# Adjust these lines according to your project

# The name to give to the program, e.g. main
PROGRAM		:= asl

# If you want the generated files to be in
# for instance the 'gen' subdirectory, then
# define the name of the additional directory here
#GENDIR		:= gen
# otherwise, put a '#' character in front of the
# line to turn it into comment.

# If you want your own sources to be in
# for instance the 'src' subdirectory, then
# define the name of the additional directory here
#SRCDIR		:= src
SRCDIR		:= ../common
# otherwise, put a '#' character in front of the
# line to turn it into comment.

# Define the name of your grammar.
# Can be done in two ways:
# 1a. Let 'make' figure out the name of the file
GRAMMAR.g4	:= $(wildcard *.g4)
# 1b. Or tell it yourself if there are more of them
#GRAMMAR.g4	:= Shell.g4

# The target language is C++
ANTLR4FLAGS := -Dlanguage=Cpp
# Note: By default the language would be Java

# Some more antlr4 options:
# Add or remove a leading '#' to disable or enable.
# Do not generate Visitor classes
ANTLR4FLAGS += -no-visitor
# Do generate Visitor classes
#ANTLR4FLAGS += -visitor
# Do not generate Listener classes
#ANTLR4FLAGS += -no-listener
# Do generate Listener classes
ANTLR4FLAGS += -listener


# The default target to make is:
#  1) give some help
#DEFAULT 	:= help
#  2) or make your program
DEFAULT 	:= $(PROGRAM)
# Select either alternative above


# ---------------------------------------------------------------
# Changes below this line are rarely needed.
# ---------------------------------------------------------------

# ==== ANTLR4 stuff ====

# This lets 'make' derive the base name of that grammar
GRAMMAR 	:= $(GRAMMAR.g4:.g4=)

# If GENDIR was defined then this tells antlr4 that
# it should place the generated files there.
ifneq ($(strip $(GENDIR) ),)
ANTLR4FLAGS += -o $(GENDIR)
endif

# The root directory of your antlr4 runtime is ...
ANTLR_ROOT := /usr/local

# Where to find various parts of the runtime files
INCDIR		:= $(ANTLR_ROOT)/include/antlr4-runtime/
LIBDIR		:= $(ANTLR_ROOT)/lib/
BINDIR		:= $(ANTLR_ROOT)/bin
ANTLR4		:= $(BINDIR)/antlr4

# The minimal set of generated files needed for any grammar.
ifneq ($(strip $(GENDIR) ),)	# if GENDIR was defined
NEEDED.h	:= $(GENDIR)/$(GRAMMAR)Lexer.h   $(GENDIR)/$(GRAMMAR)Parser.h
NEEDED.cpp	:= $(GENDIR)/$(GRAMMAR)Lexer.cpp $(GENDIR)/$(GRAMMAR)Parser.cpp
else
NEEDED.h	:= $(GRAMMAR)Lexer.h   $(GRAMMAR)Parser.h
NEEDED.cpp	:= $(GRAMMAR)Lexer.cpp $(GRAMMAR)Parser.cpp
endif

# Make a list of all the needed source files
NEEDED		:= $(NEEDED.h) $(NEEDED.cpp)
# And all the object files generated from them
NEEDED.o	:= $(NEEDED.cpp:.cpp=.o)

# ==== MAKE stuff ====

# Wildcard definitions to generate lists of file names
# existing in this directory

# Available source files here are ...
ifneq ($(strip $(SRCDIR) ),)	# if SRCDIR was defined
HEADERS		= $(wildcard $(SRCDIR)/*.h ./*.h)
SOURCE.c	= $(wildcard $(SRCDIR)/*.c ./*.c)
SOURCE.cc	= $(wildcard $(SRCDIR)/*.cc ./*.cc)
SOURCE.cpp	= $(wildcard $(SRCDIR)/*.cpp ./*.cpp)
else
HEADERS		= $(wildcard *.h)
SOURCE.c	= $(wildcard *.c)
SOURCE.cc	= $(wildcard *.cc)
SOURCE.cpp	= $(wildcard *.cpp)
endif

ifneq ($(strip $(GENDIR) ),)	# if GENDIR was defined
# also add those in that subdirectory
HEADERS		+= $(wildcard $(GENDIR)/*.h)
SOURCE.cpp	+= $(wildcard $(GENDIR)/*.cpp)
endif

# List of all the currently available source files
SOURCES		= $(SOURCE.c) $(SOURCE.cc) $(SOURCE.cpp)
# And all the object files generated from them
OBJECTS		= $(SOURCE.c:.c=.o) $(SOURCE.cc:.cc=.o) $(SOURCE.cpp:.cpp=.o)

# ==== C++ stuff ====

# Which compiler we are going to use
CCC	= g++-5
CXX	= g++-5
CC 	= g++-5

# Tell compiler:
# ... where to search for additional header files ...
ifneq ($(strip $(SRCDIR) ),)	# if SRCDIR was defined
#  ... our own headers files
CPPFLAGS += -I. -I$(SRCDIR)
endif
ifneq ($(strip $(GENDIR) ),)
#  ... antlr4 generated header files
CPPFLAGS += -I$(GENDIR)
endif
#  ... the antlr4 runtime files
CPPFLAGS += -I$(INCDIR)
# ... select the C++ version desired,
CPPFLAGS += --std=c++11
# ... enable various warnings,
CPPFLAGS += -Wall -Wextra
# ... but disable this one,
CPPFLAGS += -Wno-unused-parameter
# ... always add extra debugging information for gdb.
#CPPFLAGS += -g


# Tell the compiler to link the antlr4 runtime library to the program
LDLIBS	+= -L$(LIBDIR) -lantlr4-runtime


# Which generated files really *do* exist (e.g. for clean-up)
ifneq ($(strip $(GENDIR) ),)	# if GENDIR was defined
GENERATED	:= $(wildcard $(GENDIR)/$(GRAMMAR)*.h) \
			   $(wildcard $(GENDIR)/$(GRAMMAR)*.cpp) \
			   $(wildcard $(GENDIR)/$(GRAMMAR)*.interp) \
			   $(wildcard $(GENDIR)/$(GRAMMAR)*.tokens)
TOKENS		:= $(wildcard $(GENDIR)/$(GRAMMAR)*.tokens)
else
GENERATED	:= $(wildcard $(GRAMMAR)*.h) \
			   $(wildcard $(GRAMMAR)*.cpp) \
			   $(wildcard $(GRAMMAR)*.interp) \
			   $(wildcard $(GRAMMAR)*.tokens)
TOKENS		:= $(wildcard $(GRAMMAR)*.tokens)
endif

# ---------------------------------------------------------------
# MAKE TARGETS
# ---------------------------------------------------------------

# list of 'targets' that are not real files at all
.PHONY:	DEFAULT help antlr clean realclean pristine

# The default target tells the user about the available targets.
DEFAULT		: $(DEFAULT)

# Give some help
help		:
	@echo "The targets to make are:"
	@echo "  make antlr		: the files generated by antlr"
	@echo "  make $(PROGRAM)		: the desired program"
#	@echo "  make debug		: a version of the program with"
#	@echo "			  extra information for the debugger"
	@echo "	Note: The 'make' tool can not know what files will"
	@echo "	be generated by antlr, therefore you must do"
	@echo "	    make antlr"
	@echo "	at least once before trying to make your program"
	@echo "For clean-up there are three more targets:"
	@echo "  make clean		: remove .o files"
	@echo "  make realclean	: also remove the generated files"
	@echo "  make pristine		: also remove the program"


# A pseudo target to force generating needed files
antlr		: $(NEEDED)


# How to make the 'main' program.
$(PROGRAM)	: $(TOKENS) $(OBJECTS)
	$(LINK.cc) -o $@ $(OBJECTS) $(LDLIBS)

# Special 'debug' target
debug		: $(OBJECTS) $(PROGRAM)
debug		: CPPFLAGS += -g


# Various pseudo-targets to clean up things.
clean		:
	-rm -f $(OBJECTS)
realclean	: clean				# if there are any generated files
ifneq ($(strip $(GENERATED) ),)
	-rm -rf $(GENERATED)
endif
pristine	: realclean
	-rm -rf $(PROGRAM) _antlr _deps

# -------------------------------------------

# How to make or update the generated files
$(NEEDED)		 	: $(GRAMMAR).g4
	@echo "## Creating the antlr generated files"
	$(ANTLR4) $(ANTLR4FLAGS) $(GRAMMAR).g4
$(TOKENS)			:
	@echo "## You should first do: make antlr"; exit 1

# ----------------------------------------------------

# Generate dependencies for all generated antlr4 files
_antlr		: $(GRAMMAR).g4
	@echo "## Updating the list of grammar dependent files"
	$(ANTLR4) -depend $(ANTLR4FLAGS) $(GRAMMAR).g4 > _antlr

# IFF we have any, then ...
ifneq ($(strip $(GENERATED) ),)
-include _antlr
endif

# IFF we have some generated files then also ...
ifneq ($(strip $(GENERATED) ),)
# Determine dependencies between all sources files
_deps		: $(HEADERS) $(SOURCES)
	@echo "## Updating the _deps dependency file"
	$(CXX) -MM $(CPPFLAGS) $(SOURCES) > _deps
-include _deps
endif

# =================================================
# Changelog:
# 2017707	- now supports having the userss source
#			  files in a separate 'src' subdirectory
# 20170329	- now supports having the generated
#			  antlr4 files in a subdirectory
#			- now 'include' is silent
#		  	- move some comments more verbose
#			- added an experimental 'debug' target
# =================================================
