/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

char mensagem[80]="MSG do Proc. Pai";

void* filho () {
   printf("[Filho] Iniciando Execucao.\n");
   printf("[Filho] O conteudo da variavel MENSAGEM e: %s\n", mensagem);
   strcpy(mensagem,"MSG do Proc. Filho");
   sleep(5);
   printf("[Filho] O conteudo da variavel MENSAGEM e: %s\n", mensagem);
   printf("[Filho] Encerrando Execucao.\n");	
}

int main(int argc, char *argv[]) {
  pthread_t	thread_id;
  system("clear");
  printf("[Pai] Iniciando Execucao.\n");
  printf("[Pai] O conteudo da variavel MENSAGEM e: %s\n", mensagem);
  pthread_create(&thread_id,NULL,&filho,NULL);
  pthread_join(thread_id,NULL);
  printf("[Pai] O conteudo da variavel MENSAGEM e: %s\n", mensagem);
  printf("[Pai] Encerrando Execucao.\n");  
  return 0;
} 
