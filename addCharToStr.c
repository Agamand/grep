#include "grep.h"

/**
	--addCharToStr
	Add the character (c), to the string (string) and updates its size (string_size)

	inputs : 
		-string(char *) : the string in which will have the character added
		-string_size(int) : the original size of the string
		-c(char) : the character to add

	output: 
		none
**/
void addCharToStr(char** string, int* string_size, char c)
{
	if (*string_size == 0)
	{
		(*string_size) = 2;
		*string = (char*)malloc(sizeof(char) * (*string_size));
		(*string)[0] = c;
		(*string)[1] = '\0';
	}
	else
	{
		int i;
		char* temp = (char*)malloc(sizeof(char) * ((*string_size) - 1));
		for (i = 0; i < (*string_size) - 1; i++)
		    temp[i] = (*string)[i];

		char* newstring = (char*)malloc(sizeof(char) * ((*string_size) + 1));
		for (i = 0; i < (*string_size) - 1; i++)
		    newstring[i] = temp[i];
		 newstring[(*string_size) - 1] = c;
		 newstring[*string_size] = '\0';
		 
		 *string = newstring;
		 (*string_size) += 1;
	}
}
