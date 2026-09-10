/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* filho (void* mensagem) {
   printf("[Filho] Iniciando Execucao.\n");
   printf("[Filho] A informacao recebida foi: %s\n", mensagem);
   sleep(5);
   printf("[Filho] Encerrando Execucao.\n");	
}

int main(int argc, char *argv[]) {
  pthread_t	thread_id;
  char mensagem[80]="MSG do Proc. Pai";
  system("clear");
  printf("[Pai] Iniciando Execucao.\n");
  pthread_create(&thread_id,NULL,&filho,&mensagem);
  pthread_join(thread_id,NULL);
  printf("[Pai] Encerrando Execucao.\n");  
  return 0;
} 
