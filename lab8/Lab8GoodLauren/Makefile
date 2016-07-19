CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -std=c99 -pedantic -g
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude
LIBDIRS     = -Llib
LIBS        = -lbintree

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/
#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)fileParse.c $(SRCDIR)main.c $(SRCDIR)treeRestaurant.c

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJS    = $(OBJDIR)fileParse.o $(OBJDIR)main.o $(OBJDIR)treeRestaurant.o


#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)lab8runnable


default : labLink
	

labLink: labCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(PROGNAME) $(OBJS) $(LIBS)
	
labCompile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)
	mv *.o $(OBJDIR)
clean:
	@ rm *.o
