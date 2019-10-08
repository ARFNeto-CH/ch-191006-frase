#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

int		troca_palavra_na_frase(char*, char*, char*);

int main(int argc, char** argv)
{
	if (argc < 4)
	{
		printf("ARFNeto\n\n\tUse: troca Frase Palavra Palavra_Nova\n\n");
		return 0;
	}	// end if

	printf("\
    troca_palavra_na_frase()\n\
    frase ..........[%s]\n\
    palavra ........[%s]\n\
    palavra nova ...[%s]\n\n",
		argv[1],
		argv[2],
		argv[3]
	);
	int	n = troca_palavra_na_frase(argv[1], argv[2], argv[3]);
	printf("    retornou %d\n\n", n);
	printf("    frase no final..[%s]\n\n\n", argv[1]);


	return 0;
}


int		troca_palavra_na_frase(char* frase, char* palavra, char* palavra_nova)
{
	int t = strlen(palavra);
	if (t != strlen(palavra_nova)) return -2;
	if (strlen(frase) < strlen(palavra)) return -3;
	char* pos = strstr(frase, palavra);			// retorna 0 ou o endereco da palavra na frase
	if (pos == 0) return -1;					// nao tinha a palavra na frase
	for (int i = 0; i < t; i += 1)			
		*(pos + i) = *(palavra_nova + i);		// retorna a posicao da troca
	return (pos - frase);	// so isso
}	// end troca_palavra_na_frase()

