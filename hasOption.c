#include "grep.h"

/**
	--hasOption 
		return 1 if the option given in parameter has been entered by the user in console command, 0 if it hasn't

	inputs: 
		options(Maillon*) : the linked list of options given in console command
		c(char) : the option to look for

	output:
		has_option : 1 if the option has been given by the user, 0 if it hasn't
**/
short hasOption(char c, Maillon* options)
{
	Maillon* inter = options;
	while(inter != NULL)
	{
		if(*(char*)inter->data == c)
			return 1;
		inter = inter->next;
	}

	return 0;
}