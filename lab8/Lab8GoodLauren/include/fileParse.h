/*
author: Lauren Good 0871905
project: lab 8
course: cis2520
last modified: July 18,2016
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <math.h>
#include "treeRestaurant.h"

/*
purpose: to get the size of the text file
parameters: name of the file to be read
returns: int the number of entries in the file
*/
int getSize (char* fileName);
/*
purpose: to read the text file and create a 2D array representation
parameters: the file that the maze is stored in, the size of the maze
returns: a list of entries read from the file
*/
Restaurant * parseFile (char* fileName, int size, Restaurant * entriesList);

/*
purpose: to clear the terminal window
parameters: nothing
returns: nothing
*/
void clrscr();