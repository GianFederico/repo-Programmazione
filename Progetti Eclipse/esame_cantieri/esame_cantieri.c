#include <stdio.h>
#include <stdlib.h>

struct cantiere{
	char nome_ing [20];
	char cognome_ing[20];
	char city [20];
	char via[20];
	int civico;
	int num_op;
	int apertura;
	int chiusura;
};
typedef struct cantiere CANTIERE;


void acquisisci_dati(CANTIERE *vettore, int dim){
	int i=0;
	while (i<dim){
	printf("Inserisci il nome dell' ing. responsabile: ");
		scanf("%s",vettore[i].nome_ing);
		printf("Inserisci il cognome dell' ing. responsabile: ");
				scanf("%s",vettore[i].cognome_ing);
				printf("Inserisci la citta' del cantiere: ");
						scanf("%s",vettore[i].city);
						printf("Inserisci la via del cantiere: ");
								scanf("%s",vettore[i].via);
								printf("Inserisci il n.civico del cantiere: ");
										scanf("%d",&vettore[i].civico);
										printf("Inserisci il n. degli operai del cantiere: ");
												scanf("%d",&vettore[i].num_op);
												printf("Inserisci l'anno di apertura del cantiere: ");
														scanf("%d",&vettore[i].apertura);
														printf("Inserisci l'anno di chiusura del cantiere: ");
																scanf("%d",&vettore[i].chiusura);

								printf("_____________________________________________________\n");
								i++;
		}
}



void stampa_vettore (CANTIERE *vettore,int dim){
	int i=0;
	while(i<dim){
		printf(" NOME ING.:%s\n COGNOME ING.:%s\n CITTA':%s\n VIA:%s\n CIVICO:%d\n NUM.OPERAI:%d\n ANNO APERTURA:%d\n ANNO CHIUSURA:%d\n",
				vettore[i].nome_ing, vettore[i].cognome_ing,vettore[i].city,vettore[i].via,vettore[i].civico,vettore[i].num_op,vettore[i].apertura,vettore[i].chiusura);
			printf("______________________________________\n");
			i++;
	}
}


void responsabile_cantieri (CANTIERE *vettore, int dim){
	int i=0;
	char cognome[20];
	int cont=0;
	printf("Inserisci il cognome dell'ing. da ricercare:");
	scanf("%s",cognome);

	printf("Cantieri di cui e' responsabile l'ing.%s:\n",cognome);
	while(i<dim){
		if(*cognome==*vettore[i].cognome_ing){
			printf(" CITTA':%s\n VIA:%s\n CIVICO:%d\n NUM.OPERAI:%d\n ANNO APERTURA:%d\n ANNO CHIUSURA:%d\n",
				vettore[i].city,vettore[i].via,vettore[i].civico,vettore[i].num_op,vettore[i].apertura,vettore[i].chiusura);
			printf("___________________________________________________________________\n");
			cont=cont+1;
		}
		i++;
	}
		if(cont==0){
			printf("l'ing.%s non e' in elenco\n", cognome);

	}
}



void apertura_chiusura (CANTIERE *vettore, int dim){
	int i=0;
	int anno;
	printf("inserisci l'anno in cui vuoi controllare: ");
	scanf("%d",&anno);

	while(i<dim){
		if(anno <= vettore[i].chiusura){
			if(vettore[i].apertura <= anno){
				printf("Cantiere n.%d nell'anno %d, risulta essere APERTO\n", i+1, anno);
			}
			else{
				printf("Cantiere n.%d nell'anno %d, risulta essere CHIUSO\n", i+1, anno);
			}

		}
		else{
						printf("Cantiere n.%d nell'anno %d, risulta essere CHIUSO\n", i+1, anno);
					}
		i++;
	}
}



void ordina_vettore (CANTIERE *vettore, int dim){
	int i=0;
	int pass=1;
	CANTIERE temp;

	printf("\n");
	printf("Cantieri ordinati per numero di operai:\n");

	while(pass<dim){
		i=0;
		while(i<dim){
		if(vettore[i].num_op < vettore[i+1].num_op){
			temp=vettore[i];
			vettore[i]=vettore[i+1];
			vettore[i+1]=temp;
		}
		i++;
	}
 pass++;
  }
}



void salva_file (FILE *file, CANTIERE *vettore, int dim){
	int i=0;
	if((file=fopen("cantieri.txt","w"))!=NULL){
		while(i<dim){
			fprintf(file,"NOME ING.:%s\n COGNOME ING.:%s\n CITTA':%s\n VIA:%s\n CIVICO:%d\n NUM.OPERAI:%d\n ANNO APERTURA:%d\n ANNO CHIUSURA:%d\n",
				vettore[i].nome_ing, vettore[i].cognome_ing,vettore[i].city,vettore[i].via,vettore[i].civico,vettore[i].num_op,vettore[i].apertura,vettore[i].chiusura);
			fprintf(file,"__________________________________________________________\n");
			i++;
		}
	}

}



//===========================================================
int main(){
	int dim;
	CANTIERE *vettore;
	FILE *file;

	printf("Quanti cantieri vuoi salvare? ");
	scanf("%d",&dim);
	while(dim==0){
		printf("reinserisci il numero: ");
		scanf("%d",&dim);
	}

	vettore=(CANTIERE*)malloc(dim*sizeof(CANTIERE));

	acquisisci_dati(vettore,dim);
	stampa_vettore(vettore,dim);
	system("pause");
	ordina_vettore(vettore,dim);
	stampa_vettore(vettore,dim);
	system("pause");
	responsabile_cantieri(vettore,dim);
	system("pause");
	apertura_chiusura(vettore,dim);
	system("pause");

    file=fopen("cantieri.txt","w");
    salva_file(file,vettore,dim);
    fclose(file);


	system("pause");
	return 0;
}
