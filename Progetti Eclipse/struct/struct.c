#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DIM 52

struct carta {
	char *valore;
	char *seme;
};

typedef struct carta CARTA;

void crea_mazzo(CARTA*MAZZO, char*valore[], char*seme[]){
	int i=0;
	while(i<DIM){
		MAZZO[i].valore=valore[i%13];
		MAZZO[i].seme=seme[i/13];
		i=i+1;
	}
}



void mescola_mazzo (CARTA *MAZZO){
	int i=0;
	int j=0;
	CARTA temp;
	while(i<DIM){
	j= rand() % 51;
	temp=MAZZO[i];
	MAZZO[i]=MAZZO[j];
	MAZZO[j]=temp;
	i++;
  }
}

void distribuzione (CARTA *MAZZO){
	int i=0;
	while(i<DIM){
		printf("%6s di %-8s%c", MAZZO[i].valore, MAZZO[i].seme, (i+1) % 2 ? '\t':'\n');
		i=i+1;
	}

}
int main(){

	CARTA MAZZO [DIM];

	char *valore[]= {"asso", "due", "tre","quattro", "cinque","sei","sette","otto","nove","dieci","jack","queen","king"};
    char *seme[]={"fiori", "cuori", "quadri", "picche"};

    srand(time(NULL));

    crea_mazzo(MAZZO, valore, seme);
	mescola_mazzo(MAZZO);
	distribuzione(MAZZO);





	system("pause");
	return 0;
}
