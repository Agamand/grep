#include "grep.h"

/**
	--fileLoader
		Load the content of a file and returns a linked list of its content
	
	inputs: 
		-filename(char*) : the path of the file to load

	output:
		-lines(FileLine*) : a linked list of FileLine containing each line(String), its index(int), and the path of the file containing the line(char*)
**/
Maillon* fileLoader(char* filename)
{
	FILE* ref_file;
	ref_file = fopen(filename, "rt");
	if (ref_file == NULL) // If the file does not exist or can't be opened
	{
		printf("Fichier introuvable\n");
		return NULL;
	}
	else
	{
		char c;
		char* buffer = NULL;
		int buffer_size = 0;
		int line_count = 1;
		int i;
		Maillon* lines = NULL;
		FileLine* c_file_line = (FileLine*)malloc(sizeof(FileLine));

		while (fread(&c, sizeof(char), 1, ref_file), !feof(ref_file))
			if(c == '\n')
				line_count++;

		fseek(ref_file, 0, SEEK_SET);
		
		for (i = 0; i < line_count; i++)
		{
			int buffer_size = 0;
			while (fread(&c, sizeof(char), 1, ref_file), !feof(ref_file) && c != '\n')
			{
				addCharToStr(&buffer, &buffer_size, c);
			}

			c_file_line = (FileLine*)malloc(sizeof(FileLine));
			c_file_line->line = buffer;
			c_file_line->line_index = i + 1;
			c_file_line->path = filename;


			addEnd(&lines, c_file_line);
		}

		return lines;
	}
}

/**
	--nFilesLoader
		Load the content of numerous files and returns a linked list of their content
	
	inputs: 
		-args(Arguments*) : a linked list of Arguments containing all the arguments given by console command

	output:
		-lines(FileLine*) : a linked list of FileLine containing each line(String), its index(int), and the path of the file containing the line(char*)
**/
Maillon* nFileLoader(Arguments* args)
{
	Maillon* temp = NULL;
	Maillon* inter = args->files;
	Maillon* lines = NULL;

	while(inter != NULL)
	{
		temp = fileLoader((char*)inter->data);
		while(temp != NULL)
		{
			addEnd(&lines, temp->data);
			temp = temp->next;
		}
		inter = inter->next;
	}
	return lines;
}
