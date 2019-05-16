#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "task.h"

  
/*---------------Calculate LCM of two numbers--------------------------*/

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

/*---------------Calculate LCM of N numbers--------------------------*/
int LCM(struct Task **ts, int tailleTableau) {
  int  step, lcm;
  lcm = 1;
  int i;
  for (i = 0 ; i < tailleTableau; i++)
    lcm= LCMTwoNumber(lcm,ts[i]->periode);
  return lcm;
	    
}  
/*---------------Calculate the demande bound function----------------*/
float dbf(struct Task **ts, double t, int numberT) {
  int i=0;
  int dbfF = 0;
  for (i = 0 ; i<numberT; i++)
    dbfF= dbfF+(ts[i]->WCET * floor((t+ts[i]->periode-ts[i]->deadline)/ts[i]->periode));
  return dbfF;		
}

/*--------------------------Schubadility test-----------------------*/ 
int isSchedu(double demande, double h){
  return demande > h ? 0 : 1;
}

int isFeasible(struct Task ** ts, int N){
  int t;
  int H =LCM(ts,N);
  for (t=0;t<H;t++) {
    if (isSchedu(dbf(ts,t,N),t)==0)
      return 0;
  return 1;}
}


/*--------------------------Task creattion-----------------------*/ 
struct Task * create_task(int id, int C, int D, int T){
  struct Task * tau = (struct Task *) (malloc(sizeof(struct Task)));
  tau->periode = T;
  tau->deadline = D;
  tau->WCET= C;
  tau->id = id;
  return tau;
}


/*--------------------------processor creattion-----------------------*/ 
struct Processor * create_processor(int id, float U){
  struct Processor * pr = (struct Processor *) (malloc(sizeof(struct Processor)));
  pr->id = id;
  pr->utilisation = U;
  
  return pr;
}

/*--------------------------Print tasks-----------------------*/ 
void print_task(struct Task *tau){
  printf("[ Task ID:%d C:%f D:%f T:%d]\n",tau->id, tau->WCET, tau->deadline, tau->periode); 

}


/*--------------------------Print processors-----------------------*/ 
void print_processor(struct Processor *pr){
  printf("[ Processor ID:%d  U:%f]\n",pr->id, pr->utilisation); 

}


/*------------------Initialiser file attente----------------*/ 
File *initialiser()
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}


/*--------------------initialiser les files d'attente de tous les processeurs----------------*/ 
File **initialiser_FileAt(File **fileA, int m){
 int k; 
   
    	for (k=0;k<m+1;k++) {
	        File *maFile = initialiser();
    		fileA[k]=maFile;
		}
}

/*-------------ajouter tache dans la file d attente----------*/ 

void enfiler(File *file, struct Task *nvTache)
{
    Element *tau = malloc(sizeof(*tau));
    if (file == NULL || tau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    tau->tache = nvTache;
    tau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = tau;
    }
    else /* La file est vide, notre élement est le premier */
    {
        file->premier = tau;
    }
    
}

/*--------------------------Print files-----------------------*/ 
void afficherFile(File *file)
{
    
    Element *element = file->premier;
     if (element == NULL)
    {
        
	printf("Aucune tache\n");
	exit(EXIT_FAILURE);
        
    } else {

    while (element != NULL)
    {
        
        
	printf("[ Task ID:%d C:%f D:%f T:%d]\n", element->tache->id,element->tache->WCET,element->tache->deadline,element->tache->periode);
        element = element->suivant;
    }
    
    printf("\n");
}

}


/*--------------------------Calculer utilisation pour chaque tache-----------------------*/ 
float* calculerUtilisation(struct Task ** ts,int N){
    
    int t;
    float* montableau=NULL;
    montableau=malloc(N*sizeof(float));
        printf("\n");
    //remplissage du tableau
    for (t=0;t<N;t++) {
        
	montableau[t]= ts[t]->WCET/ts[t]->deadline; /// il retourn tj un 0
	printf("[ L'utilisation de la tache %d est: %.2f]\n",ts[t]->id,montableau[t]);
    }
        
	//printf("[ WCET %d]\n",ts[1]->WCET);
	//printf("[ deadline %d]\n",ts[1]->deadline);
 
	printf("\n");
    return montableau;
}


/*   tri DEcroissant */
void triD(struct Processor **pr, int size)
{   int k=0;
    int i = 0;
    int j = 0;
    float tmp = 0.000000;
   

  for(j=1;j<size;j++)
    {
       if(pr[j]->utilisation<pr[j+1]->utilisation){


                tmp = pr[j]->utilisation;
                pr[j]->utilisation= pr[j+1]->utilisation;
                pr[j+1]->utilisation = tmp;

		k=pr[j]->id;
                pr[j]->id= pr[j+1]->id;
                pr[j+1]->id = k;

		
            }
        
    }

}

/*   tri croissant */
void triC(struct Processor **pr, int size)
{   int k=0;
    int i = 0;
    int j = 0;
    float tmp = 0.000000;
   

  for(j=1;j<size;j++)
    {
       if(pr[j]->utilisation>pr[j+1]->utilisation){


                tmp = pr[j]->utilisation;
                pr[j]->utilisation= pr[j+1]->utilisation;
                pr[j+1]->utilisation = tmp;

		k=pr[j]->id;
                pr[j]->id= pr[j+1]->id;
                pr[j+1]->id = k;

		
            }
        
    }

}


/*----------Creer un tableau de structure Task contenant les element d'une file d'attente (par proc)--------------*/ 
void TransfFileTask(File *file, struct Task **fs, int N, int FileNumber){


    int k=0, i=0;
    Element *element = file->premier;
    
     if (element == NULL)
    {
	printf("Aucune tache");
    }
  	
      // calculer nombre d element de la file 
     while (element != NULL)
    {
	 int id=element->tache->id;
         float WCET= element->tache->WCET;
	 float deadline= element->tache->deadline;
         int periode=element->tache->periode;
       

        fs[i]=create_task(id,WCET,deadline,periode);

        k++; i++;
	element = element->suivant;
        if (i==k)  break;
    }
     
    // test de faisabilité a base de dbf
    TestFaisabilite(fs,k, FileNumber);
    printf("\n");
    
     
}

/*--------------------------Partitionnement avec FirstFit Algo-----------------------*/ 


float PartitionnementFF(struct Task **ts, float *grille, struct Processor **pr, int m, int N) {    
                 //N :nombre de taches m:nombre de processeur
	 	int t,j,i,k=0;
		float CapaciteMax=1.0;  //Utilisation max des processeurs
		File *fileA[m];     //L'ensemble des files d'attentes
	        struct Task *fs[N];


		//initialisation des files d'attentes
		initialiser_FileAt(fileA, m);
  
		// partitionnement des taches 
		for (t=0;t<N;t++) {  // on entre dans ce test quand le premier processeur est plein
			j=1;   
		
		         //premier processeur
		        while ((grille[t]+ pr[j]->utilisation > CapaciteMax)) { 
				
				j=j+1;
				if (j>m) {
			 
			  	printf("Pas de solution...\n");
				for (k=1;k<m+1;k++) {
	     			 printf("La file d'attente du processeur %d contient:\n",k);
	     			 afficherFile(fileA[k]);
				}
				} 
		       	}
		    enfiler(fileA[pr[j]->id], ts[t]);
		    pr[j]->utilisation = pr[j]->utilisation +grille[t];
		  	    
		} 
 	      for (k=1;k<m+1;k++) {
	    	 printf("La file d'attente du processeur %d contient:\n",k);
	     	 afficherFile(fileA[k]);
	     
	    }

 
             /* Tester la faisabilite pour chaque sous ensemble de taches  */
		for (k=1;k<m+1;k++) {
		
		TransfFileTask(fileA[k],fs, N, k);
	         }

	}


/*--------------------------Partitionnement avec BestFit Algo-----------------------*/ 


float PartitionnementBF(struct Task **ts, float *grille, struct Processor **pr, int m, int N){    
                 int t,j,i,k=0;
		float CapaciteMax=1.0;  //Utilisation max des processeurs
		File *fileA[m];     //L'ensemble des files d'attentes
        	struct Task *fs[N];
		

		//initialisation des files d'attentes
		initialiser_FileAt(fileA, m);
  
		// partitionnement des taches 
		for (t=0;t<N;t++) {  // on entre dans ce test quand le premier processeur est plein
			j=1;   
		
		         //premier processeur
		        while ((grille[t]+ pr[j]->utilisation > CapaciteMax)) { 
				
				j=j+1;
				if (j>m) {
			 
			  	printf("Pas de solution...\n");
				for (k=1;k<m+1;k++) {
	     			 printf("La file d'attente du processeur %d contient:\n",k);
	     			 afficherFile(fileA[k]);
				}
				} 
		       	}
		    enfiler(fileA[pr[j]->id], ts[t]);
		    pr[j]->utilisation = pr[j]->utilisation +grille[t];
		    printf("utilisation nouvelle dans le processeur %d est %f\n",pr[j]->id,pr[j]->utilisation);	
		    triD(pr,m);
		      
		} 
 	      for (k=1;k<m+1;k++) {
	    	 printf("La file d'attente du processeur %d contient:\n",k);
	     	 afficherFile(fileA[k] );
	    }
              
             /* Tester la faisabilite pour chaque sous ensemble de taches  */
		for (k=1;k<m+1;k++) {
		printf("Transformer  La file d'attente du processeur %d contient:\n",k);
		TransfFileTask(fileA[k],fs, N, k);
	         }

}


/*--------------------------Teste de faisabilité à base de dbf-----------------------*/ 

void TestFaisabilite(struct Task **fs, int N, int FileNumber){

  int Hyperperiode= LCM(fs,N); //LCM of all periods
  
  printf("[PROCESSOR] %d \n", FileNumber);
  printf("This is the Hyperperiod %d \n", Hyperperiode);
  
  int f=isFeasible(fs,N);
  if (f==1)
    printf("FEASIBLE \n");
  else printf("Not Feasible \n");

}

/*--------------------------Partitionnement avec BestFit Algo-----------------------*/ 

float PartitionnementWF(struct Task **ts, float *grille, struct Processor **pr, int m, int N){    
                 int t,j,i,k=0;
		float CapaciteMax=1.0;  //Utilisation max des processeurs
		File *fileA[m];     //L'ensemble des files d'attentes
        	struct Task *fs[N];
		

		//initialisation des files d'attentes
		initialiser_FileAt(fileA, m);
  
		// partitionnement des taches 
		for (t=0;t<N;t++) {  // on entre dans ce test quand le premier processeur est plein
			j=1;   
		
		         //premier processeur
		        while ((grille[t]+ pr[j]->utilisation > CapaciteMax)) { 
				
				j=j+1;
				if (j>m) {
			 
			  	printf("Pas de solution...\n");
				for (k=1;k<m+1;k++) {
	     			 printf("La file d'attente du processeur %d contient:\n",k);
	     			 afficherFile(fileA[k]);
				}
				} 
		       	}
		    enfiler(fileA[pr[j]->id], ts[t]);
		    pr[j]->utilisation = pr[j]->utilisation +grille[t];
		    printf("utilisation nouvelle dans le processeur %d est %f\n",pr[j]->id,pr[j]->utilisation);	
		    triC(pr,m);
		      
		} 
 	      for (k=1;k<m+1;k++) {
	    	 printf("La file d'attente du processeur %d contient:\n",k);
	     	 afficherFile(fileA[k] );
	    }
              
             /* Tester la faisabilite pour chaque sous ensemble de taches  */
		for (k=1;k<m+1;k++) {
		printf("Transformer  La file d'attente du processeur %d contient:\n",k);
		TransfFileTask(fileA[k],fs, N, k);
	         }

}


