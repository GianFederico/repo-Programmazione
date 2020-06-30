#include <stdio.h>
#include <stdlib.h>
struct sup {
	char nome[25];
	char citta[20];
	char via[20];
	int n_civico;
	int num_dip;
	int fatt;
};
typedef struct sup SUPER;


void acquisisci_elementi (SUPER *vettore, int dim){
	int i=0;
	while (i<dim){
		    printf("Inserisci il nome del responsabile nella forma ''mario_rossi'' : ");
		        scanf("%s",vettore[i].nome);
		    printf("Inserisci la citta' del supermercato : ");
				scanf("%s",vettore[i].citta);
			printf("Inserisci la via del supermercato : ");
				scanf("%s",vettore[i].via);
			printf("Inserisci il numero civico del supermercato : ");
				scanf("%d",&vettore[i].n_civico);
			printf("Inserisci il numero dei dipendenti del supermercato : ");
				scanf("%d",&vettore[i].num_dip);
			printf("Inserisci il fatturato annuo del supermercato : ");
				scanf("%d",&vettore[i].fatt);
			printf("_____________________________________________________________\n");

				i++;
	}

}



void stampa_supermercati (SUPER *vettore, int dim){
	int i=0;
	while (i<dim){
		printf("NOME RESP.: %s   CITTA': %s   VIA: %s   N.CIVICO: %d   N.DIPENDENTI: %d   FATTURATO: %d \n",
				vettore[i].nome, vettore[i].citta, vettore[i].via, vettore[i].n_civico, vettore[i].num_dip, vettore[i].fatt);
		printf("_____________________________________________________________\n");
		i++;
	}
}



void ordina_supermercati (SUPER *vettore, int dim){
	int i=0;
	int pass=1;
	SUPER temp;

	printf("Supermercati in ordine decrescente di numero dipendenti:\n");
	printf("\n");
	while (pass<dim){
		i=0;
		while(i<dim){
			if (vettore[i].num_dip < vettore[i+1].num_dip){
				temp=vettore[i];
				vettore[i]=vettore[i+1];
				vettore[i+1]=temp;
			}
			i++;
		}
		pass++;
	}
}



void nome_responsabile (SUPER *vettore, int dim){
	char nome[25];
	int i=0;
	int temp;
	printf("Inserisci il nome del responsabile del supermercato da ricercare: ");
	scanf("%s",nome);

	while(i<dim){
		if (*nome==*vettore[i].nome){
			printf("Dati del supermercato: \n");
			printf("NOME RESP.: %s   CITTA': %s   VIA: %s   N.CIVICO: %d   N.DIPENDENTI: %d   FATTURATO: %d \n",
			vettore[i].nome, vettore[i].citta, vettore[i].via, vettore[i].n_civico, vettore[i].num_dip, vettore[i].fatt);
		        }
	i++;
	}

	temp=dim-1;
	if(i==temp){
					printf("\nIl responsabile non e' in elenco.");
	   }

}


void presenze (SUPER *vettore, int dim){
     char city[20];
     int i;
     int cont=0;

     printf("Inserisci la citta' in cui controllare quanti upermercati ci sono: ");
     scanf("%s",city);

     while(i<dim){
    	 if (*city==*vettore[i].citta){
    		 cont=cont+1;
    	 }
    	 i++;
     }

     printf("Nella citta' selezionata ci sono %d supermercati",*city);
}





//==============================================================================
int main(){
int dim;

	SUPER *vettore;

	printf("Quanti supermercati vuoi registrare? ");
	scanf("%d",&dim);

	vettore=(SUPER*)malloc(dim*sizeof(SUPER));


	acquisisci_elementi(vettore, dim);
	stampa_supermercati(vettore, dim);
	ordina_supermercati(vettore, dim);
	stampa_supermercati(vettore, dim);
	nome_responsabile(vettore, dim);
	presenze(vettore, dim);





	system("pause");
	return 0;
}
