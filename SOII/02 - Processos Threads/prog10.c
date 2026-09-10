/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char mensagem[80]="MSG do Proc. Pai";
int valor = 10;

void* filho01 () {
   printf("[Filho01] Iniciando Execucao.\n");
   printf("[Filho01] O conteudo da variavel VALOR e: %d\n", valor);
   valor = valor + 5;
   sleep(5);
   printf("[Filho01] O conteudo da variavel VALOR e: %d\n", valor);
   printf("[Filho01] Encerrando Execucao.\n");	
   pthread_exit(0);
}

void* filho02 () {
   printf("[Filho02] Iniciando Execucao.\n");
   printf("[Filho02] O conteudo da variavel VALOR e: %d\n", valor);
   valor = valor - 2;
   sleep(5);
   printf("[Filho02] O conteudo da variavel VALOR e: %d\n", valor);
   printf("[Filho02] Encerrando Execucao.\n");	
   pthread_exit(0);
}

int main(int argc, char *argv[]) {
  pthread_t	thread_id[3];
  system("clear");
  printf("[Pai] Iniciando Execucao.\n");
  printf("[Pai] O conteudo da variavel VALOR e: %d\n", valor);
  pthread_create(&thread_id[0],NULL,&filho01,NULL);
  pthread_create(&thread_id[1],NULL,&filho02,NULL);
  pthread_join(thread_id[0],NULL);
  pthread_join(thread_id[1],NULL);
  printf("[Pai] O conteudo da variavel VALOR e: %d\n", valor);
  printf("[Pai] Encerrando Execucao.\n");  
  return 0;
} 
