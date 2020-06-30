#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
int a,b,c,a1,b1,c1,tot_carte;
#define DIM 40

struct carta{
	char *tipo;
	char *sottotipo;
};
typedef struct carta CARTA;




void acquisisci_carta (int a, int b, int c, int tot_carte){
	printf("Quante carte Mostro ci sono nel deck? ");
	scanf("%d",&a);
	printf("Quante carte Magia ci sono nel deck? ");
	scanf("%d",&b);
	printf("Quante carte Trappola ci sono nel deck? ");
	scanf("%d",&c);

	tot_carte=a+b+c;
	printf("Nel deck ci sono %d carte. ", tot_carte);
}




void acquisisci_tipo (int a1, int b1,int c1, int a, int b,int c){
	    if(a>0){
	printf("Quante carte Mostro con effetto ci sono nel deck? ");
    scanf("%d",&a1);
   	 a=a-a1;
     }
		if(b>0){
	printf("Quante carte Magia continue ci sono nel deck? ");
	scanf("%d",&b1);
	b=b-1;
	}
		if(c>0){
	printf("Quante carte Trappola continue ci sono nel deck? ");
	scanf("%d",&c1);
	c=c-1;
	}
}




int main(){

	srand(time(NULL));

	acquisisci_carta(a,b,c,tot_carte);
	acquisisci_tipo(a,b,c,a1,b1,c1);
	system("pause");
	return 0;
}
