#include <stdio.h>
#include <stdlib.h>

struct Task {
    int periode;
    int deadline;
    int WCET;
};

int Hyperperiode;
int numberT, compteur; //nombre de tache du system
int LCM(int *tableau, int tailleTableau);
int LCMTwoNumber(int a,int b);

int main(void)
{
    struct Task t;
 
 printf("************************************************\n");
 printf("\t The dbf function\n");
 printf("************************************************\n");  
 printf("\t Please unter the taskset parameters\n");
 printf("************************************************\n"); 
 printf("\t Number of task in your taskset \n");
 printf("************************************************\n");
 scanf("%d", &numberT);
 
 int tableau[numberT];

 for (compteur = 1 ; compteur < numberT+1 ; compteur++){
    printf("Periode de la tache %d: ", compteur);
    scanf("%d", &t.periode);
    
    printf("Deadline de la tache %d: ",compteur);
    scanf("%d", &t.deadline);

    printf("WCET de la tache %d: ",compteur);
    scanf("%d", &t.WCET);
  tableau[compteur]=t.periode;

  printf("************************************************\n");  
  }

 Hyperperiode= LCM(tableau,numberT); 
 printf("hyperperiode %d: ",Hyperperiode);



 return 0;
}


	int LCMTwoNumber(int a,int b) {
			   int max, step, lcm;
		   lcm = 0;

		   if(a > b)
		      max = step = a;
		   else
		      max = step = b;

		   while(1) {
		      if(max%a == 0 && max%b == 0) {
			 lcm = max;
			 break;    
		      }

		      max += step;
		   } return lcm;
	}

	int LCM(int *tableau, int tailleTableau) {
		   int  step, lcm;
		   lcm = 0;
		   int i;
	printf("taille %d: ",tailleTableau);


	 if (tailleTableau==2){
	       lcm= LCMTwoNumber(tableau[1],tableau[2]);
	  }

	    else 
		if  (tailleTableau<2){
		lcm= tableau[1];
	
	  	}

		else 
		lcm= LCMTwoNumber(tableau[1],tableau[2]);
		    for (i = 3 ; i < tailleTableau+1; i++){
		      lcm= LCMTwoNumber(lcm,tableau[i] );
		      
		  }
	     return lcm;
	    
	}
