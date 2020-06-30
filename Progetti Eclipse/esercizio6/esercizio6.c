#include <stdlib.h>
#include <stdio.h>
#define DIM a
int a;
struct data{int giorno; int mese; int anno;};
typedef struct data DATA;


void acquisisci_vettore(int vett[DIM]){

	int i=0;
	while (i<DIM){
		printf("inserisci l'elemento %d: ",i+1);
		scanf("%d", &vett[i]);
      i++;
	}
}

void stampa_vettore(int vett[DIM]){
	int i=0;
	while(i<DIM){
		printf("%d ",vett[i]);
		i++;
	}
}

void ordinamento_vettore(int vett[DIM]){
	int i=0;
	int temp;
	int pass=1;
	while(pass<DIM){
		i=0;
	while(i<DIM){
		if(vett[i]>vett[i+1]){
			temp=vett[i];
			vett[i]=vett[i+1];
			vett[i+1]=temp;
		}
		i++;
	}
	pass=pass+1;
	}
}







//=======================================
int main(){


	int vettore[DIM];
	printf("quanto deve essere grande il vettore? ");
	scanf("%d", &a);

	acquisisci_vettore(vettore);
	system("pause");
	stampa_vettore(vettore);
    system("pause");
    ordinamento_vettore(vettore);
    system("pause");
    stampa_vettore(vettore);

	system("pause");
	return 0;
}
