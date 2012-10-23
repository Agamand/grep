#ifndef _MEMORYMGR_H_
#define _MEMORYMGR_H_

#ifdef _DEBUG_

typedef struct MemBlock
{
	void* ptr;
	unsigned int size;
	char* file;
	int line;
}MemBlock;


typedef struct MemList
{
	MemBlock block;
	struct MemList* next;
}MemList;


void* memorymgr_malloc(unsigned int size, const char* file, int line);
void memorymgr_free(void* ptr);
void memorymgr_showMemLeak();
void memorymgr_log();


static MemList* memList = (MemList*)0;

#define MALLOC(size) memorymgr_malloc(size, __FILE__, __LINE__)
#define FREE(ptr) memorymgr_free(ptr)

#else

#define MALLOC(size,__FILE__,__LINE__) malloc(size)
#define FREE(ptr) free(ptr)

#endif


#endif /*_MEMORYMGR_H_*/