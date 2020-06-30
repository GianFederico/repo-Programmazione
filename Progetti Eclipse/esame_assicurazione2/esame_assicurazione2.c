#include <stdio.h>
#include <stdlib.h>
struct DIPENDENTE {
	int codice;
	char nome[20];
	int sin_tratt;
	int sin_concl;
	int sin_da_concl;
};

typedef struct DIPENDENTE DIPENDENTI;


void acquisisci_dipendenti (DIPENDENTI *vettore, int dim){
	int i=0;
	while (i<dim){
		printf("inserisci il codice del dipendente: ");
		scanf("%d", &vettore[i].codice);
		printf("inserisci il nome del dipendente: ");
				scanf("%s", vettore[i].nome);
				printf("inserisci il num. di sinistri trattati dal dipendente: ");
						scanf("%d", &vettore[i].sin_tratt);
						printf("inserisci il num. dei sinistri conclusi dal dipendente: ");
								scanf("%d", &vettore[i].sin_concl);
								printf("__________________________________________________________\n");

								vettore[i].sin_da_concl = vettore[i].sin_tratt-vettore[i].sin_concl;
								i++;
	}
}


void stampa_vettore(DIPENDENTI *vettore, int dim){
	int i=0;
	while(i<dim){
		printf("CODICE:%d   NOME:%s   SINISTRI TRATTATI:%d   SINISTRI CONCLUSI:%d   SINISTRI IN SOSPESO:%d \n",
				vettore[i].codice,vettore[i].nome, vettore[i].sin_tratt, vettore[i].sin_concl, vettore[i].sin_da_concl);
		printf("____________________________________________________________________________________________________\n");
		i++;
	}
}


void ordina_vettore(DIPENDENTI *vettore, int dim){
	int pass=1;
	int i=0;
	DIPENDENTI temp;

	printf("dipendenti ordinati per numero maggiore di sinistri da concludere:\n");
	while(pass<dim){
		i=0;
		while (i<dim){
			if (vettore[i].sin_da_concl<vettore[i+1].sin_da_concl){
				temp=vettore[i];
				vettore[i]=vettore[i+1];
				vettore[i+1]=temp;
			}
			i++;
		}
		pass++;
	}

}

void salva_file(FILE *file, DIPENDENTI *vettore, int dim){
	int i=0;
	if ((file=fopen("deependenti.txt","w"))!=NULL){
		while(i<dim){
			fprintf(file,"CODICE:%d   NOME:%s   SINISTRI TRATTATI:%d   SINISTRI CONCLUSI:%d   SINISTRI IN SOSPESO:%d \n",
				vettore[i].codice,vettore[i].nome, vettore[i].sin_tratt, vettore[i].sin_concl, vettore[i].sin_da_concl);
			fprintf(file, "____________________________________________________________________________________________________\n");
		i++;
		}
	}

}


//=====================================================================
int main(){

	int dim;
	DIPENDENTI *vettore;
	FILE *file;

	printf("Quanti dipendenti vuoi inserire?");
	scanf("%d",&dim);

	vettore=(DIPENDENTI*)malloc(dim*sizeof(DIPENDENTI));

	acquisisci_dipendenti(vettore,dim);
    stampa_vettore(vettore,dim);
    ordina_vettore(vettore, dim);
    stampa_vettore(vettore, dim);

    file=fopen("deependenti.txt","w");
    salva_file(file,vettore,dim);
    fclose(file);

    free(vettore);

	system("pause");
	return 0;
}
