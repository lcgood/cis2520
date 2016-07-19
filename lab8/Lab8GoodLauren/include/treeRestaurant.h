/*
author: Lauren Good 0871905
project: lab 8
course: cis2520
last modified: July 18,2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeInterface.h"

typedef struct Restaurant 
{
	char * name;
	char * foodType;
	int * rating;
} Restaurant;

extern int maxFloor;
extern int numNodes;

int compareName (void* r1, void* r2);

int compareRating(void* r1, void* r2);

Restaurant* createRestaurant();

void destroyRestaurant();

//1==rating, 2 ==name
Tree* createTree(int type);

void destroyTree(Tree * tree);

void addNode(Tree * tree, Restaurant * data);

void removeNode(Tree * tree, Restaurant * data);

void printNode(void * data);

char * nodeToString(void * data);

void printList(Tree * tree);

//floor 0 is valid. if returned 2: 3 floors including root
int getMaxFloor(Tree * tree, int lastLargest, int current);

int getFloor(Tree * tree, Tree * subtree, int current);

int printTreeRecursive(Tree *tree, int is_left, int offset, int depth, char ** s);//[20][255]);

void printTree(Tree * tree);
