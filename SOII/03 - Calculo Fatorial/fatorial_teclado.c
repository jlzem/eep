/************************************************************************************** 
*** Programa que calcula o fatorial de um número, recebendo-o atraves do teclado 
*** Alterações promovidas por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char *argv[]) {

	int numero=0, fatorial=1, contador=0;

	system("clear");

	printf("Digite um numero para calcular o fatorial: ");
	scanf("%d", &numero);

	for (contador = numero; contador > 1; contador--) {    
		fatorial = fatorial * contador;
	}

	printf("--------------------------------------------------\n");
	printf("O Fatorial do numero %d e = %d \n", numero, fatorial);
	printf("--------------------------------------------------\n");

	return 0;
}
