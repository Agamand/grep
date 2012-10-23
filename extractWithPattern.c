#include "grep.h"
#include "MemoryMgr/MemoryMgr.h"
/**
	--extractWithPattern
		Search a string pattern in a list of strings
	
	inputs: 
		-lines(Maillon*) : the list of strings
		-pattern(char*) : the search pattern

	output: 
		-containing_pattern(FileLine*) : linked list of Fileline containing each line(String) and its index(int) for each line containing the pattern
**/

char* strstr_with(char* _str, char* _substr ,short nocheckCase)
{
	if(nocheckCase)
	{
		char* str_low = toLowerCase(_str);
		char* substr_low = toLowerCase(_substr);
		char* result = strstr(str_low,substr_low);
		FREE(str_low);
		FREE(substr_low);
		return result;
	}
	else
	{
		return strstr(_str,_substr);
	}
}

Maillon* extractWithPattern(Maillon* lines, char* pattern, short has_i, short has_w, short has_v)
{
	Maillon* current_line;
	Maillon* containing_result = NULL;
    current_line = lines;
	char* found = NULL;

	if (!has_v)
	{
		while (current_line != NULL) 
		{
			if(!has_w)
			{
				if(strstr_with(((FileLine*)(current_line->data))->line, pattern,has_i) != NULL)
				{
					addEnd(&containing_result, current_line->data);
				}
			}
			else
			{
				if((found = strstr_with(((FileLine*)(current_line->data))->line, pattern,has_i)) != NULL)
				{
					if(isWholeWord(((FileLine*)(current_line->data))->line, found, pattern))
							addEnd(&containing_result, current_line->data);
				}
			}
			current_line = current_line->next;
		}
	}
	else
	{
		while (current_line != NULL) 
		{
			if(!has_w)
			{	
				if(strstr_with(((FileLine*)(current_line->data))->line, pattern,has_i) == NULL)
				{
					addEnd(&containing_result, current_line->data);
				}
			}
			else
			{
				if(strstr_with(((FileLine*)(current_line->data))->line, pattern,has_i) == NULL)
				{
					addEnd(&containing_result, current_line->data);
				}
				else if((found = strstr_with(((FileLine*)(current_line->data))->line, pattern,has_i)) != NULL)
				{
						if(!isWholeWord(toLowerCase(((FileLine*)(current_line->data))->line), found, pattern))
							addEnd(&containing_result, current_line->data);
				}
			}

			current_line = current_line->next;
		}
	}

	return containing_result;
}
