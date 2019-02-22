#ifndef TASK_H
#define TASK_H

struct Task{
  int id;
  int periode;
  float deadline;
  float WCET;
};
struct Processor{
  int id;
  float utilisation;
};

typedef struct Element Element;

struct Element
{
    struct Task *tache;
    Element *suivant;
};

typedef struct File File;

struct File
{
    Element *premier;
};



/* functions  */

File *initialiser();
void enfiler(File *file, struct Task *nvNombre);
int defiler(File *file);
void afficherFile(File *file);
File **initialiser_FileAt(File **fileA, int m); //files d'attentes
void TransfFileTask(File *file, struct Task **fs, int N, int k);

int LCM(struct Task **ts, int tailleTableau);
int LCMTwoNumber(int a,int b);
float dbf(struct Task **tableau, double h, int numberT) ; 
int isSchedu(double demande, double h);
int isFeasible(struct Task ** ts, int N);
float * calculerUtilisation(struct Task ** ts,int N);
void TestFaisabilite(struct Task **fs, int N,int FileNumber);

struct Task * create_task(int, int, int ,int);
struct Processor * create_processor(int id, float U);
void print_task(struct Task *tau);


void triC(struct Processor **pr, int size);
void triD(struct Processor **pr, int size);

float PartitionnementFF(struct Task **ts, float *grille, struct Processor **pr, int m, int N);
float PartitionnementBF(struct Task **ts, float *grille, struct Processor **pr, int m, int N);
float PartitionnementWF(struct Task **ts, float *grille, struct Processor **pr, int m, int N);

#endif
