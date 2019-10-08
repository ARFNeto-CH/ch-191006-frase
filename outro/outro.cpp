#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

char* ch_strstr(const char*, const char*);
int		testa_strstr(char*, char*);
void	teste1();		// testes para ch_strstr()
void	teste2();		// testes para troca_palavra_na_frase()
int		troca_palavra_na_frase(char*, char*, char*);

int main(int argc, char** argv)
{
	teste2();
	return 0;
}


char* ch_strstr(const char* Palheiro, const char* Agulha)
{
	int		n = strlen(Palheiro);
	int		t = strlen(Agulha);
	int		ultimo = n - t;
	int		matches = 0;

	char* pos = 0;
	char* posFrase = (char*)Palheiro;
	char* posPalavra = (char*)Agulha;
	int		candidato = 0;
	// ja sei onde procurar: de 0 ate 'ultimo'
	for (int i = 0; i <= n; i++)
	{
		// tem duas situacoes: posso estar em uma parte 
		// da string que eu procuro ou nao
		if (candidato != 0)
		{	// ja estou em um candidato
			if (*(i + posFrase) != *(posPalavra))
			{
				matches = 0;
				candidato = 0;
				posPalavra = (char*)Agulha;	// comeca de novo
			}
			else
			{
				matches = matches + 1;
				if (matches == t) return pos;
				posPalavra += 1;
			}	// end if
		}
		else
		{	// ainda buscando um inicio
			if (i > ultimo) return 0;		// nao cabe mais
			if (*(i + posFrase) != *(posPalavra)) continue;
			// achou a primeira letra
			candidato = 1;
			posPalavra += 1;
			pos = posFrase + i;
			matches = 1;	//	achei a primeira letra
		}	// end if

	}	// end for
	return 0;
}	// end strstr()


int		testa_strstr(char* palheiro, char* agulha)
{
	char* r = ch_strstr(palheiro, agulha);
	if (r == 0)
	{
		printf("nao achou [%s] em [%s]\n", agulha, palheiro);
	}
	else
	{
		printf("achou [%s] em [%s]!\n", agulha, palheiro);
		printf("posicao: %d\n", (r - palheiro));
	}
	return (r != 0);
}	// end testa_strstr()


void		teste1()
{
	//
	// testes para strstr
	//
	char* Palheiro = "Palheiro";
	char* Agulha = "Agulha";

	char teste_frase[80];
	char teste_palavra[80];
	int n;

	strcpy(teste_frase, Palheiro);

	strcpy(teste_palavra, "iro");
	n = testa_strstr(teste_frase, teste_palavra);
	printf("strstr(%s,%s) retornou %d\n", Palheiro, teste_palavra, n);

	strcpy(teste_palavra, "irx");
	n = testa_strstr(teste_frase, teste_palavra);
	printf("strstr(%s,%s) retornou %d\n", teste_frase, teste_palavra, n);

	strcpy(teste_frase, "irxiro");

	strcpy(teste_palavra, "iro");
	n = testa_strstr(teste_frase, teste_palavra);
	printf("strstr(%s,%s) retornou %d\n", Palheiro, teste_palavra, n);

	strcpy(teste_palavra, "irx");
	n = testa_strstr(teste_frase, teste_palavra);
	printf("strstr(%s,%s) retornou %d\n", teste_frase, teste_palavra, n);

	n = testa_strstr(teste_frase, teste_frase);
	printf("strstr(%s,%s) retornou %d\n", teste_frase, teste_frase, n);

	strcpy(teste_frase, "irxirxirxiro");

	strcpy(teste_palavra, "iro");
	n = testa_strstr(teste_frase, teste_palavra);
	printf("strstr(%s,%s) retornou %d\n", Palheiro, teste_palavra, n);

	strcpy(teste_palavra, "irx");
	n = testa_strstr(teste_frase, teste_palavra);
	printf("strstr(%s,%s) retornou %d\n", teste_frase, teste_palavra, n);

	n = testa_strstr(teste_frase, teste_frase);
	printf("strstr(%s,%s) retornou %d\n", teste_frase, teste_frase, n);

}	//	end teste1()


void		teste2()
{
	char* palavra = "XYZT";
	char* palavra_nova = "abcd";
	char* frase = "01234567890123456789";	// sem a palavra
	char* frase_i = "XYZT4567890123456789"; // palavra no inicio
	char* frase_m = "01234567XYZT23456789"; // palavra no meio
	char* frase_f = "0123456789012345XYZT"; // palavra no fim

	char teste_frase[501];
	char teste_palavra[501];
	char teste_palavra_nova[501];
	int n;


	// o exemplo inicial
	strcpy(teste_frase, "azul");
	strcpy(teste_palavra, "azul");
	strcpy(teste_palavra_nova, "abcd");

	printf("\
    troca_palavra_na_frase()\n\
    frase ..........[%s]\n\
    palavra ........[%s]\n\
    palavra nova ...[%s]\n\n",
		teste_frase,
		teste_palavra,
		teste_palavra_nova
	);

	n = troca_palavra_na_frase(teste_frase, teste_palavra, teste_palavra_nova);
	printf("    retornou %d\n\n", n);
	printf("    frase no final..[%s]\n\n\n", teste_frase);

	// sem a palavra na frase
	strcpy(teste_frase, frase);
	strcpy(teste_palavra, palavra);
	strcpy(teste_palavra_nova, palavra_nova);

	printf("\
    troca_palavra_na_frase()\n\
    frase ..........[%s]\n\
    palavra ........[%s]\n\
    palavra nova ...[%s]\n\n",
		teste_frase,
		teste_palavra,
		teste_palavra_nova
	);

	n = troca_palavra_na_frase(teste_frase, teste_palavra, teste_palavra_nova);
	printf("    retornou %d\n\n", n);
	printf("    frase no final..[%s]\n\n\n", teste_frase);

	// com a palavra logo no inicio
	strcpy(teste_frase, frase_i);

	printf("\
    troca_palavra_na_frase()\n\
    frase ..........[%s]\n\
    palavra ........[%s]\n\
    palavra nova ...[%s]\n\n",
		teste_frase,
		teste_palavra,
		teste_palavra_nova
	);

	n = troca_palavra_na_frase(teste_frase, teste_palavra, teste_palavra_nova);
	printf("    retornou %d\n\n", n);
	printf("    frase no final..[%s]\n\n\n", teste_frase);


	// com a palavra no meio da frase
	strcpy(teste_frase, frase_m);


	printf("\
    troca_palavra_na_frase()\n\
    frase ..........[%s]\n\
    palavra ........[%s]\n\
    palavra nova ...[%s]\n\n",
		teste_frase,
		teste_palavra,
		teste_palavra_nova
	);

	n = troca_palavra_na_frase(teste_frase, teste_palavra, teste_palavra_nova);
	printf("    retornou %d\n\n", n);
	printf("    frase no final..[%s]\n\n\n", teste_frase);


	// com a palavra no final da frase
	strcpy(teste_frase, frase_f);

	printf("\
    troca_palavra_na_frase()\n\
    frase ..........[%s]\n\
    palavra ........[%s]\n\
    palavra nova ...[%s]\n\n",
		teste_frase,
		teste_palavra,
		teste_palavra_nova
	);

	n = troca_palavra_na_frase(teste_frase, teste_palavra, teste_palavra_nova);
	printf("    retornou %d\n\n", n);
	printf("    frase no final..[%s]\n\n\n", teste_frase);


	return;
}	//	end teste2()


int		troca_palavra_na_frase(char* frase, char* palavra, char* palavra_nova)
{
	int t = strlen(palavra);
	if (t != strlen(palavra_nova)) return -2;
	if (strlen(frase) < strlen(palavra)) return -3;
	char* pos = strstr(frase, palavra);			// retorna 0 ou o endereco da palavra na frase
	if (pos == 0) return -1;					// nao tinha a palavra na frase
	for (int i = 0; i < t; i += 1)				// tinha, entao faz a troca 
	{
		*(pos + i) = *(palavra_nova + i);		// retorna a posicao da troca
	}
	return (pos - frase);	// so isso
}	// end troca_palavra_na_frase()

/*
	0
	XYZT
	01234567890123456789
					XYZT
					|
					\
					 - 16

	Na frase a palavra pode estar a partir do inicio, 0 ate a posicao
	final em que ela cabe:

	Se
		  t = tamanho da palavra
		  n = tamanho da frase
	Entao
		  Ela pode estar comecando entre 0 e (n-t) inclusive

	No exemplo, XYZT tem 4 posicoes e a frase tem 20 entao a palavra
	pode estar entao entre 0 e 16. Se passar de 16 = (n-t) ela nao cabe

	Note que a frase pode ter uma palavra so e entao trocamos a frase toda

	Em C em string/h tem a rotina

	char *strstr(const char *haystack, const char *needle)

	ou...

	char *strstr(const char *palheiro, const char *agulha)
	https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
	em nosso bom portugues :)

	Ela devolve então char*, o endereco da palavra na frase se tiver, ou NULL.

	Então vamos escrever outra igual porque os caras que pensaram nisso sao melhores que nos provavelmente

*/