#include "grep.h"

/**
	--extractWithPattern
		Search a string pattern in a list of strings
	
	inputs: 
		-lines(Maillon*) : the list of strings
		-pattern(char*) : the search pattern

	output: 
		-containing_pattern(FileLine*) : linked list of Fileline containing each line(String) and its index(int) for each line containing the pattern
**/
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
			if (!has_i)
			{	
				if(!has_w)
				{
					if(strstr(((FileLine*)(current_line->data))->line, pattern) != NULL)
					{
						addEnd(&containing_result, current_line->data);
					}
				}
				else
					if((found = strstr(((FileLine*)(current_line->data))->line, pattern)) != NULL)
					{
						if(isWholeWord(((FileLine*)(current_line->data))->line, found, pattern))
								addEnd(&containing_result, current_line->data);
					}
			}
			else
			{
				if(!has_w)
				{
					if(strstr(toLowerCase(((FileLine*)(current_line->data))->line), toLowerCase(pattern)) != NULL)
					{
						addEnd(&containing_result, current_line->data);
					}
				}
				else
					if((found = strstr(toLowerCase(((FileLine*)(current_line->data))->line), toLowerCase(pattern))) != NULL)
					{
						if(isWholeWord(toLowerCase(((FileLine*)(current_line->data))->line), found, pattern))
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
				if (!has_i)
				{	
					if(strstr(((FileLine*)(current_line->data))->line, pattern) == NULL)
					{
						addEnd(&containing_result, current_line->data);
					}
				}
				else
				{
					if(strstr(toLowerCase(((FileLine*)(current_line->data))->line), toLowerCase(pattern)) == NULL)
					{
						addEnd(&containing_result, current_line->data);
					}
				}
			}
			else
			{
				if (!has_i)
				{	

					if(strstr(((FileLine*)(current_line->data))->line, pattern) == NULL)
					{
						addEnd(&containing_result, current_line->data);
					}
					else if(strstr(((FileLine*)(current_line->data))->line, pattern) != NULL)
					{
						if(!isWholeWord(((FileLine*)(current_line->data))->line, found, pattern))
								addEnd(&containing_result, current_line->data);
					}
				}
				else
				{
					if(strstr(toLowerCase(((FileLine*)(current_line->data))->line), toLowerCase(pattern)) == NULL)
					{
						addEnd(&containing_result, current_line->data);
					}
					else if((found = strstr(toLowerCase(((FileLine*)(current_line->data))->line), toLowerCase(pattern))) != NULL)
					{
							if(!isWholeWord(toLowerCase(((FileLine*)(current_line->data))->line), found, pattern))
								addEnd(&containing_result, current_line->data);
					}
				}
			}

			current_line = current_line->next;
		}
	}

	return containing_result;
}
