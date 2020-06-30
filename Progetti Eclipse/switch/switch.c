/*
 * switch.c
 *
 *  Created on: 19 dic 2016
 *      Author: GianFederico
 */
#include <stdio.h>
#include <stdlib.h>

int numero;
float importo, impfinale;


int main(){

	printf("inserici l'importo:  ");
	scanf("%f", &importo);

	printf("adesso scegli una delle seguenti operazioni: \n");
	printf("- premi 1 per uno sconto del 10percento  \n");
	printf("- premi 2 per uno sconto del 20percento  \n");
	printf("- premi 3 per uno sconto del 30percento  \n");
	printf("- premi 4 per un aumento del 10percento \n");
	printf("- premi 5 per uscire \n");
	scanf("%d",&numero);

	impfinale=importo;
//costrutto switch(numero del caso)
   switch(numero){

 	 case 1:

		impfinale*=.9;
		printf("l'importo scontato del 10percento risulta:  %.2f ",impfinale);
		break;
	 case 2:
		impfinale*=.8;
		printf("l'importo scontato del 20percento risulta:  %.2f ",impfinale);
				break;
	 case 3:
		impfinale*=.7;
		printf("l'importo scontato del 30percento risulta:   %.2f ",impfinale);
				break;
	 case 4:
		impfinale*=1.1;
		printf("l'importo con un amento del 10percento risulta:  %.2f ",impfinale);
				break;
	 case 5:
		printf("hai scelto di non effettuare alcuna operazione.");
				break;
		}

	system("pause");
	return 0;
}

