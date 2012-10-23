#include "grep.h"

/*
    -- optIsAdded (function)
    Allows to know if an option was already added to the list of options

    => Inputs :
        - Linked list of options
        - Option to check

    => Output :
        0 or 1
*/

short int optIsAdded(Maillon* options, char opt)
{
    Maillon* inter;
        inter = options;

    while (inter != NULL)
    {
        if (*(char*)inter->data == opt)
            return 1;

        inter = inter->next;
    }

    return 0;
}
