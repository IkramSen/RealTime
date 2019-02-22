#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "structure.h"

int Hyperperiode;
int numberT, compteur; //nombre de tache du system
float Demande=0;



int main(void)
{
    struct Task t;
    
 printf("************************************************\n");
 printf("\t The dbf function\n");
 printf("************************************************\n");  
 printf("\t Please unter the taskset parameters\n");
 printf("************************************************\n"); 
 printf("Number of task in your taskset : ");
 scanf("%d", &numberT);
 printf("************************************************\n");

 int tableau[numberT];
 struct Task tasks[numberT];

 for (compteur = 1 ; compteur < numberT+1 ; compteur++){
    printf("Periode de la tache %d: ", compteur);
    scanf("%d", &t.periode);
    
    printf("Deadline de la tache %d: ",compteur);
    scanf("%d", &t.deadline);

    printf("WCET de la tache %d: ",compteur);
    scanf("%d", &t.WCET);
  
 // ensembles des taches
  tasks[compteur].periode = t.periode;
  tasks[compteur].deadline = t.deadline;
  tasks[compteur].WCET = t.WCET;

  tableau[compteur]=t.periode;// tableau des periodes
  
  printf("************************************************\n");  
  }

 Hyperperiode= LCM(tableau,numberT); 
 Demande= dbf(tasks, Hyperperiode,numberT );
 printf("hyperperiode %d: \n",Hyperperiode);
 printf("Demande de processeur %f: \n",Demande);

 isSchedu(Demande,Hyperperiode);


 return 0;
}

