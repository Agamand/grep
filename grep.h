#ifndef GREP_H

#define GREP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/*
    -- Arguments (structure)
    Structure of arguments : options, pattern and files
    Cf. getArgs()
*/
typedef struct Arguments {
    Maillon* options;
    char* pattern;
    Maillon* files;
} Arguments;

/**
	--FileLine
		Structure of intel concerning the content of a file line by line

		members: 
			-line(char*) : a string containing a line of the file
			-line_index(int) : the index of the line (starting at 1)
			-path(char*) : the path of the file
		
**/
typedef struct FileLine {
    char* line;
    int line_index;
	char* path;
} FileLine;

Arguments* getArgs(int, char**);

char* toLowerCase(char*);

short int optExists(char*, int, char);
short int optIsAdded(Maillon*, char);
short int hasOption(char, Maillon*);
short int isWholeWord(char*, char*, char*);

int listSize(Maillon*);

void addCharToStr(char**, int*, char);
void displayFileLine(Maillon*, int, short);
void displayWithOptions(Maillon*, Arguments*);

Maillon* extractWithPattern(Maillon*, char*, short, short, short);
Maillon* fileLoader(char*);
Maillon* nFileLoader(Arguments*);


#endif



