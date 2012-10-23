#include <stdlib.h>

#include "linkedList.h"

void addFirst(Maillon** l, void* data)
{
    Maillon* newMa;
        newMa = NULL;

    newMa = (Maillon*)malloc(sizeof(Maillon));
    if (newMa == NULL)
        return;

    newMa->data = data;
    newMa->next = *l;
    *l = newMa;
}

void addEnd(Maillon** l, void* data)
{
    Maillon* newMa;
        newMa = NULL;
	Maillon* lastMaillon;
		lastMaillon = *l;

    newMa = (Maillon*)malloc(sizeof(Maillon));
    if (newMa == NULL)
        return;

	newMa->data = data;
	newMa->next = NULL;

    if (*l != NULL)
	{
	    while (lastMaillon->next != NULL)
            lastMaillon = lastMaillon->next;
        lastMaillon->next = newMa;
	}
	else
        *l = newMa;
}
