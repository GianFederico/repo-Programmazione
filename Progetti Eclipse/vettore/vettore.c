/*
 * vettore.c
 *
 *  Created on: 19 dic 2016
 *      Author: GianFederico
 */
#include <stdio.h>
#include <stdlib.h>
//definizione lunghezza del vettore
#define MAX 5

int main(){
//dichiarazone nel main del vettore
	int vettore[MAX];
	int i;
//ciclo for (partenza;condizione;incremento)
	  for(i=0; i<MAX; ++i){
		printf("inserisci il valore %d:  ", (i+1));
		scanf("%d", &vettore[i]);
	  }

	  printf("il vettore che hai caricato e'...\n \n");

	  system("pause");

	  printf("la suspance \n \n");
	  system ("pause");

	  for(i=0; i<MAX; ++i){
		  printf("%d ", vettore[i]);
	  }
	system("pause");
	return 0;
}

