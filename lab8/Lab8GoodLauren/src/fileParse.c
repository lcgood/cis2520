/*
author: Lauren Good 0871905
project: lab 8
course: cis2520
last modified: July 18,2016
*/
#include "fileParse.h"
int getSize (char * fileName)
{
    FILE * fp;
    int y =0;
    char * buffer;
    buffer = malloc(sizeof(char)*100);
    fp = fopen(fileName,"r");
    if (fp != NULL)
    {
        while(!feof(fp))
        {
            fgets(buffer,100,fp);
            y++;
        }
        fclose(fp);
    }
    free(buffer);
    return y;
}

Restaurant * parseFile (char * fileName,int size, Restaurant * entriesList)
{
    FILE * fp;
    char * buffer = malloc(sizeof(char)*100);
    char * token = "";
    fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }
    else 
    {
        for(int i=0; i< size-1; i++)
        {
            Restaurant * temp = malloc(sizeof(Restaurant));
            fgets(buffer,100,fp);
            token = strtok(buffer,",");
            int length = strlen(token) +1;
            // Malloc Assumes ASCII / UTF8
            temp->name = malloc(sizeof(char)*length);
            strncpy(temp->name, token, length);
            token = strtok(NULL,",");
            length = strlen(token) +1;
            temp->foodType = malloc(sizeof(char)*length);
            strncpy(temp->foodType, token, length);
            temp->rating = malloc(sizeof(int));
            token = strtok(NULL,"\n");
            *(temp->rating) = atoi(token);
            entriesList[i] = *temp;
        }
        fclose(fp);
        free(buffer);
        return entriesList;
    }
}

void clrscr()
{
    system("@cls||clear");
}