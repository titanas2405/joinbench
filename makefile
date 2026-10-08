#Options for compiling

	CC       = gcc

	#O3 for most optimization. Code base is small
	#so compile time is not an issue
	
	CFLAGS   = -Wall -Wextra  -O3
	CPPFLAGS = -Iinclude

#Where should the dependency rules be stored

	DEPDIR := .deps

#Options for dependency
# -MD option is euivilent to -M -MF but -MF 
#  this writes to a file specified
# -MP option to add phony target for 
#  each dependency other than the main file 

	DEPFLAGS = -MD -MP -MF $(DEPDIR)/$*.d 

#Getting all the source files

	SRCS = $(wildcard src/*.c src/*/*.c)

#Using % to change the file to build file

	OBJS = $(SRCS:src/%.c=build/%.o)

#To run we need the build folder and the main file

run: build main 
	./build/main

#We are using the -p to not fail when we try to create a folder that exists

build:	
	mkdir -p ./build

# For main to work we need all the object files and we compile them into
#one file ./build/main

main: $(OBJS)
	$(CC) -o ./build/main $^

# Compile for c using the cc the dep flags the c flags and cpp flags 

COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

#Cancel rule before writing our own

build/%.o : src/%.c

#It is needed first to make the directory for dependencies that is why we have
# |$(DEPDIR). To do it first
#For every compiled file it is needed to have the corresponding source file.
#We make sure that  $(DEPDIR)/%.d file is tracked
#Then we compile the file

build/%.o : src/%.c $(DEPDIR)/%.d | $(DEPDIR)
	@mkdir -p $(dir $@) $(dir $(DEPDIR)/$*.d)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

#Clean by removing contents of ./build

clean:
	rm -rf ./build/*

#Create the dependecy folder
$(DEPDIR): 
	@mkdir -p $@


#Getting all the dependecy files from src files
DEPFILES := $(SRCS:src/%.c=$(DEPDIR)/%.d)

#Cancel any previous rules for every depndency file
$(DEPFILES):


#include all the dependencies
include $(wildcard $(DEPFILES))
