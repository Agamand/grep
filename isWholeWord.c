#include "grep.h"

short isWholeWord(char* line, char* found, char* pattern)
{
	if(*(found) == toLowerCase(line)[0] || *(found-1) == ' ' || *(found-1) == '\'' || *(found-1) == ','|| *(found-1) == '.')
		if(*(found+strlen(pattern)) == ' ' || *(found+strlen(pattern)) == '\'' || *(found+strlen(pattern)) == ','|| *(found+strlen(pattern)) == '.'|| *((found+strlen(pattern))) == '\0'
		|| *(found+strlen(pattern)) == '\n')
			return 1;

	return 0;
}