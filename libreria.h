#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct _Tdato
  {
  	int matr;
  	char nombre[60];
  	int sexo;
  	int edad;
  }Talum;
//***********************************************************
char* crear_cadena(int tama,char* msj,int permitirEspacio,int solo_numeros);
int validanum(int ri,int rf, char *msge,char *error);
void mtdo_burbuja( Talum[],int);
int busqueda_binaria(Talum[], int, int);
//***********************************************************************************  
//FUNCION QUE CREA UNA CADENA Y REGRASA EL VALOR, VALIDADO CON SOLO UN ESPACIO Y SIN NUMEROS.
//***********************************************************************************
char* crear_cadena(int tama,char* msj,int permitirEspacio,int solo_numeros)
{
  char cadena[30];
  int i=0,tecla,band=FALSE;
  do{  
  	  
       if(i==0)
	   {
			system ("cls");
			puts(msj);
	   } 
       tecla=getch();
       if(solo_numeros==TRUE)
       {
       		//Solo numeros permitidos
       	    //*********************************
       		if ((tecla>=48&&tecla<=57)||(tecla==32&&band==TRUE))
       		{	
        		printf("%c",tecla);
        		cadena[i]=tecla;  
        		if (tecla==32)  band=FALSE;
            	else band=permitirEspacio;
				i++;                                                          
        	}

       }
       else
       {
       		//Solo letras, permitidas
  	  		 //************************
       		if ((tecla>=65&&tecla<=90)||(tecla>=97&&tecla<=122)||(tecla==164)||(tecla==165)||(tecla==32&&band==TRUE))
       		{
        		printf("%c",tecla);
        		cadena[i]=tecla;  
        		if (tecla==32) band=FALSE;
            	else band=permitirEspacio;
        		i++;                                                          
        	}
       }
  	  
        if(i>tama)
        {
        	system ("cls");
        	printf("\n\nSolo puedes meter: %d caracteres, Por favor intenta de nuevo\n\n",tama);
            system ("pause");
            printf("\n\n");
        	i=0;
        }
     }while(tecla!=13);
     cadena[i]='\0';
     return cadena;
}
//***********************************************************
//FUNCION QUE VALIDA UN NUMERO DENTRO DE UN RANGO.
//**************************************************************
int validanum(int ri,int rf, char *msge,char *error)
{
  char xnum[30];
  int num;
  system("cls");
  do{
     strcpy(xnum,crear_cadena(30,msge,TRUE,TRUE));
	 num=atoi(xnum);
	 if(num < ri || num > rf)
	 {
	  	system("cls");	
	  	printf("%s",error);
		getch();
	 }
  }while(num < ri || num > rf);

return num;
}
//***************************************************************************
//FUNCION DE BURBUJA
void mtdo_burbuja( Talum arreglo[],int tam)
{
	int i,j;
 	Talum temp;
 	for (i=0;i<tam+1;i++)
 	{ 
   		for (j=0;j<tam-1;j++)
   		{
  			if (arreglo[j+1].matr<arreglo[j].matr)
  			{
   				temp=arreglo[j];
   				arreglo[j]=arreglo[j+1];
   				arreglo[j+1]=temp;
   
  			}
   		}
	}
   
   	
}
//FUNCION DE BUSQUEDA BINARIA
int busqueda_binaria(Talum arreglo[], int tam, int num)
{

  int Ls = tam-1,Li = 0,centro;
 
  while (Li<=Ls)
    {
      	centro = (Ls + Li)/2;
      	if (arreglo[centro].matr == num)
 		return centro;
      	else
      	{
		  	if (num < arreglo[centro].matr)
   			Ls=centro-1;
		 	else
  			Li=centro+1;
      	}
 		
    }
  return -1;

}
