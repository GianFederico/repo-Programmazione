#include <stdio.h>
#include <stdlib.h>

#define dim 3


struct volo {
	int codice;
	char citta_partenza[20];
	char citta_destinazione[20];
	int tot_posti;
	int posti_occupati;
};
typedef struct volo VOLO;



void acquisisci_voli (VOLO vettore[dim]) {
 int i=0;
 while (i<dim){
	printf("inserisci il codice del volo: ");
		scanf("%d",&vettore[i].codice);
		printf("inserisci la citta' di partenza del volo: ");
				scanf("%s",&vettore[i].citta_partenza);
				printf("inserisci la citta' di arrivo del volo: ");
						scanf("%s",&vettore[i].citta_destinazione);
						printf("inserisci il total dei posti del volo: ");
								scanf("%d",&vettore[i].tot_posti);
								printf("inserisci numero di posti occupati: ");
										scanf("%d",&vettore[i].posti_occupati);
										printf("________________________________________\n");

										i++;
	}

}


void stampa_voli (VOLO vettore[dim]){
	int i=0;
	while (i<dim){
		printf("CODICE:%d    PARTENZA DA: %s    ARRIVO A: %s    TOT. POSTI:%d    POSTI OCCUPATI:%d \n", vettore[i].codice, vettore[i].citta_partenza,
				vettore[i].citta_destinazione, vettore[i].tot_posti, vettore[i].posti_occupati);
		printf("-----------------------------------------------------------------------------------------------\n");
		i++;
	}
}


void prenotazione (VOLO vettore[dim]){
 int i=0;
 int b;
 int c;
 int d;

 printf("quanti posti vuoi prenotare? ");
 scanf ("%d",&b);

 printf("inserisci il codice del volo che vuoi prenotare: ");
 	scanf("%d",&c);

 while (i<dim){
	 if (c==vettore[i].codice){
		d=vettore[i].tot_posti-vettore[i].posti_occupati;
		 printf("posti disponibili per questo volo: %d \n",d);
		 system("pause");
		 if(b<d){
			 printf("prenotazione effettuata! \n");
			 d=d-b;
			 printf("posti attualmente disponibili: %d", d);
		 }
		 else{
			 printf("posti non sufficienti, prenotazione fallita. \n");
		 }

	 }
	 i++;
 }

}

void ordina_voli (VOLO vettore[dim]){
	int i=0;
	VOLO temp;
	int pass=1;
	printf("____________________________________________________________\n");
	while(pass<dim){
		i=0;
				while(i<dim){
					if(vettore[i].posti_occupati < vettore[i+1].posti_occupati){
						temp=vettore[i];
					    vettore[i]=vettore[i+1];
						vettore[i+1]=temp;

					}
					i++;
				}
		pass++;
	}

}

void salva_file(FILE *file, VOLO vettore[dim]){
	int i=0;
	if((file=fopen("voli.txt","w"))!=NULL){
		while(i<dim){
		fprintf(file, "CODICE:%d    PARTENZA DA: %s    ARRIVO A: %s    TOT. POSTI:%d    POSTI OCCUPATI:%d \n", vettore[i].codice, vettore[i].citta_partenza,
				vettore[i].citta_destinazione, vettore[i].tot_posti, vettore[i].posti_occupati);
		fprintf(file, "-----------------------------------------------------------------------------------------------\n");
		i++;
	}
	}
}



int main(){

	VOLO vettore[dim];
	FILE *file;


	acquisisci_voli(vettore);
	stampa_voli(vettore);
	ordina_voli(vettore);
	stampa_voli(vettore);
	prenotazione(vettore);

	file=fopen("voli.txt","r");
    salva_file(file, vettore);
	fclose(file);


	system("pause");
	return 0;
}
