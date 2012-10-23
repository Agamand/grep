#include "grep.h"
#include "MemoryMgr/MemoryMgr.h"

char* toLowerCase(char* str)
{
    int i;
	int size = strlen(str);
	char* converted = (char*)MALLOC(sizeof(char)*(size+1));

    for (i = 0; i < size; i++)
    {
        if (str[i] > 64 && str[i] < 91)
            converted[i] = str[i] + 32;
        else
            converted[i] =  str[i];

		converted[size] = '\0';
    }

	return converted;
}