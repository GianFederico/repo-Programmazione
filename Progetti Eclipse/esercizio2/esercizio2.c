#include <stdio.h>
#include<stdlib.h>
#include <math.h>



int main(){
	int n,k;
	printf("inserici il numero da moltiplicare n volte: ");
	scanf("%d",&k);

	printf("\nora inserisci l'elevamento a potenza: ");
	scanf("%d",&n);

	printf("\n%d %d", k,n);

int ris=0;
int i=1;

for(i=1;i<=n;i++){
	ris=ris+pow(k,i);
}

	printf("\nil risultato finale e': ");
	printf("%d\n", ris);

	system("pause");
	return 0;

}

