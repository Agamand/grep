#include "grep.h"

/**
	--displayFileLine
		Display the content of each element contained in the list by printing its line index and the line concerned

	inputs: 
		-l(Maillon*) : the linked list containing the elements to display
		-file_count(short int) : the number of files containing the result
		-has_n(shor int) : 1 if the option -n was given in option, 0 if it wasn't

**/
void displayFileLine(Maillon* l, int file_count, short has_n)
{
    Maillon* inter;
    inter = l;
    int i = 1;

	if(has_n)
	{
		if (file_count > 1)
		{
			while (inter != NULL)
			{
				printf("%s: %d: %s\n", ((FileLine*)(inter->data))->path, ((FileLine*)(inter->data))->line_index, ((FileLine*)(inter->data))->line);

				inter = inter->next;
				i++;
			}
		}
		else
		{
			while (inter != NULL)
			{
				printf("%d: %s\n", ((FileLine*)(inter->data))->line_index, ((FileLine*)(inter->data))->line);

				inter = inter->next;
				i++;
			}
		}

	}
	else 
	{
		if (file_count > 1)
		{
			while (inter != NULL)
			{
				printf("%s: %s\n", ((FileLine*)(inter->data))->path, ((FileLine*)(inter->data))->line);
				inter = inter->next;
				i++;
			}
		}
		else
		{
			while (inter != NULL)
			{
				printf("%s\n", ((FileLine*)(inter->data))->path, ((FileLine*)(inter->data))->line);
				inter = inter->next;
				i++;
			}
		}
	}
    if (i == 1)
        printf("The pattern hasn't been found");

    printf("\n");
}
