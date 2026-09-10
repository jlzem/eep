/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {
	system("clear");
	printf("[Pai] Iniciando a execucao.\n");
	while (1) {
		fork();
		printf("[Filho] Iniciando a execucao\n");
		sleep(2);
		printf("[Filho] Encerrando a execucao\n");
		printf("[Pai] Encerrando a execucao\n");
	}
	return 0;
}
