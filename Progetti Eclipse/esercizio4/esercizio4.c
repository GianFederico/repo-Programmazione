#include <stdio.h>
#include <stdlib.h>
#define DIM a

int a;

int main(){
	printf("Inserire la grandezza dell'insieme: ");
	scanf("%d", &a);
int i=0;
int insieme[DIM];

	while(i<DIM){
		printf("\nInserisci un numero dell'insieme compreso tra 18 e 90: ");
		scanf("%d",&insieme[i]);

		while(insieme[i]<18 || insieme[i]>90){
			printf("il numero inserito non e' valido, reinserire numero: ");
			scanf("%d",&insieme[i]);
		}
		i=i+1;
	}
int j=0;
	while(j<DIM){
		printf("%d ",insieme[j]);
		j=j+1;
	}

	int cont=0;
	  int valmax=0;
	  int temp=0;
	  int m=0;
	  int n;
	  while(m<DIM){
	    n=0;
	    temp=0;
	    while(n<DIM){
	      if(insieme[m]==insieme[n]){
	        temp=temp+1;
	      }
	      if(temp>=cont){
	        cont=temp;
	        valmax=insieme[m];
	      }
	      n=n+1;
	    }
	    m=m+1;
	  }
	  printf("\nIl valore piu' presente e': %d", valmax);


	system("pause");
	return 0;

}


