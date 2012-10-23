#include "dirsearch.h"
#ifdef _WIN32
#include <windows.h>
#include <tchar.h> 
#else
#include <sys/types.h>
#include <dirent.h>
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MemoryMgr/MemoryMgr.h"

void getFileFrom(const char* dir, Maillon** fileList)
{
	int size = strlen(dir);
	char* dir_search = (char*)MALLOC((size+3)*sizeof(char));
	strncpy(dir_search,dir,size);
	dir_search[size] = '/';
	dir_search[size+1] = '*';
	dir_search[size+2] = 0;

#ifdef _WIN32
	WIN32_FIND_DATA findData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	hFind = FindFirstFile(dir_search, &findData);

	if (hFind == INVALID_HANDLE_VALUE) 
	{
		return;
	}

	do
	{
		if(!strcmp(findData.cFileName,".") || !strcmp(findData.cFileName,".."))
			continue;

		int size_next = size+strlen(findData.cFileName)+2;
		char* next = (char*)MALLOC(size_next*sizeof(char*));
		strncpy(next,dir,size);
		next[size] = '/';
		strncpy(next+size+1,findData.cFileName,size_next-size-1);

		if(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			getFileFrom(next,fileList);
			FREE(next);
		}
		else
		{
			addEnd(fileList,next);
		}
	}
	while(FindNextFile(hFind,&findData) != 0);

#else
  DIR           *d;
  struct dirent *_dir;
  d = opendir(dir);
  if (d)
  {
    while ((_dir = readdir(d)) != NULL)
    {
		if(!strcmp(_dir->d_name,".") || !strcmp(_dir->d_name,".."))
			continue;

		int size_next = size+strlen(_dir->d_name)+2;
		char* next = (char*)MALLOC(size_next*sizeof(char*));
		strncpy(next,dir,size);
		next[size] = '/';
		strncpy(next+size+1,_dir->d_name,size_next-size-1);
					
		
		if(_dir->d_type & DT_DIR)
		{
			getFileFrom(next,fileList);
			FREE(next);
		}
		else
		{
			addEnd(fileList,next);
		}
    }

    closedir(d);
  }

#endif
  FREE(dir_search);

}