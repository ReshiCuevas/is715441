/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void secuencia()
{
  long long int i;
  double pi;
  for (i=1;i<50000000000;i++){
    pi+=(i &1 ? 1.0 : -1.0 )/(2*i-1);
  }

  pi=pi*4;
  printf("π = %0.10lf \n",pi);
}
int main(void)
{
  setbuf(stdout, NULL);
  clock_t start = clock();
  int miliseg;
  secuencia();
  clock_t end = clock();
  miliseg= ((end-start)/CLOCKS_PER_SEC)*1000;
  printf("Tiempo en ms: %d",miliseg);
  while(1==1)
  {
  scanf("%d",&miliseg);
  }
  return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LIM 50000000000

typedef struct {
  long long int max;
  long long int min;
  double resultado;
}limite;
double pi;

DWORD WINAPI  secuencia(void *param){
    limite l=(limite)param;
    long long int i;

    for (i=l->min;i<l->max;i++){
      l->resultado+=((i-1) &1 ? -1.0 : 1.0 )/(2*i-1);
    }
    l->resultado=(l->resultado)*4;
    return 0;
}

int main(void)
{
  setbuf(stdout, NULL);
  int miliseg, i, num;
  long long int r;
  double pi;
  HANDLE arrHandles[16];
  limite limits[16];

  printf("Hilos?\n"),
  scanf("%d",&num);
  r= LIM/num;

  clock_t start = clock();

  for(i=0;i<num;i++){
    limits[i].min=r*i+1;
    limits[i].max=r*(i+1);
    limits[i].resultado=0;
    arrHandles[i]=CreateThread(NULL,0,secuencia,(void *)&limits[i],0,NULL);
  }

  for(i=0;i<num;i++){
      WaitForSingleObject(arrHandles[i],INFINITE);
    }

  for(i=0;i<num;i++){
