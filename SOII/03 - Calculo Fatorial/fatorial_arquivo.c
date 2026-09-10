/************************************************************************************** 
*** Programa que calcula o fatorial de um número, recebendo-o atraves de um arquivo 
*** Alterações promovidas por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {

	int numero=0, fatorial=1, contador=0;
	FILE *arquivo;

	system("clear");

	arquivo=fopen("fatorial.txt","r");

	if ( arquivo == NULL ) {

		printf("--------------------------------------------------\n");
		printf("Nao foi possivel abrir o arquivo fatorial.txt\n");
		printf("--------------------------------------------------\n");

	} else {

		fscanf(arquivo,"%d",&numero);
		fclose(arquivo);

		for (contador = numero; contador > 1; contador--) {    
			fatorial = fatorial * contador;
		}

		printf("--------------------------------------------------\n");
		printf("O Fatorial do numero %d e = %d \n", numero, fatorial);
		printf("--------------------------------------------------\n");

	}

	return 0;
}
