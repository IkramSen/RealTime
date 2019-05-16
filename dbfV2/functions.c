#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"


int compteur;
/*************************************************************************************************************************/
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
   /*------------------------------------------------------*/
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
    /*------------------------------------------------------*/

	float dbf(struct Task *tableau, double h, int numberT) { 
	         double partieEntiere;
		 double dbfF=0;
		 int nombreTache=numberT;
		 double t= h;
	  for (compteur = 1 ; compteur < nombreTache+1 ; compteur++){
		       double T= tableau[compteur].periode;
		       double D= tableau[compteur].deadline;
		       double C= tableau[compteur].WCET;
		       double bast=t+(T-D);
		       partieEntiere=floor(bast/T); 
		       dbfF= dbfF+(C * partieEntiere);
		       
		       
		      
	 }
	return dbfF;
		
		  }

      /*-----------------------------------------------------*/

  	void isSchedu(double demande, double h){

		double dbf=demande;
		double t= h;
	        if (dbf<t){ 
			printf("After test dbf of all tasks is less then t ... So TaskSet is schedulable using this algorithme\n");
		}
		 else {
			printf("After test t is less then dbf of all tasks So TaskSet is not schedulable using this algorithme\n");
		 }
         
	      }

