#include "reporter.h"
#include "errors.h"
#include <stdio.h>

int verbose_mode;

void set_verbosity(int mode)
{
	extern int verbose_mode;

	verbose_mode = mode;
}

void report_verbose(const char *cpfstr, struct cpf_info *info);
void report_unset(const char *cpfstr, struct cpf_info *info);
void report_quiet(const char *cpfstr, struct cpf_info *info);

void report(const char *cpfstr, struct cpf_info *info)
{
	extern int verbose_mode;

	switch(verbose_mode) {
	case VVERBOSE: report_verbose(cpfstr, info); break;
	case VQUIET: report_quiet(cpfstr, info); break;
	case VUNSET: 
	default:
		report_unset(cpfstr, info);	
		break;
	}
}


void report_verbose(const char *cpfstr, struct cpf_info *info)
{
	if (info->vcode == 1) {
		printf(mval, cpfstr);
		return;
	}

	printf(mnval, cpfstr, info->vcode);

	if (info->vcode % ETS == 0)
		printf(mts, ETS, info->len, CPFLEN);

	if (info->vcode % ETL == 0)
		printf(mtl, ETL, info->len, CPFLEN);
 
	if (info->vcode % EHNNC == 0)
		printf(mhnnc, EHNNC, cpfstr[info->fstnnc], info->fstnnc + 1);

	if (!(info->fstnnc == -1 && info->len >= 9 || info->fstnnc > 8))
		printf(wsmv, EHNNC);

	if (info->vcode % EU10 == 0)
		printf(mud, 10, EU10, cpfstr[9], info->ed10);
	
	if (info->vcode % EU11 == 0)
		printf(mud, 11, EU11, cpfstr[10], info->ed10);

	if (info->vcode % EBL == 0)
		printf(mbl, EBL);

}

void report_unset(const char *cpfstr, struct cpf_info *info)
{
	if (info->vcode == 1) {
		printf(mval, cpfstr);
		return;
	}

	printf(mnval, cpfstr, info->vcode);

	if (info->vcode % ETS == 0)
		printf(mts, ETS, info->len, CPFLEN);

	if (info->vcode % ETL == 0)
		printf(mtl, ETL, info->len, CPFLEN);
 
	if (info->vcode % EHNNC == 0)
		printf(mhnnc, EHNNC, cpfstr[info->fstnnc], info->fstnnc + 1);

	if (info->vcode % EU10 == 0)
		printf(mud, 10, EU10, cpfstr[9], info->ed10);
	
	if (info->vcode % EU11 == 0)
		printf(mud, 11, EU11, cpfstr[10], info->ed11);

	if (info->vcode % EBL == 0)
		printf(mbl, EBL);
}

void report_quiet(const char *cpfstr, struct cpf_info *info)
{
	if (info->vcode != 1)
		printf(mnval, cpfstr, info->vcode);
}

