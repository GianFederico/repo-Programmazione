#include <stdio.h>
#include <stdlib.h>

struct dipendente {
	int codice;
	char nome[20];
	int sin_tratt;
	int sin_concl;
	int compenso;
	int sin_da_tratt;
};

typedef struct dipendente DIPENDENTE;



void acquisisci_dipendenti(DIPENDENTE *vettore, int dim){
	int i=0;
	while (i<dim){
		printf("Inserisci il codice dipendente: ");
		scanf("%d",&vettore[i].codice);
		printf("Inserisci il nome del dipendente: ");
				scanf("%s",vettore[i].nome);
				printf("Inserisci il numero dei sinstri trattati: ");
						scanf("%d",&vettore[i].sin_tratt);
						printf("Inserisci il numero di sinistri conclusi: ");
								scanf("%d",&vettore[i].sin_concl);
								printf("Inserisci il compenso : ");
										scanf("%d",&vettore[i].compenso);

										vettore[i].sin_da_tratt = vettore[i].sin_tratt - vettore[i].sin_concl;

					printf("__________________________________________________\n");
					i++;
	}

}

void stampa_dipendenti(DIPENDENTE *vettore, int dim){
  int i=0;
  while (i<dim){
    printf("\nCODICE: %d\nNOME: %s\nSINISTRI TRATTATI: %d\nSINISTRI CONCLUSI: %d\nCOMPENSO: %d\nSINISTRI DA TRATTARE: %d\n",
        vettore[i].codice, vettore[i].nome, vettore[i].sin_tratt, vettore[i].sin_concl, vettore[i].compenso, vettore[i].sin_da_tratt);
    printf("_________________________________________________________________________________________________________________________\n");
  i++;
  }
}



void ordina_dipendenti(DIPENDENTE *vettore, int dim){
	int i=0;
	int pass=1;
	DIPENDENTE temp;

	while(pass<dim){
		i=0;
		while(i<dim){
			if(vettore[i].sin_da_tratt<vettore[i+1].sin_da_tratt){
				temp=vettore[i];
				vettore[i]=vettore[i+1];
				vettore[i+1]=temp;
			}
			i++;
		}
		pass=pass+1;
	}
}


void salva_file (FILE *file, DIPENDENTE *vettore, int dim){
	int i=0;
	if((file=fopen("dipendenti.txt","w"))!=NULL){
		while(i<dim){
			fprintf(file,"CODICE: %d   NOME:%s   SINISTRI TRATTATI: %d   SINISTRI CONCLUSI: %d   COMPENSO: %d   SINISTRI DA TRATTARE: %d\n",
				vettore[i].codice, vettore[i].nome, vettore[i].sin_tratt, vettore[i].sin_concl, vettore[i].compenso, vettore[i].sin_da_tratt);
		    fprintf(file,"__________________________________________________________________________________\n");
		i++;
		}
	}


}


//===============================================================
int main(){
	int dim;

	DIPENDENTE *vettore;
	FILE *file;


	printf("Quanti dipendenti vuoi registrare? ");
	scanf("%d",&dim);
	 while (dim==0){
		 printf("reinserisci il numero dei dipendenti da registrare: ");
		 scanf("%d",&dim);
	 }

	vettore=(DIPENDENTE*)malloc(dim*sizeof(DIPENDENTE));

	acquisisci_dipendenti(vettore,dim);
	system("pause");
	stampa_dipendenti(vettore,dim);
	system("pause");
	ordina_dipendenti(vettore,dim);
	printf("----------Dipendenti ordinati per sinistri ancora da concludere---------- \n");
	printf("\n");
	stampa_dipendenti(vettore,dim);

	file=fopen("dipendenti.txt","w");
   salva_file(file,vettore,dim);
	fclose(file);

	free(vettore);

	system("pause");
	return 0;
}
