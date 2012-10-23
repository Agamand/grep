#ifdef _DEBUG_

#include "MemoryMgr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

MemList* new_MemList(unsigned int size, const char* file, int line)
{
	MemList* list = (MemList*)malloc(sizeof(MemList));
	int size_file = strlen(file);
	list->block.file = (char*)malloc(sizeof(char)*(size_file+1));
	strncpy(list->block.file,file,size_file+1);
	list->block.line = line;
	list->block.ptr = NULL;
	list->block.size = size;
	list->next = NULL;
	return list;
}

void delete_MemList(MemList* list)
{
	free(list->block.file);
	free(list);
}

void* memorymgr_malloc(unsigned int size, const char* file, int line)
{
	void* ptr = malloc(size);
	if(!memList)
	{
		memList = new_MemList(size,file,line);
		memList->block.ptr = ptr;
	}
	else
	{
		MemList* list = new_MemList(size,file,line);
		list->block.ptr = ptr;
		list->next = memList;
		memList = list;
	}

	return ptr;
}
void memorymgr_free(void* ptr)
{
	if(!memList)
		return;

	MemList* next = memList;
	MemList* previous = NULL;
	while(next != NULL)
	{
		if(next->block.ptr == ptr)
		{
			free(ptr);
			if(previous)
				previous->next = next->next;
			else memList = next->next;
			delete_MemList(next);
			break;
		}
		previous = next;
		next = next->next;
	}
}
void memorymgr_showMemLeak()
{
	int count = 0;
	MemList* next = memList;


	printf("  =============================================  \n");
	printf("               Memory leak tracker               \n");  
	printf("  =============================================  \n");

	while(next)
	{
		printf("0x%p -- size : %d -- %s:%d\n",next->block.ptr,next->block.size,next->block.file,next->block.line);
		count++;
		next = next->next;
	}

	printf("  =============================================  \n");
	if(count)
	{
		printf("              %d leak detected !\n",count);
	}
	else
	{
		printf("              No leak detected !");
	}
	printf("  =============================================  \n");
}
void memorymgr_log()
{
	FILE* file = fopen("memoryLeak.log","w");
	if(!file)
		return;

	int count = 0;
	MemList* next = memList;


	fprintf(file,"  =============================================  \n");
	fprintf(file,"               Memory leak tracker               \n");  
	fprintf(file,"  =============================================  \n");

	while(next)
	{
		fprintf(file,"0x%p -- size : %d -- %s:%d\n",next->block.ptr,next->block.size,next->block.file,next->block.line);
		count++;
		next = next->next;
	}

	fprintf(file,"  =============================================  \n");
	if(count)
	{
		fprintf(file,"              %d leak detected !\n",count);
	}
	else
	{
		fprintf(file,"              No leak detected !");
	}
	fprintf(file,"  =============================================  \n");

	fclose(file);
}
#endif