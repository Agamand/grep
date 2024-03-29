#include "grep.h"
#include "MemoryMgr/MemoryMgr.h"

/*
	Default egrep command
	Return the lines of the file (argv[2]) containing the regular expression (argv[1]) 
*/
int eGrep(int argc, char** argv){
	
	Arguments* args = getArgs(argc, argv);

	if(!args)
		return 0;

	if (args->files != NULL)
	{
		
		Maillon* lines = nFileLoader(args);

		if (lines != NULL)
		{

			Maillon* results = extractWithPattern(lines, args->pattern, hasOption('i', args->options), hasOption('w', args->options), hasOption('v', args->options));

			displayWithOptions(results, args);

			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv)
{
	eGrep(argc, argv);
#ifdef _DEBUG_
	memorymgr_showMemLeak();
	memorymgr_log();
#endif
	system("pause");
	return 0;
}