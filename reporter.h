#ifndef REPORTER_H
#define REPORTER_H

	#include "validator.h"
	#include "reporter.h"

	#define VQUIET 1
	#define VUNSET 2
	#define VVERBOSE 3

	void report(const char *strcpf, struct cpf_info *info);
	void set_verbosity(int mode);

#endif

