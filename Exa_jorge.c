#include"libreria.h"
//****************************************************************************
void menu();
Talum lee_datos();
void desplegar(Talum[],int);
void salida_archivo(Talum[],int);
void metodo_burbuja(Talum[],int);
void busqueda_bin(Talum[],int);
//****************************************************************************
int main (void)
{
   srand (time(NULL));
   menu();
   return 0;
}
//****************************************************************************
//***************** FUNCION MENU DESDE DONDE SE MANDA LLAMAR FUNCIONES *******
void menu(void)
{
	int op,tam=0;
    Talum Lista[500];
    fflush(stdin);
   
    do{
       system ("cls");
       printf("\n M  E   N   U");
	   printf("\n1.- Agragar");
	   printf("\n2.- Desplegar");
	   printf("\n3.- Salida a archivo de texto");
	   printf("\n4.- Ordenar");
	   printf("\n5.- Buscar");
	   printf("\n6.- salir");
	   printf("\nESCOGE UNA OPCION.");
       scanf ("%d",&op);
	   switch(op)
	    {
		  case 1: Lista[tam]= lee_datos();
		  		  tam++; break;
		  case 2: desplegar(Lista,tam); break;
		  case 3: salida_archivo(Lista,tam); break;
		  case 4: metodo_burbuja(Lista,tam); break;
		  case 5: busqueda_bin(Lista,tam); break;
		}
	
    }while(op != 6);
}
//***********************************************************************************
Talum lee_datos()
{
	Talum reg;
	fflush(stdin);
	reg.matr=validanum(0,5000,"Dame la matricula del alumno","Error");
    strcpy(reg.nombre,crear_cadena(30,"\nNombre del alumno\n",TRUE,FALSE));
    reg.edad = validanum(0,200,"Edad, del alumno","Error, poner numeros validos");
    reg.sexo = validanum(1,2,"Sexo \n1.-Masculino \n2.-Femenino","Error, poner numeros validos");
   		
   return reg;
}
//***************************************************************************************
void desplegar(Talum reg[],int tama)
{
	int i;
	char genero[10];
	system("cls");
	printf("\n  #  Matricula Nombre\t\t\t\t\t Edad   Sexo\n");
	for(i=0;i<tama;i++)
	{
		if (reg[i].sexo==1)
     		{
     		  strcpy(genero,"M");
     		}
     	  else
       		{
       	  		strcpy(genero,"F");
       		}
       	printf("%3d %5d %-39s %10d    %-15s \n",i+1,reg[i].matr,reg[i].nombre,reg[i].edad,genero);	
      	
	}
getch();
}
//***********************************************************************
void salida_archivo(Talum reg[],int tama)
{
	int i;
	char genero[10],nombre[30];
	FILE *text;
	strcpy(nombre,crear_cadena(30,"\nNombre del archivo, no es necesario agregar la extension.",TRUE,FALSE));
	strcat(nombre,".txt");
	text = fopen(nombre,"w");
 	if(tama==0) printf("No hay registros");
 	else
    {
    
		for(i=0;i<tama;i++)
		{
			if (reg[i].sexo==1)
     		{
     		  strcpy(genero,"M");
     		}
     	  else
       		{
       	  		strcpy(genero,"F");
       		}
			fprintf(text,"%3d %5d %39s %10d %10s\n",i+1,reg[i].matr,reg[i].nombre,reg[i].edad,genero);
		}
    		
		
 	
		printf("\nSe ha imprimido correctamente");	
    }
	fclose(text);
			
	getch();	


}
//***************************************************************************
//FUNCION DE BURBUJA
void metodo_burbuja( Talum arreglo[],int tama)
{	
	system ("cls");
	printf("\nMETODO DE ORDENACION POR BURBUJA\n");
	
    mtdo_burbuja(arreglo,tama);
    desplegar(arreglo,tama);
    getch();
   	
}
//FUNCION DE BUSQUEDA BINARIA
void busqueda_bin(Talum arreglo[],int tama)
{
	int num,matri;
	system("cls");
	num=validanum(1,1000,"\nSelecciona la matricula que deseas encontrar\n","\nESE NUMERO NO APLICA\n");
	matri=busqueda_binaria(arreglo,tama,num);
	if (matri==-1)
	{
		printf("\nLa matricula no existe\n");
	}
	else
	{
		printf("\nLA matricula es:\n");
		printf("%3d %5d %39s %10d\n",matri+1,arreglo[matri].matr,arreglo[matri].nombre,arreglo[matri].edad);
		
	}
  
 getch();

}
