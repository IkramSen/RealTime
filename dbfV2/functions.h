#ifndef TIME_H
#define TIME_H

#include <time.h>
#include <math.h>
#include "structure.h"

/*******************************************************************************************************************************/

int LCM(int *tableau, int tailleTableau);
int LCMTwoNumber(int a,int b);
float dbf(struct Task *tableau, double h, int numberT) ; 
void isSchedu(double demande, double h);

/*******************************************************************************************************************************/

#endif
