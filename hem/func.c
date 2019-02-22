 #include "func.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#define BILLION 1E9

double t;
/******************************************  FUnctions ********************************************/

	  double Maxi(double ETime, double ExecutionTime){
           
               double Maximum=0;

	       if(ETime < ExecutionTime){  Maximum= ExecutionTime;
		printf("max in the function: %f\n",Maximum);	
		 }
		else{  Maximum = ETime; 
                printf("max in the function: %f\n",Maximum);	
		}

          return Maximum;

           }

     	  double dbf(double ExecutionTime,double deadline, double h,double periode) { 
               double T= periode;
               t= h;
               double C= ExecutionTime;
               double D= deadline;
	       double partieEntiere;
	       double dbfF;
	
        double bast=t+(T-D);
	partieEntiere=floor(bast/T); 
	dbfF= C * partieEntiere;
	 //printf("dbfF in the function: %f\n",dbfF);	
	return dbfF;
	  }


	   double dbfFinal(double prime1, double prime2){ 
		       double dbf1= prime1;
		       double dbf2= prime2;
		       
	
		double dbftotal=dbf1+dbf2;
		printf("we are in function dbfFinal and here dbf of all tasks (task1 and task2) in interval t= %f is : %f\n",t,dbftotal);	
		return dbftotal;
		  }


	 void isSchedu(double dbf){

		double dbftotal=dbf;

	        if (dbftotal<t){ 
			printf("and after test dbf of all tasks is less then t ... So TaskSet is schedulable using this algorithme\n");
		}
		 else {
			printf("but after test t is less then dbf of all tasks So TaskSet is not schedulable using this algorithme\n");
		 }
         
	      }

	   typedef struct timespec tspec;

	   /* I used CLOCK_MONOTONIC because i don't actually care what time it is, I just want the clock to be consistent */
	   tspec ptask_gettime() {

	   tspec b;
	   clock_gettime(CLOCK_MONOTONIC, &b); 
	   return b; 
	   }
	   
	   inline double LCM(int a,int b) {
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

	   // execution time
	    inline double tspec_soustr(const tspec *ts, const tspec *te) {
		double tu;

		//printf("The beginning of execution in function is: (%lld)s et (%.9ld)ns\n", (long long) ts->tv_sec, ts->tv_nsec);
		tu = (te->tv_sec - ts->tv_sec) + (te->tv_nsec - ts->tv_nsec) / BILLION;

		//printf("The execution time in function is: %f\n",tu);
		return tu;
		}
	
		// nanoSleep()
	    void sleep_until(struct timespec *ts, double delay)
	       {
	
		ts->tv_sec += delay;
		if(ts->tv_sec >= 100*100*100){
			ts->tv_sec -= 100*100*100;
			ts->tv_sec++;
		}
	   	clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, ts,  NULL);
             
	}

          /******************************************  end FUnctions ********************************************/
