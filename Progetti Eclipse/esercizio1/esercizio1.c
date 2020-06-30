/*
 * esercizio1.c
 *
 *  Created on: 11 gen 2017
 *      Author: GianFederico
 */
//esercizio per confrontare 2 insiemi e stampare gli elementi uguali.

#include <stdio.h>
#include <stdlib.h>
#define DIM1 a
#define DIM2 b
#define DIM3 c

int a,b,c;

int main(){
	printf("inserisci la grandezza del primo insieme: ");
	scanf("%d",&a);
	printf("\ninserisci la grandezza del secondo insieme: ");
	scanf("%d", &b);

printf(" \n");

printf("ATTENZIONE! NON E' POSSIBILE INSERIRE PIU' VOLTE LO STESSO NUMERO.\n");


int vettore1[DIM1];
int i;
for(i=0; i<DIM1; ++i){
	printf("\ninserisci l'elemento del primo insieme nella posizione %d: ", (i+1));
	scanf("%d", &vettore1[i]);
}

printf(" \n");

int vettore2[DIM2];
int j;
for(j=0; j<DIM2; ++j){
	printf("inserisci l'elemento del secondo insieme nella posizione %d: ", (j+1));
	scanf("%d", &vettore2[j]);
}


int k=0;
int t=0;
int m=0;
int cont=0;
int vettore3[DIM3];


while(t<DIM2){
	k=0;
	while(k<DIM1){
		if(vettore1[k]==vettore2[t]){
			cont=cont+1;
			vettore3[m]= vettore1[k];
		m=m+1;
		}
		k=k+1;
	}
	 t=t+1;
 }
c=cont;

        printf("\n il primo insieme e'     : ");
        for(i=0; i<DIM1; ++i){
		  printf("%d ", vettore1[i]);
                  }

    printf("\n il secondo insieme e'   : ");
		          for(i=0; i<DIM2; ++i){
		  printf("%d ", vettore2[i]);
		          }

    printf("\n i numeri in comune sono : ");
		  		        for(i=0; i<DIM3; ++i){
		  printf("%d ", vettore3[i]);
		         }
      if(c==0){
    	  printf("ATTENZIONE! l'insieme non ha elementi.\n");
      }

printf(" \n");
	system ("pause");
	return 0;
}


