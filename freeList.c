#include <stdlib.h>

#include "linkedList.h"

void freeList(Maillon** l)
{
    Maillon* inter = *l;
    Maillon* forw;

    while (inter != NULL)
    {
        forw = inter->next;
        free(inter);
        if (forw != NULL)
            inter = forw->next;
    }

    *l = NULL;
}
