#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DIM a
int a;

void acquisisci_vettore(int vett[DIM]){
	 int i=0;
	 while(i<DIM){
		 printf("inserisci elemento: ");
		 scanf("%d", &vett[i]);
		 i++;
	 }
 }

void scrittura_elemento(int vett[DIM]){
	int b;
	int valore;
	printf("\nin che posizione vuoi scrivere l'elemento? (partendo da 0) ");
	scanf("%d",&b);

    printf("\nche valore vuoi assegnare a quella posizione? ");
    scanf("%d", &valore);

    vett[b]=valore;

    int i=0;
    while(i<DIM){
    	printf("%d ", vett[i]);
    	i++;
    }
}

void lettura_elemento(int vett[DIM]){
	int posiz;
	printf("il valore di quale posizione vuoi conoscere (partendo da 0): ");
	scanf("%d",&posiz);

	printf("\nil valore in posizione %d e': ", posiz);
	printf("%d \n", vett[posiz]);

}

void inversione_elementi(int vett1[DIM]){
   int vett2[DIM];
   	int i=0;
	while(i<DIM){
		vett2[i]=vett1[i];
		i++;
	}
	i=0;
    int k=DIM;
	while(k>0){
    	k=k-1;
		vett1[i]=vett2[k];
		i++;
	}
   i=0;
 while(i<DIM){
	printf("%d ",vett1[i]);
	i++;
}
 printf("\n");
}

void conteggio_presenze(int vett[DIM]){
	int n;
	int cont=0;
	int i=0;
	printf("di quale valore si vogliono cercare le occorrenze? ");
	scanf("%d", &n);

	while(i<=DIM){
		if (vett[i]==n){
			cont=cont+1;
		}

		i++;
	}

	printf("il valore cercato e' presente %d volte.",cont);
}

void somma_elementi(int vett[DIM]){
	int i=0;
	int somma=0;
	while (i<DIM){
		somma=somma+vett[i];
	    i++;
	}
	printf("la somma degli elementi del vettore e': %d ", somma);
}
void molt_elementi(int vett[DIM]){
	int i=0;
	int molt=1;
	while (i<DIM){
		molt=molt*vett[i];
	    i++;
	}
	printf("la moltiplicazione degli elementi del vettore e': %d ", molt);
}

//_____________________________________

int main(){


	int vettore1[DIM];

	printf("quanto deve essere grande il vettore? \n");
	scanf("%d", &a);

	acquisisci_vettore(vettore1);
	system("pause");
	scrittura_elemento(vettore1);
	system("pause");
	lettura_elemento(vettore1);
	system("pause");
	inversione_elementi(vettore1);
	system("pause");
	conteggio_presenze(vettore1);
	system("pause");
	somma_elementi(vettore1);
	system("pause");
	molt_elementi(vettore1);
	system("pause");

	return 0;
}



