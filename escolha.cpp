// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa matatdor.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <iostream>
#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()
#include <sched.h>
#include <sys/time.h>     // getpriority(int which, int who)  setpriority(int which, int who, int prio);
#include <sys/resource.h>
using namespace std;

/*
  LEMBRAR DE RODAR COMO SUPERUSUARIO !!! 
*/
int main()
{
  
  int menu;
  int pid_vitima;
  int core;
  int prioridade;
  cpu_set_t set;
	
	while(true) {

  	printf( "1 - MATAR \n 2 - PARAR \n 3 - CONTINUAR \n 4 - MUDAR CPU \n 5 - ADICIONAR PRIORIDADE \n");
  	scanf( "%d", &menu);
	
	  printf("PID DA VITIMA: ");
	  scanf("%d", &pid_vitima);

  	switch(menu) {
  		case 1:
  			kill(pid_vitima, SIGKILL);
  			break;
  		case 2:
  			kill(pid_vitima, SIGSTOP);
  			break;
  		case 3:
  			kill(pid_vitima, SIGCONT);
  			break;

		  case 4:
			 printf("CORE: ");
			 scanf("%d", &core);

       CPU_ZERO(&set);
			 CPU_SET(core, &set);
			 sched_setaffinity(pid_vitima, sizeof(cpu_set_t), &set);
			 break;

      case 5:
       
       printf("Prioridade: ");
       scanf("%d", &prioridade);
       setpriority(PRIO_PROCESS, pid_vitima, prioridade);
       // cout << getpriority(PRIO_PROCESS, pid_vitima) << endl; 
  		 break;

      default:
  			break;
  }
}

 exit(0);
}






