#include <stdlib.h>

#include "linkedList.h"

void changeMaillon(Maillon* l, int n, void* data)
{
    Maillon* ad;
        ad = l;
    int i;

    for (i = 1; ad->next != NULL && i < n; i++)
        ad = ad->next;

    if (i != n)
        return;

    ad->data = data;
}
