#include "grep.h"

/*
    -- optExists (function)
    Allows to know if an option is valid.

    => Inputs :
        - Array of options (char*)
        - Array size (int)
        - Option to check (char)

    => Output :
        0 or 1
        or -1 if the array is invalid.
*/
short int optExists(char* opts, int size, char optToCheck)
{
    if (opts == NULL)
        return -1;

    int i;

    for (i = 0; i < size; i++)
        if (opts[i] == optToCheck)
            return 1;

    return 0;
}
