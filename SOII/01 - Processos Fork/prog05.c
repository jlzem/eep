/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc,char *argv[]) {
	pid_t   var;
	system("clear");
	printf("[Pai] Iniciando a execucao.\n");
	var=fork();
	if ( var == 0) {
	   printf("[Filho] Iniciando a execucao\n");
	   sleep(10);
	   printf("[Filho] Encerrando a execucao\n");
	} else {
	   sleep(5);
	   printf("[Pai] Encerrando a execucao\n");
	}
	return 0;
}
