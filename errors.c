#include "errors.h"

#if LANGUAGE == LANGUAGE_PT
const char musage[] ="Modo de uso:\n\t%s $cpf\n\t%s $cpf -v\n\t%s $cpf -q\n";
const char mval[] = "%s é um CPF válido.\n";
const char mnval[] = "%s não é um CPF válido, com código de validação %d.\n";
const char mts[] = "\tmuito curto (%d) - tem comprimento %d, era esperado %d\n";
const char mtl[] = "\tmuito longo (%d) - tem comprimento %d, era esperado %d\n";
const char mhnnc[] = "\ttem caracteres não numéricos (%d) - '%c' na posição %d\n";
const char mud[] = "\tcaracter %d inesperado (%d) - é '%c' esperava-se '%d'\n";
const char mbl[] ="\testá na lista negra (%d)\n";
const char wsmv[] ="\tvalidação dos digitos redundantes foi cancelada por %d\n";
#endif

#if LANGUAGE == LANGUAGE_EN
const char musage[] = "Usage:\n\t%s $cpf\n\t%s $cpf -v\n\t%s $cpf -q\n";
const char mval[] = "%s is a valid CPF.\n";
const char mnval[] = "%s is not a valid CPF, with validation code %d.\n";
const char mts[] = "\ttoo short (%d) - has length %d, was expected %d\n";
const char mtl[] = "\ttoo long (%d) - has length %d, was expected %d\n";
const char mhnnc[] = "\thas non-numeric chars (%d) - '%c' at position %d\n";
const char mud[] = "\tunexpected %dth char (%d) - it is '%c', expecting '%d'\n";
const char mbl[] = "\tis blacklisted (%d)\n";
const char wsmv[] = "\tredundant digit validation was skipped due to %d\n";
#endif

