#include <stdlib.h>
#include <stdio.h>
#include "func.h"
#include "task.h"
#include <pthread.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>



extern int periode1;
extern int periode2;
extern int deadline1;
extern int deadline2;
extern double h;


/* ********************************** */
struct timespec CurrentTime, End;
double dbf1, dbf2;
double Realdeadline1,Realdeadline2;
/* ********************************* */
			
	void* tache1(void *arg) 
		{
		 struct timespec timeStart, timeEnd,i ;
		 int nb;
		 double ETime=0;
		 	
			/*  initialisation */
	                CurrentTime=ptask_gettime();
		   	End.tv_sec = (CurrentTime.tv_sec +h);
	                printf("We are in the thread111111111111111.\n");
			i = ptask_gettime();
                        nb=0;   
   
		while(i.tv_sec<End.tv_sec){

			/* start date */
			timeStart = ptask_gettime(); 
			
			/*calcule de deadline et periode*/
			double RealPeriode=i.tv_sec+periode1;
			Realdeadline1= timeStart.tv_sec + deadline1;

			/* treatment  */
			
			 printf("periode1 %d\n", periode1) ;
		 	 printf("hyperperiode %f\n", h) ;
		 	 printf("The beginning of execution: (%lld)s et (%.9ld)ns\n", (long long)timeStart.tv_sec, timeStart.tv_nsec);
                        
			/* End of treatment  */
			timeEnd = ptask_gettime();  

                        
                        /*   resp time */
			double ExecutionTime = tspec_soustr(&timeStart, &timeEnd); 
		        //ETime=ExecutionTime;
                        ETime= Maxi(ETime, ExecutionTime );
			
			/*  missing deadline */
			if( ExecutionTime >Realdeadline1) {
        		    printf( "The execution time has exceeded the deadline for job  %d\n",nb++);
           		    //pthread_exit(NULL);
                         }
			else{
			    printf("The execution time in thread 1 is: %f\n",ExecutionTime);
			}

			/*  waiting for next period  */
			double nextperiod=RealPeriode-timeEnd.tv_sec;
			sleep_until(&timeEnd, nextperiod);


			/*** edf test preeption ***/
			i=ptask_gettime();

 			double TempsRestant=  Realdeadline2-i.tv_sec;
			
			if (TempsRestant==0) {
			 printf("THREAD 2 a depasse son echeance");
			}

			else {
			if (TempsRestant < Realdeadline1) {
			 
			 sleep_until(&i, TempsRestant);
			
			} }

			i=ptask_gettime();
			
			}
		    printf( "The max execution time of all jobs in task 1 is  %f\n", ETime);
                    /*   c: ExecutionTime, h:t, periode1:T, deadline1:D  */	
		     dbf1= dbf(ETime,deadline1,h,periode1);	
		
	}		





	void* tache2(void *arg) 
		{
        
		      struct timespec timeStart, timeEnd,j ;
		      int nb;   
		      double ETime=0;
		      CurrentTime=ptask_gettime();
		      End.tv_sec = (CurrentTime.tv_sec +h); 
		      printf("We are in the thread 222222222222222.\n");
		      j = ptask_gettime();
		      nb=0;
		
                        
		    while(j.tv_sec<End.tv_sec){

			/* start date */
			timeStart = ptask_gettime(); 

			/*calcule de deadline et periode*/
			double RealPeriode=j.tv_sec+periode2;
			Realdeadline2= timeStart.tv_sec + deadline2;

			/* treatment  */
			printf("h in thread 2 is :  %f\n",h);
			printf("The beginning of execution: (%lld)s et (%.9ld)ns\n", (long long)timeStart.tv_sec, timeStart.tv_nsec);
                        printf("periode2 %d\n", periode2) ;
			
			/* End of treatment  */
			timeEnd = ptask_gettime();  

                        
                        /*   execution time */
			double ExecutionTime= tspec_soustr(&timeStart, &timeEnd);
			
			ETime= Maxi(ETime, ExecutionTime );
                        
			//ETime=ExecutionTime;
		        
			/*  missing deadline */
			if( ExecutionTime >Realdeadline2) {
        		    printf( "The execution time has exceeded the deadline for job  %d\n",nb++);
           		    //pthread_exit(NULL);
                         }
			else{
			  
			    printf("The execution time in thread 2 is : %f\n",ExecutionTime);
			}

			/* Wait for next period  */
			double nextperiod=RealPeriode-timeEnd.tv_sec;
			sleep_until(&timeEnd, nextperiod);

			/*** edf test preeption ***/
			j=ptask_gettime();

 			double TempsRestant=  Realdeadline1-j.tv_sec;
			if (TempsRestant==0) {
			 printf("THREAD 1 a depasse son echeance");
			}

			else {
			if (TempsRestant < Realdeadline2) {
		          sleep_until(&j, TempsRestant);
			}}
			
			/*  get current time to compare it with t */
			j=ptask_gettime();
                        
			}
		printf( "The max execution time of all jobs in task 2 is  %f\n", ETime);
	         /*   c: ExecutionTime, h:t, periode2:T, deadline2:D  */	
		double dbf2= dbf(ETime,deadline2,h,periode2);
        

		}
