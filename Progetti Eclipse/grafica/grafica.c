/*
 * grafica.c
 *
 *  Created on: 21 dic 2016
 *      Author: GianFederico
 */
#include <stdio.h>
#include <stdlib.h>
//dichiarazioni iniziali delle funzioni
void cerchio();
void intersezione();
void base();

int main(){
//dichiarazioni nel main delle funzioni
	cerchio();
	intersezione();
    base();

    system("pause \n");

    printf("     *** Merry Christmas!!! ***\n\n");
    printf("     *** And happy new year ***\n\n");
	system ("pause");
	     return (0);
}
//esplicitazione delle varie funzioni
void cerchio(){
	printf("                 *     \n");
	printf("              *     *  \n");
	printf("                * *    \n");
}
void intersezione(){
	printf("                /\\      \n");
	printf("               /  \\     \n");
	printf("              /    \\    \n");
}
void base(){
	printf("             /______\\ \n");
	printf("                ||\n\n");

}
