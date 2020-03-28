#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef union {
		int numero;
		struct{
		unsigned char bit:1;
		unsigned char bit1:1;
		unsigned char bit2:1;
		unsigned char bit3:1;
		} mapa;		
	}campo;


void anillo(){
campo uno;
int salir=0;
uno.numero=0;
int contador =1;
printf("\n.:Contador anillo:.\n");
while(salir!=72 && salir!=104)
{	
	printf("\nESTADO %d \n",contador);
	printf("Campo de bits:%d",uno.mapa.bit);
    printf("%d",uno.mapa.bit1);
    printf("%d",uno.mapa.bit2);
    printf("%d",uno.mapa.bit3);
    if(kbhit())salir=getch();
	if(uno.numero<=0){
	uno.numero=8;
	contador=1;
	}
	else
	{
		uno.numero=	uno.numero/2;
		contador++;
	}
	Sleep(1000);	  	
}
return;
}

void johnson(){
campo uno;
int salir=0;
uno.numero=0;
int contador =1;
int calculo=16;
printf("\n.:Contador johnson:.\n");
while(salir!=72 && salir!=104)
{	
	if(uno.numero>15){
	uno.numero=0;
	calculo=16;
	contador=1;
	}
	printf("\nESTADO %d \n",contador);
	printf("Campo de bits:%d",uno.mapa.bit);
    printf("%d",uno.mapa.bit1);
    printf("%d",uno.mapa.bit2);
    printf("%d",uno.mapa.bit3);	
	if(kbhit())salir=getch();
	Sleep(1000);
	if(uno.numero==15)
	{
		uno.numero++;
	}
	else
	{
		calculo=calculo/2;
		uno.numero=uno.numero+calculo;
	}
	contador++;		  	
}
return;
}

void shifter(){
campo uno;
int salir=0;
uno.numero=0;
int contador =1;
int calculo=16;
printf("\n.:Contador shifter:.\n");
while(salir!=72 && salir!=104)
{	
	if(contador==9){
	uno.numero=0;
	calculo=16;
	contador=1;
	}
	if(contador<5)
	{
	printf("\nESTADO %d \n",contador);
	printf("Campo de bits:%d",uno.mapa.bit);
    printf("%d",uno.mapa.bit1);
    printf("%d",uno.mapa.bit2);
    printf("%d",uno.mapa.bit3);	
	Sleep(1000);
		calculo=calculo/2;
		uno.numero=uno.numero+calculo;
	}
	else
	{
	if(contador==6)
	{	calculo=16;
		calculo=calculo/2;
		uno.numero=uno.numero-calculo;}
		
	printf("\nESTADO %d \n",contador);
	printf("Campo de bits:%d",uno.mapa.bit);
    printf("%d",uno.mapa.bit1);
    printf("%d",uno.mapa.bit2);
    printf("%d",uno.mapa.bit3);	
	Sleep(1000);
	calculo=calculo/2;
	uno.numero=uno.numero-calculo;
	}
	if(kbhit())salir=getch();
	contador++;		  	
}	
	return;
}

int main(int argc, char *argv[]) {
int exit=0;
while(exit!=27)
{
	anillo();
	system("cls");
	johnson();
	system("cls");
	shifter();
	system("cls");
	if(kbhit())exit=getch();
}
	return 0;
}
