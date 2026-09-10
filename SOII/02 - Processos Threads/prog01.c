/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* filho (void* null) {
   printf("[Filho] Iniciando Execucao.\n");
   sleep(5);
   printf("[Filho] Encerrando Execucao.\n");	
}

int main(int argc, char *argv[]) {
  pthread_t	thread_id;
  system("clear");
  printf("[Pai] Iniciando Execucao.\n");
  pthread_create(&thread_id,NULL,&filho,NULL);
  printf("[Pai] Encerrando Execucao.\n");  
  return 0;
} 
