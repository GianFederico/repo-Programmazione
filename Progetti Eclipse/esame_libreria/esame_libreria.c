#include <stdio.h>
#include <stdlib.h>
#define dim 3

struct dati_libro{
	int codice;
	char titolo[20];
	char autore[20];
	int copie_disponibili;
	int copie_minime;
	int anno;
};

typedef struct dati_libro LIBRI;

//========================================================

void acquisisci_libro (LIBRI vettore[dim]){
	int i=0;
	while(i<dim) {
	printf("Inserisci il codice a 5 cifre del libro n.%d: " ,i+1);
		scanf("%d",&vettore[i].codice);
		printf("Inserisci il titolo del libro n.%d: " ,i+1);
				scanf("%s",&vettore[i].titolo);
				printf("Inserisci l'autore del libro n.%d: " ,i+1);
						scanf("%s",&vettore[i].autore);
						printf("Inserisci il num. di copie disponibili del libro n.%d: " ,i+1);
								scanf("%d",&vettore[i].copie_disponibili);
								printf("Inserisci il num. minimo di copie del libro n.%d: " ,i+1);
										scanf("%d",&vettore[i].copie_minime);
										printf("Inserisci l'anno del libro n.%d: " ,i+1);
												scanf("%d",&vettore[i].anno);
						printf("________________________________________________________\n");
						i++;
	}
}



void stampa_libri(LIBRI vettore[dim]){
	int i=0;
	printf("\n");
	while(i<dim){
		printf("CODICE:%d  TITOLO:%s  AUTORI:%s  COPIE DISPONIBILI:%d  COPIE MINIME:%d  ANNO:%d", vettore[i].codice, vettore[i].titolo,
				vettore[i].autore, vettore[i].copie_disponibili, vettore[i].copie_minime, vettore[i].anno);
		printf("\n");
		printf("\n");
		i++;
	}
}



void controlla_copie(LIBRI vettore[dim]){
	int i=0;
	int k;
	while(i<dim){
		if(vettore[i].copie_disponibili < vettore[i].copie_minime){
			printf("Bisogna rifornirsi di copie de: %s ",vettore[i].titolo);
			k= vettore[i].copie_minime-vettore[i].copie_disponibili;
			printf("(%d copie). \n",k);
		}
		else{
			printf("Non c'e' bisogno di copie per il libro: %s. \n", vettore[i].titolo);
		}
			i++;
	}
}



void ordina_libri(LIBRI vettore[dim]){
	int i=0;
	int pass=1;
	LIBRI temp;

	printf("_________________________________________\n");
	printf("Libri ordinati secondo l'anno di pubblicazione: \n");

	 while(pass<dim){
		 i=0;
		while(i<dim){
			if(vettore[i].anno > vettore[i+1].anno){
					temp=vettore[i];
					vettore[i]=vettore[i+1];
					vettore[i+1]=temp;
				}
				i++;
			}
		 pass++;
	 }

}


void prenotazione (LIBRI vettore[dim]){
	int k=0;
	int j=0;
	int i=0;
	int risp=0;

	printf ("Inserisci il codice del libro che si desidera prenotare: ");
	scanf ("%d",k);
	printf("In quale quantita'? ");
	scanf ("%d",j);

	while(i<dim){
		if (k==vettore[i].codice){
			if (j<=vettore[i].copie_disponibili){
				printf("PRENOTAZIONE EFFETTUATA: x%d %s.\n",j,vettore[i].titolo);
			}
			else{
				printf("PRENOTAZIONE FALLITA: rimangono solo %d copie di %s.\n",vettore[i].copie_disponibili, vettore[i].titolo);
			}
		}
		i++;
	}
	printf("Vuoi prenotare altri libri? 1 per prenotare ancora, 0 per terminare la prenotazione: ");
			scanf("%d",risp);
			if(risp==1){
				prenotazione(vettore);
			}
			else{
				printf("Grazie e arrivederci!");
			}

}



void scrivi_file (FILE *file, LIBRI vettore[dim]){
	int i=0;
	if((file=fopen("libreria.txt","w"))!=NULL){
		while(i<dim){
			fprintf(file, "CODICE:%d  TITOLO:%s  AUTORI:%s  COPIE DISPONIBILI:%d  COPIE MINIME:%d  ANNO:%d \n", vettore[i].codice, vettore[i].titolo,
				vettore[i].autore, vettore[i].copie_disponibili, vettore[i].copie_minime, vettore[i].anno);
			fprintf(file,"________________________________________________________________\n");
			i++;
		}
	}





}


int main(){
	LIBRI vettore[dim];
	FILE *file;



	acquisisci_libro(vettore);
	stampa_libri(vettore);
    controlla_copie(vettore);
    ordina_libri(vettore);
    stampa_libri(vettore);

    file=fopen("elenco.txt","r");
    scrivi_file(file,vettore);
    fclose(file);





	system("pause");
	return 0;
}
