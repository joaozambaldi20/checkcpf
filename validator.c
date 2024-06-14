#include <stdio.h>
#include <string.h>
#include "validator.h"

/*
 * setevd: calculated the expected values for the 10th & 11th digits and asign
 * info->ed10 & info->ed11
 *
 * it is expected that
 * 	- the cpfstr has sufficient length (at least 9) - it won't be checked
 * 	- the first 9 cpfstr's chars are digits - undefined behaviour otherwise
 * 
 * information about how 10th & 11th CPF's digit validation can be found int 
 * the README of this program or the following wikipedia page: 
 *
 *	https://pt.wikipedia.org/wiki/Cadastro_de_Pessoas_F%C3%ADsicas
 */
int setevd(char *cpfstr, struct cpf_info *info)
{
	int aux, i;

	for (i = aux = 0; i < 9; ++i)
		aux += (cpfstr[i] - '0') * (10 - i);
	info->ed10 = (11 - aux % 11) % 10;

	for (i = aux = 0; i < 9; ++i)
		aux += (cpfstr[i] - '0') * (11 - i);
	aux += info->ed10 * (11 - 9);

	info->ed11 = (11 - aux % 11) % 10;
}

void valcpf(char *cpfstr, struct cpf_info *info)
{	
	int i;
	
	info->vcode = 1;

	/* checks the size */
	info->len = strlen(cpfstr);
	if (info->len < CPFLEN)
		info->vcode *= ETS;
	if (info->len > CPFLEN)
		info->vcode *= ETL;
		

	/* checks for non-numeric characters */
	info->fstnnc = -1;
	for (i = 0; i < info->len && i < CPFLEN; ++i)
		if (cpfstr[i] < '0' || cpfstr[i] > '9') {
			info->vcode *= EHNNC;	 
			info->fstnnc = i;
			break;
		}


	/* 
	 * mathematics validation
	 *
	 * we can only make (meaningfull) mathematical digit validation
	 * when
	 *	- the input is long enought
	 *	- the input has no has only numerical characters 
	 *
	 * expected values of the 10th and 11th digit will be calculated if
	 * the input has sufficient length (greater or equal to 9) and these
	 * first digits are all numeric
	 * 
	 * it is then meaning to set unexpected 10th & 11th digit errors even
	 * even those digits are not numeric, as long the input has sufficient 
	 * length for that
	 *
	 * the user of these funciton can know that mathematical validation
	 * was spected by checking the if condition as none of these variables
	 * we be further changed
 	 */
	if (info->fstnnc == -1 && info->len >= 9 || info->fstnnc > 8) {
		setevd(cpfstr, info);
		if (info->len >= 10 && cpfstr[9] - '0' != info->ed10)
			info->vcode *= EU10;
		if (info->len >= 11 && cpfstr[10] - '0' != info->ed11)
			info->vcode *= EU11;
	}

	/* blacklists 01234567890 */
	if (strcmp(cpfstr, "01234567890") == 0)
		info->vcode *= EBL;

	/* blacklists CPFs in the form XXXXXXXXXXX */
	for (i = 0; i < info->len && cpfstr[i] == cpfstr[0]; ++i)
		;
	if (i == 11)
		info->vcode *= EBL;
}

