#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "validator.h"
#include "reporter.h"


int main(int argc, char **argv)
{
	int i;
	struct cpf_info info;

	/* prints usage if there is no cpf to be checked */
	if (argc < 2) {
		fprintf(stderr, musage, argv[0], argv[0], argv[0]);
		return 1;
	}
	
	/* initializes external int verbose mode wrt. command line args */
	if (strcmp(argv[argc - 1], "-q") == 0)
		set_verbosity(VQUIET);
	else if (strcmp(argv[argc - 1], "-v") == 0)
		set_verbosity(VVERBOSE);
	else
		set_verbosity(VUNSET);

	for (i = 1; i < argc; ++i)
		if (argv[i][0] != '-') {
			valcpf(argv[i], &info);
			report(argv[i], &info);
		}


	return 0;
}

