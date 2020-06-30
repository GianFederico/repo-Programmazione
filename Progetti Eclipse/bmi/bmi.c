/*
 * bmi.c
 *
 *  Created on: 16 dic 2016
 *      Author: GianFederico
 */
#include <stdio.h>
#include <stdlib.h>

float bmi,altezza,peso;

int main(){

	printf("inserisci la tua altezza in metri (es: 1.70): ");
    scanf("%f", &altezza);
	printf("adesso inserisci il tuo peso in kg (es: 63): ");
    scanf("%f", &peso);

    bmi=peso/(altezza*altezza);

    printf("il tuo indice di massa corporea e': %.2f \n", bmi);
//costrutto if - else if - else
        if(bmi<16){
        	printf("sei gravemente sottopeso. \n");
        }

    	else if (bmi>=16 && bmi<=19){
    		printf("sei leggermente sottopeso. \n");
    	}

		else if	(bmi>19 && bmi<=25){
			printf("sei normopeso. \n");
		}
		else if	(bmi>25.1 && bmi<=30){
					printf("sei leggermente sovrappeso. \n");
		}
		else {
					printf("sei gravemente sovrappeso. \n");
    	}

  system("pause");
  return 0;
}

