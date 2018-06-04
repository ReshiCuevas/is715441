#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nombre[15];
  float calificacion;
} Profesor;

void readArray(Profesor *arr, int x){
  int i;

  for (i=0; i<x ; i++){
    scanf("%s",arr[i].nombre);
    scanf("%f", &arr[i].calificacion);
  }
}
void mergeArrays (Profesor *arr, int x, Profesor *arrr, int y, Profesor *arrrr, int z){
  int i, j;

  for (i=0; i<x; i++){
    strcpy(arrrr[i].nombre, arr[i].nombre);
    arrrr[i].calificacion=arr[i].calificacion;
  }
  j=i;
  for (i=0; i<y; i++, j++){
    strcpy(arrrr[j].nombre, arrr[i].nombre);
    arrrr[j].calificacion=arrr[i].calificacion;
  }

}
void sortArray(Profesor *arr, int x){
  Profesor temp;
  int i, j;
  for(i=0; i<x; i++){
    for (j=i+1; j<x; j++){
      if (arr[i].calificacion<arr[j].calificacion){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
}
void printArray(Profesor *arr, int x ){
  int i;
  for(i=0; i<x; i++){
    printf("%s %0.1f\n",arr[i].nombre, arr[i].calificacion);
  }
}

void main(){
  Profesor arrA[20];  //Primer arreglo
  Profesor arrB[20];  //Segundo arreglo
  Profesor arrC[40];  //Arreglo final, con elementos fusionados y ordenados
  int n1, n2, n3; //Longitud de los arreglos

  scanf( "%d", &n1);
  readArray(arrA, n1); //leer el primer arreglo
  scanf("%d", &n2);
  readArray(arrB, n2); //leer el segundo arreglo
  n3=n1+n2;
  mergeArrays(arrA, n1, arrB, n2, arrC, n3);  //Fusionar los dos arreglos en un tercer arreglo

  sortArray(arrC, n3);  //Ordenar los elementos del tercer arreglo, recuerde que pueden
  //existir profesores repetidos

  printArray(arrC, n3);   //Imprimir el resultado final
}