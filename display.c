#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

void display(Maillon* l)
{
    Maillon* inter;
        inter = l;
    int i = 1;

    while (inter != NULL)
    {
        if (i > 1)
        {
            printf(" ");
        }
        printf("%p", inter->data);

        inter = inter->next;
        i++;
    }
    if (i == 1)
        printf("List empty");

    printf("\n");
}
