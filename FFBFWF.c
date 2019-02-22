
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "task.h"


int main(void)
{
  int N=6,i , m=4, Heurist=0;

  int k;
  struct Task *ts[N];
  struct Processor *pr[m];
  
  // un example avec 3 taches 
  ts[0]=create_task(0,4.0,5.0,6); //id,C,D,T
  ts[1]=create_task(1,2.0,3.0,4);
  ts[2]=create_task(2,1.0,6.0,8);
  ts[3]=create_task(3,4.0,5.0,8);
  ts[4]=create_task(4,2.0,5.0,8);
  ts[5]=create_task(5,1.0,3.0,8);

  print_task(ts[0]);
  print_task(ts[1]);
  print_task(ts[2]);
  print_task(ts[3]);
  print_task(ts[4]); 
  print_task(ts[5]);

  pr[1]=create_processor(1,0);
  pr[2]=create_processor(2,0);
  pr[3]=create_processor(3,0);
  pr[4]=create_processor(4,0);

  print_processor(ts[1]);
  print_processor(ts[2]);
  print_processor(ts[3]);
  print_processor(ts[4]);

  printf("Chose one heuristic : 1-> FirstFit / 2-> BestFit? / 3-> WorstFit \n");
	   scanf("%d", &Heurist);

		if (Heurist==1){ //firstFit 
			float* grille=calculerUtilisation(ts,N); //tableau des utilisations pour chaque tache
		       	PartitionnementFF(ts, grille,pr, m, N);

			}
			else {
			  if (Heurist==2) { //BestFit 
			 float* grille=calculerUtilisation(ts,N); 
		         PartitionnementBF(ts, grille,pr, m, N);
			  } 
		else   {      //WorstFit 
			 float* grille=calculerUtilisation(ts,N); 
		         PartitionnementWF(ts, grille,pr, m, N);   
		   } } 

  return 0;
}
