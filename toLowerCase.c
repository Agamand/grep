#include "grep.h"
#include "MemoryMgr/MemoryMgr.h"

char* toLowerCase(char* str)
{
    int i;

	char* converted = (char*)MALLOC(sizeof(char)*strlen(str));

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] > 64 && str[i] < 91)
            converted[i] = str[i] + 32;
        else
            converted[i] =  str[i];

		converted[strlen(str)] = '\0';
    }

	return converted;
}