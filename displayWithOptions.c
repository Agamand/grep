#include "grep.h"

/**
	--displayWithOptions
		Generic display options diplaying the results considering the options given in parameter by console command

	inputs: 
		-lines(Maillon*) : a linked list of the resulting FileLines from the inital command
		- args(Arguments*) : a linked list of the arguments given in parameter by console command

**/
void displayWithOptions(Maillon* lines, Arguments* args)
{
	short has_n = hasOption('n', args->options);
	int file_count = listSize(args->files); 
	
	displayFileLine(lines, file_count, has_n);
	
}