#ifndef VALIDATOR_H
#define VALIDATOR_H

#define CPFLEN 11	/* the length of a CPF number ss 11 */
#define ETS 2		/* validation error: too short */
#define ETL 3		/* validation error: too long */
#define EHNNC 5		/* validation error: has non-numeric chars */
#define EU10 7		/* validation error: unexpected 10th digit */
#define EU11 11		/* validation error: unexpected 11th digit */
#define EBL 13		/* validation error: blacklisted */


struct cpf_info
{
	short vcode;	/* validation code, see README */
	short len;	/* the length of the string */
	short fstnnc;	/* first invalid char's idnex if any, ohterwise -1 */
	short ed10;	/* expected value of the 10th digit */
	short ed11;	/* expected value of the 11th digit */
};

void valcpf(char *, struct cpf_info *);

#endif

