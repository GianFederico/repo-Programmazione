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
	printf("%d", vett[posiz]);

}

void inversione_elementi(int vett1[DIM], int vett2[DIM]){
    int i=0;
    int j=0;
    int k=DIM;
	while(DIM!=0){
    	DIM=DIM-j;
		vett1[i]=vett2[DIM];
		i++;
		j++;
	}

   i=0;
 while(i<k){
	printf("%d ",vett1[i]);
	i++;
}
}



//_____________________________________

int main(){


	int vettore[DIM];

	printf("quanto deve essere grande il vettore? \n");
	scanf("%d", &a);

	acquisisci_vettore(vettore);
	system("pause");
	scrittura_elemento(vettore);
	system("pause");
	lettura_elemento(vettore);
	system("pause");
	inversione_elementi(vettore, vettore);
	system("pause");

    system("pause");
	return 0;
}


