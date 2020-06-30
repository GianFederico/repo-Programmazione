//contare le vocali in una stringa
#include <stdio.h>
#include <stdlib.h>
#define MAX a

int a;

int main (){
    printf("inserisci il numero di caratteri da controllare, spazi inclusi:\n ");
    scanf("%d", &a);

 char stringa[MAX];

    printf("Digitare la stringa intera: ");
	scanf ("%s",stringa);

 int cont=0;
 int i=0;
	for(i=0;i<=MAX;i++){
		if (stringa[i]=='a'){
			cont=cont+1;
		}
		else if (stringa[i]=='e'){
			cont=cont+1;
		}
		else if (stringa[i]=='i'){
					cont=cont+1;
				}
		else if (stringa[i]=='o'){
					cont=cont+1;
				}
		else if (stringa[i]=='u'){
					cont=cont+1;
				}
	}
    printf("\n le vocali nella stringa sono:");
    printf("%d",cont);
	system ("pause");
	return 0;
}





