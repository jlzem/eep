/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

char msg[80] = "Eu nao sou ninguem ...";

int main(int argc,char *argv[]) {
	pid_t   filho1, filho2;
	int estado;
	system("clear");
	printf("[Pai] Iniciando a execucao.\n");
	
	filho1=fork();
	if ( filho1 == 0) {
	   printf("[Filho 1] Iniciando a execucao.\n");
	   printf("[Filho 1] O valor de MSG e %s.\n",msg);
	   strcpy(msg,"Eu sou o processo FILHO 1.");
	   printf("[Filho 1] O valor de MSG e %s.\n",msg);
	   printf("[Filho 1] Encerrando a execucao.\n");
	   exit(0);
	}

	filho2=fork();
	if ( filho2 == 0) {
	   printf("[Filho 2] Iniciando a execucao.\n");
	   printf("[Filho 2] O valor de MSG e %s.\n",msg);
	   strcpy(msg,"Eu sou o processo FILHO 2.");
	   printf("[Filho 2] O valor de MSG e %s.\n",msg);
	   printf("[Filho 2] Encerrando a execucao.\n");
	   exit(0);
	}

	waitpid(filho1,estado,0);
	waitpid(filho2,estado,0);

	printf("[Pai] O valor de MSG e %s.\n",msg);
	printf("[Pai] Encerrando a execucao.\n");
	return 0;
}
