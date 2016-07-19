/*
author: Lauren Good 0871905
project: lab 8
course: cis2520
last modified: July 18,2016
*/
#include "treeRestaurant.h"

int maxFloor = 0;
int numNodes = 0;

int compareName (void* r1, void* r2) 
{
	if(r1 == NULL || r2 == NULL) return 0;
	return strcmp(((Restaurant*)r1)->name,((Restaurant*)r2)->name);
}

int compareRating (void* r1, void* r2)
{

	if(r1 == NULL || r2 == NULL) return 0;
	if(*((Restaurant*)r1)->rating == *((Restaurant*)r2)->rating) return 0;
	else if (*((Restaurant*)r1)->rating > *((Restaurant*)r2)->rating) return 1;
	else return -1;
}

Restaurant* createRestaurant(int rating, char * name, char * foodType)
{
	Restaurant * newRestaurant = malloc(sizeof(Restaurant));
	newRestaurant->name = malloc(sizeof(char)*(strlen(name)));
	strcpy(newRestaurant->name,name);
	newRestaurant->foodType = malloc(sizeof(char)*(strlen(foodType)));
	strcpy(newRestaurant->foodType,foodType);
	*newRestaurant->rating = rating;
	return(newRestaurant);
}

void destroyRestaurant(void * toDelete)
{
	if(toDelete != NULL)
	{
		Restaurant * temp = (Restaurant*)toDelete;
		printf("%s\n",temp->name);
		free(temp->name);
		free(temp->foodType);
		free(temp->rating);
		free(temp);
	}
}

//type == 1: rating. type ==2 name
Tree* createTree(int type)
{
	if(type == 1) return createBinTree(&compareRating, &destroyRestaurant);
	else if(type == 2) return createBinTree(&compareName, &destroyRestaurant);
	else return NULL;
}

void addNode(Tree * tree, Restaurant * data)
{
	if(tree != NULL && data != NULL)
	{
		addToTree(tree, data);
		numNodes ++;
	}	
}

void removeNode(Tree * tree, Restaurant * data)
{
	removeFromTree(tree, &data);
	numNodes --;
}

void printNode(void * data)
{
	Restaurant * temp = (Restaurant*) data;
	printf("%s(%d)\n",temp->name, *temp->rating);
}

char * nodeToString(void * data)
{
	char * string = malloc(sizeof(char)*80);
	Restaurant * temp = (Restaurant*) data;
	sprintf(string,"%s(%d)",temp->name, *temp->rating);
	return string;
}

void printList(Tree * tree)
{
	if(!isTreeEmpty(tree)) printInOrder(tree, &printNode);
}

int getMaxFloor(Tree * tree, int lastLargest, int current)
{
	Tree * left = getLeftSubtree(tree);
	Tree * right = getRightSubtree(tree);
	if(current > lastLargest) lastLargest = current;
	if(right != NULL) lastLargest = getMaxFloor(right, lastLargest,current+1);
	if(left != NULL) lastLargest = getMaxFloor(left, lastLargest,current+1);
	free(left);
	free(right);
	return lastLargest;
}

int getFloor(Tree * tree, Tree * subtree, int current)
{
	int foundFloor;
	if(tree == subtree) foundFloor = current;
	else if(getRightSubtree(tree) != NULL)foundFloor = getFloor(getRightSubtree(tree), subtree, current+1);
	else if(getLeftSubtree(tree) != NULL)foundFloor = getFloor(getLeftSubtree(tree), subtree, current+1);
	return foundFloor;
}

int printTreeRecursive(Tree * tree, int is_left, int offset, int level, char** s)//[20][255])
{
    char buffer[20];
    int width = 20;
    char * nodeTempStr;
    Tree * leftTree;
    Tree * rightTree;
    if(tree && !isTreeEmpty(tree))
    {
    	nodeTempStr = nodeToString(getRootData(tree));
    	leftTree = getLeftSubtree(tree);
    	rightTree = getRightSubtree(tree);
        sprintf(buffer, "%20s",nodeTempStr);
	    int left  = printTreeRecursive(leftTree, 1, offset, level + 1, s);
	    int right = printTreeRecursive(rightTree, 0, offset + left + width, level + 1, s);
	    for (int i = 0; i < width; i++)
        {
	        s[2 * level][offset + left + i] = buffer[i];
        }

	    if (level && is_left) {
	        for (int i = 0; i < width + right; i++)
	        {
	            s[2 * level - 1][offset + left + width/2 + i] = '_';
	        }

	        s[2 * level - 1][offset + left + width/2] = '+';
	        s[2 * level - 1][offset + left + width + right + width/2] = '+';

	    } else if (level && !is_left) {
	        for (int i = 0; i < left + width; i++)
	        {
	            s[2 * level - 1][offset - width/2 + i] = '_';
	        }

	        s[2 * level - 1][offset + left + width/2] = '+';
	        s[2 * level - 1][offset - width/2 - 1] = '+';
	    }
	    free(nodeTempStr);
	    free(leftTree);
	    free(rightTree);
    return left + width + right;
   } else return 0;
}

void printTree(Tree * tree)
{
    // need twice the height because of the child/parent lines
    int maxHeight = getMaxFloor(tree,0,0)*2 +1;
    char ** string = malloc(sizeof(char*)*maxHeight);
    for (int i = 0; i < maxHeight; i++)
    {
        string[i] = malloc(sizeof(char)*255);
        sprintf(string[i], "%80s", " ");
    }

    printTreeRecursive(tree, 0, 0, 0, string);

    for (int i = 0; i < maxHeight; i++)
    {
        printf("%s\n", string[i]);
        free(string[i]);
    }
    free(string);
}
