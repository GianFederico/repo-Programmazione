#include <stdio.h>
#include <stdlib.h>

struct info{
	int codice;
	char editore[20];
	char nome[20];
	char fumetto[20];
	int anno;
};
typedef struct info PG;


//==========================================================
void acquisizione_dati (PG *elenco, int dim){
	int i=0;

	while(i<dim){
	   printf("Inserire il codice del personaggio n.%d: ",i+1);
		scanf("%d",&elenco[i].codice);
	   printf("Inserire l'editore del personaggio n.%d: ",i+1);
		scanf("%s",&*(elenco[i]).editore);
	   printf("Inserire il nome del personaggio n.%d: ",i+1);
		scanf("%s",&*(elenco[i]).nome);
	   printf("Inserire il fumetto da cui e' preso il personaggio n.%d: ",i+1);
		scanf("%s",&*(elenco[i]).fumetto);
	   printf("Inserire l'anno di nascita del personaggio n.%d: ",i+1);
		scanf("%d",&elenco[i].anno);
	   printf("______________________________________\n");
		printf("\n");
		i=i+1;
	}
}


void stampa_elenco(PG *elenco, int dim){
	 int i=0;
			 while(i<dim){
	         printf("CODICE: %d \n", elenco[i].codice);
	         printf("EDITORE: %s \n", elenco[i].editore);
	         printf("NOME: %s \n", elenco[i].nome);
	         printf("FUMETTO: %s \n", elenco[i].fumetto);
	         printf("ANNO : %d \n", elenco[i].anno);
	         printf("____________________________\n");

	         i=i+1;
			 }
}


void ordinamento_elenco(PG *elenco, int dim){
	int i=0;
	int pass=1;
	PG temp;
	while (pass<dim){
		i=0;
	while(i<dim){
		if (elenco[i].anno>elenco[i+1].anno){
			temp=elenco[i];
			elenco[i]=elenco[i+1];
			elenco[i+1]=temp;
		}
			i=i+1;
		}
		pass=pass+1;
	}
}


void stampa_elenco_ordinato(PG *elenco, int dim){
	printf("****** Elenco ordinato ****** \n");
	printf("\n");
	int i=0;
	while(i<dim){
		  printf("CODICE: %d \n", elenco[i].codice);
		  printf("EDITORE: %s \n", elenco[i].editore);
		  printf("NOME: %s \n", elenco[i].nome);
		  printf("FUMETTO: %s \n", elenco[i].fumetto);
		  printf("ANNO : %d \n", elenco[i].anno);
		  printf("____________________\n");
		  i=i+1;
	}
}


void salva_elenco(PG *elenco, int dim, FILE *file){
	int i=0;

	if((file=fopen("elenco.txt","w"))!=NULL){
     while(i<dim){
    	 fprintf(file, "%d, %s, %s, %s, %d", elenco[i].codice, elenco[i].editore, elenco[i].nome, elenco[i].fumetto, elenco[i].anno);
      i=i+1;
     }
	}
	else{
		printf("Il file non puo' essere aperto. \n");
	}
}

//============================================================
int main(){
	FILE *file;
	file=fopen("elenco.txt","w");
	int dim;
    PG *elenco;
	printf("Quanti personaggi vuoi inserire? ");
	scanf("%d", &dim);
	elenco=(PG*)malloc(dim*sizeof(PG));

 acquisizione_dati(elenco, dim);
 stampa_elenco(elenco, dim);
 ordinamento_elenco(elenco, dim);
 stampa_elenco_ordinato(elenco, dim);
 system("pause");
 salva_elenco(elenco, dim, file);

    free(elenco);
    fclose(file);
  system("pause");
	return 0;
}
