#include <stdio.h>
#include <stdlib.h>

struct info{
	int codice;
	char editore[15];
	char nome[15];
	char fumetto[15];
	int anno;
};
typedef struct info PG;


void acquisisci_dati (PG *vettore, int dim){
	int i=0;
	while(i<dim){

     printf("Inserisci il codice del personaggio n.%d: ",i+1);
	     scanf("%d", &vettore[i].codice);
	         printf("Inserisci il nome dell'editore: ");
	     	      scanf("%s", &*vettore[i].editore);
	     	          printf("Inserisci il nome: ");
	      	    	       scanf("%s", &*vettore[i].nome);
	      	    	      printf("Inserisci il fumetto: ");
	     	    	            scanf("%s", &*vettore[i].fumetto);
	     	    	           printf("Inserisci l'anno di nascita: ");
	     	    	         	     scanf("%d", &vettore[i].anno);
	                   printf("_______________________________________________\n");
	                   printf("\n");
	i++;
	}
}



void stampa_vettore (PG *vettore, int dim){
	int i=0;
   while(i<dim){
	   printf("%d %s %s %s %d \n", vettore[i].codice, vettore[i].editore, vettore[i].nome, vettore[i].fumetto, vettore[i].anno);

	   i++;
   }

   printf("\n");

}



void ordina_vettore(PG *vettore, int dim){
	int i=0;
	int pass=1;
	PG temp;
	while(pass<dim){
		i=0;
		while(i<dim){
			if(vettore[i].anno>vettore[i+1].anno){
		       temp=vettore[i];
				vettore[i]=vettore[i+1];
				vettore[i+1]=temp;
			}
			i++;
		}
		pass=pass+1;
	}
}



void salva_file(FILE *file, PG *vettore, int dim){
	int i=0;
	if((file=fopen("elenco.txt","w"))!=NULL){
		while(i<dim){
			fprintf(file, "%d %s %s %s %d \n",  vettore[i].codice, vettore[i].editore, vettore[i].nome, vettore[i].fumetto, vettore[i].anno);
			i++;
		}
	}
	else {
		printf("il file non può essere aperto. \n");
	}
}



void stampa_da_data (FILE *file, PG *vettore, int dim){
	int data;
	int i=0;
	printf("Da che anno vuoi stampare? ");
	scanf("%d", &data);

	if((file=fopen("elenco.txt","r"))!=NULL){
		while(i<dim){
			if(vettore[i].anno>data){
				fscanf(file,"%d %s %s %s %d \n", vettore[i].codice, vettore[i].editore, vettore[i].nome, vettore[i].fumetto, vettore[i].anno);
			    printf("%d %s %s %s %d \n", vettore[i].codice, vettore[i].editore, vettore[i].nome, vettore[i].fumetto, vettore[i].anno);
			}
		i++;
		}
	}
}

//===========================================================================
int main(){

int dim;
	FILE *file;
    PG *vettore;
    printf("Quanti personaggi vuoi salvare? ");
    scanf("%d", &dim);

    vettore=(PG*)malloc(dim*sizeof(PG));
    file=fopen("elenco.txt","w");

 acquisisci_dati(vettore, dim);
 stampa_vettore(vettore, dim);
 ordina_vettore(vettore, dim);
 stampa_vettore(vettore, dim);
 salva_file(file,vettore, dim);
 fclose(file);
 file=fopen("elenco.txt","r");
 stampa_da_data(file, vettore, dim);

    fclose(file);
    system("pause");
	free(vettore);
	return 0;
}
