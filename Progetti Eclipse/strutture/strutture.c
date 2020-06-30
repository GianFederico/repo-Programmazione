#include <stdlib.h>
#include <stdio.h>

struct data{int giorno; int mese; int anno;};
typedef struct data DATA;

int main(){
	DATA data1;
	printf("inserisci giorno: ");
	scanf("%d", &data1.giorno);
	printf("inserisci mese: ");
	scanf("%d", &data1.mese);
	printf("inserisci anno: ");
	scanf("%d", &data1.anno);

	printf("\n %d %d %d ", data1.giorno, data1.mese, data1.anno);
	system("pause");
}

