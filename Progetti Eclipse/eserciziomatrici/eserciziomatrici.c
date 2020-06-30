#include <stdio.h>
#include <stdlib.h>
#define RIGHE a
#define COLONNE b
int a,b;


void genera_matrix (float matrix[RIGHE][COLONNE]){
	printf("\aquante righe avranno le matrici? ");
	scanf("%d", &a);
	printf("quante colonne avranno le matrici? ");
	scanf("%d", &b);
}

void inserisci_elementi(float matrix[RIGHE][COLONNE]){
	int i=0;
	int j=0;

	while(i<RIGHE){
		j=0;
		while(j<COLONNE){
			printf("inserisci il valore in posizione %d,%d: ", i+1,j+1);
			scanf("%f", &matrix[i][j]);
			j=j+1;
		}
	i=i+1;
	}

}

void stampa_matrix(float matrix[RIGHE][COLONNE]){
	int i=0;
	int j=0;
	while(i<RIGHE){
		j=0;
		while(j<COLONNE){
			printf("%.2f  ", matrix[i][j]);
			j++;
	     }
	printf("\n");
	i++;
	}

}

void somma_matrix(float matrix1[RIGHE][COLONNE],float matrix2[RIGHE][COLONNE], float matrixSOM[RIGHE][COLONNE]){
	int i=0;
    int	j=0;
	while(i<RIGHE){
		j=0;
				while(j<COLONNE){
					matrixSOM[i][j]=matrix1[i][j]+matrix2[i][j];
					j=j+1;
				}
		i=i+1;
	}

}



//=========================================================
int main(){
	float matrix1[RIGHE][COLONNE];
	float matrix2[RIGHE][COLONNE];
	float matrixSOMMA[RIGHE][COLONNE];

	genera_matrix(matrix1);
	system("pause" );
	inserisci_elementi(matrix1);
	system("pause");
	inserisci_elementi(matrix2);
	system("pause");
	stampa_matrix(matrix1);
	system("pause");
	stampa_matrix(matrix2);
	system("pause");
	somma_matrix(matrix1,matrix2,matrixSOMMA);
	system("pause");
	stampa_matrix(matrixSOMMA);







   system("pause");
   return 0;
}

