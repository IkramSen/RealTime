#ifndef TIME_H
#define TIME_H

#include <time.h>
#include <math.h>


typedef struct timespec tspec;

tspec ptask_gettime(); 

void ptask_wait_for_next_period();

double LCM(int a,int b);

double tspec_soustr(const tspec *a, const tspec *b); // a is  timestart  an b is timeend

void sleep_until(struct timespec *ts, double delay);

//double dbf(timespec c, int h, double period);

/*   c: ExecutionTime, h:t, periode2:T, deadline2:D  */		
double dbf(double ExecutionTime,double deadline, double h,double periode);

double dbfFinal(double prime1, double prime2);

void isSchedu(double dbf);

double Maxi(double ETime, double ExecutionTime );

#endif
