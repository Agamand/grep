#ifndef LINKEDLIST_H

#define LINKEDLIST_H

    typedef struct Maillon {
        struct Maillon* next;
        void* data;
    } Maillon;

    void addFirst(Maillon**, void*);
    void addEnd(Maillon**, void*);
    void changeMaillon(Maillon*, int, void*);
	void displayFileLine(Maillon*);
	void display(Maillon*);
    void freeList(Maillon**);

#endif
