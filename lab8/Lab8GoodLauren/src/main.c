/*
author: Lauren Good 0871905
project: lab 8
course: cis2520
last modified: July 18,2016
*/
#include "fileParse.h"

void deleteList(Restaurant * list, int length)
{
	for(int i=0; i< length-1; i++)
	{
		free(list[i].name);
		free(list[i].rating);
		free(list[i].foodType);
	}
	free(list);
}

void printEntries(Restaurant * head, int length)
{
	for(int i=0; i< length-1; i++)
	{
		printf("Name: %s\tFoodType: %s\tRating: %d\n", head[i].name, head[i].foodType, *head[i].rating);
	}
}

int main(int argc, char ** argv)
{
	if(argc < 2) printf("Invalid number of arguments\n");
	else
	{
		int fileLength = getSize(argv[1]);
		Restaurant * entriesList = malloc(sizeof(Restaurant) * fileLength-1);
		for(int i=0; i<fileLength-1; i++)
		{
			entriesList[i].name = NULL;
			entriesList[i].foodType = NULL;
			entriesList[i].rating = NULL;
		}
		entriesList = parseFile(argv[1],fileLength-1,entriesList);
		printEntries(entriesList, fileLength-1);
		Tree * ratingTree = createTree(1);
		unsigned char *temp = (unsigned char*) ratingTree;
		Tree * nameTree = createTree(2);
		unsigned char *temp2 = (unsigned char*) nameTree;
		for(int i=0; i<8; i++)
		{
			*(temp+i) = 0;
			*(temp2+i) = 0;
		}
		//populate trees
		for(int i=0; i<fileLength-2;i++)
		{
			addNode(ratingTree,&entriesList[i]);
			addNode(nameTree,&entriesList[i]);
		}
		printf("Rating Tree\n");
		printList(ratingTree);
		printf("\n\nName Tree\n");
		printList(nameTree);

		printf("max floors: %d\n", getMaxFloor(nameTree,0,0));
		printf("get floor: %d\n",getFloor(nameTree,nameTree,0));

		printf("Tree:\n");
		printTree(nameTree);
		printTree(ratingTree);
		//destroyBinTree(ratingTree);
		//destroyBinTree(nameTree);
		deleteList(entriesList,fileLength-1);
		free(nameTree);
		free(ratingTree);
	}
	return 0;
}