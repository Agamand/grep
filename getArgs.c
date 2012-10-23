#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grep.h"
#include "MemoryMgr/MemoryMgr.h"
/*
    -- getArgs (function)

    Examples Commands allowed :
    grep -i "pattern" fic.txt
    grep -ifw "pattern" fic fic2 fic3
    grep -i -fw "pattern" fic
    grep "pattern" -wf fic -n fic2 fic3 -s

    => Inputs : argc, argv

    => Output :
    Return NULL if the list of arguments is invalid.
    Else, return a pointer of a structure Arguments :
        - Linked list of options (i, f, w, NULL)
        - Pattern (s, t, r, i, n, g, \0)
        - Linked list of files names (fic\0, fic2\0, NULL)

*/

Arguments* getArgs(int argc, char** argv)
{
    int i;
    int j;

    short int patternFound = 0;

    FILE* pf = NULL;

    Arguments *args = (Arguments*)MALLOC(sizeof(Arguments));
    args->options = NULL;
    args->pattern = NULL;
    args->files = NULL;

    const int nOpts = 36;
    char opts[36] = {
        'E', 'F', 'G', 'P', 'e', 'f', 'i', 'w', 'x', 'z', 's', 'v',
        'V', 'm', 'b', 'n', 'H', 'h', 'o', 'q', 'a', 'I', 'd', 'D',
        'r', 'R', 'L', 'l', 'c', 'T', 'Z', 'B', 'A', 'C', 'u', 'U'
    };
    char* optsSt[36] = {
        "--extended-regexp",
        "--fixed-regexp",
        "--basic-regexp",
        "--perl-regexp",
        "XXXXXXXXXXX", // --regexp=MOTIF
        "XXXXXXXXXXX", // --file=FICHIER
        "--ignore-case",
        "--word-regexp",
        "--line-regexp",
        "--null-data",
        "--no-messages",
        "--invert-match",
        "--version",
        "XXXXXXXXXXX", // --max-count=NUM
        "--byte-offset",
        "--line-number",
        "--with-filename",
        "--no-filename",
        "--only-matching",
        "--quiet",
        "--text",
        "XXXXXXXXXXX", // no option with -- for I
        "XXXXXXXXXXX", // --directories=ACTION
        "XXXXXXXXXXX", // --devices=ACTION
        "--recursive", // r
        "--recursive", // R
        "--files-without-match",
        "--files-with-matches",
        "--count",
        "--initial-tab",
        "--null",
        "XXXXXXXXXXX", // --before-context=NUM
        "XXXXXXXXXXX", // --after-context=NUM
        "XXXXXXXXXXX", // --context=NUM
        "--binary",
        "--unix-byte-offsets",
    };

    void* save = NULL;

    if (argc <= 2)
    {
        if (argc == 2 && strcmp(argv[1], "--help") == 0)
        {
            addEnd(&(args->options), (void*)&(argv[1][0]));
            return args;
        }
        else
            return NULL;
    }

    for (i = 1; argv[i] != NULL; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == '-')
            {
                if (strcmp(argv[i], "--help") == 0)
                {
                    freeList(&(args->options));
                    addEnd(&(args->options), (void*)&(argv[i][0])); // Put a '-' for the help option
                    args->pattern = NULL;
                    freeList(&(args->files));
                    return args;
                }
                else
                {
                    for (j = 0; j < nOpts; j++)
                    {
                        if (strcmp(argv[i], optsSt[j]) == 0)
                        {
                            addEnd(&(args->options), (save = MALLOC(sizeof(char))));
                            *(char*)save = opts[j];
                        }
                    }
                }
            }
            else
            {
                for (j = 0; argv[i][j] != '\0'; j++)
                {
                    if (argv[i][j] != '-' && optExists(opts, nOpts, argv[i][j]) && !optIsAdded(args->options, argv[i][j])) // != '-' is optional because '-' is not an option
                        addEnd(&(args->options), (void*)&(argv[i][j]));
                }
            }
        }
        else if (!patternFound)
        {
            patternFound = 1;
            args->pattern = argv[i];
        }
        else
        {
			addEnd(&(args->files), (void*)argv[i]);
        }
    }

    return patternFound ? args : NULL;
}
