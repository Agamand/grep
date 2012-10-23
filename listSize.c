#include "grep.h"

/**
	--listSize 
		return the size of the linked list given in parameter

	inputs : 
		-list(Maillon*) : the linked list to count

	output : 
		-size(short int) : the size of the list given in parameter
**/
int listSize(Maillon* list)
{

	int size = 0;
	while(list != NULL)
	{
		size++;
		list=list->next;
	}

	return size;
}