#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#define FILAS 100
#define COLUMNAS 100

using namespace std;

int recursivoCuadro(int cuadro[FILAS][COLUMNAS], int fil, int colum, int &cuadrado){
	int desplazoIzq,esquinaIzq,desplazoArriba;
	
	if (fil== 0 || colum == 0){
		cuadrado = max(cuadrado, cuadro[fil][colum]);
		return cuadro[fil][colum];
	}
	
	desplazoIzq = recursivoCuadro(cuadro, fil, colum - 1, cuadrado);
	desplazoArriba = recursivoCuadro(cuadro, fil - 1, colum, cuadrado);
	esquinaIzq = recursivoCuadro(cuadro, fil - 1, colum - 1, cuadrado);
	
	int numero = 0;
	if (cuadro[fil][colum] != 0) {
		numero = 1 + min (min(desplazoArriba, desplazoIzq), esquinaIzq);
	}
	
	cuadrado = max(cuadrado, numero);
	return numero;
}
	
	
	int dinamicoCuadro(int cuadro[FILAS][COLUMNAS], int fil, int colum)
	{
		int maximo = 0;
		int cuadroauxiliar[FILAS][COLUMNAS];
		
		for (int x = 0; x <fil; x++)
		{
			for (int j = 0; j <colum; j++)
			{
				
				cuadroauxiliar[x][j] = cuadro[x][j];
				
				
				if (x && j && cuadro[x][j]){
					
					cuadroauxiliar[x][j] = min (min (cuadroauxiliar[x][j - 1], cuadroauxiliar[x - 1][j]),
												cuadroauxiliar[x - 1][j - 1]) + 1;
				}	
				if (maximo < cuadroauxiliar[x][j]){
					maximo = cuadroauxiliar[x][j];
				}
			}
		}
		
		return maximo;
	}
	
	
	int main(int argc, char *argv[]) {
		
		char rsp='S';
		while(toupper(rsp)=='S'){
			
			int cuadro[FILAS][COLUMNAS], fil,columna;
			
			cout<<"\n\t***MATRIZ M x N***"<<endl;
			cout<<"\n INGRESE CANTIDAD N: ";cin>>fil;
			cout<<"\n INGRESE CANTIDAD M: ";cin>>columna;
			cout<<"\n----------------------------------------------"<<endl;
			
			int cuadrado = 0;
			srand(time(NULL));
			
			cout<<endl;
			
			for(int x=0;x<fil;x++){
				for(int y=0;y<columna;y++){
					cuadro[x][y]=rand()%(1-0+1)+0;
				}
			}
			
			for(int x=0;x<fil;x++){
				for(int y=0;y<columna;y++){
					cout<<cuadro[x][y]<<" ";
				}
				cout<<endl;
			}
			
			recursivoCuadro(cuadro, fil-1, columna-1,cuadrado);
			
			cout<<"\n----------------------------------------------"<<endl;
			cout <<"\n\t\nCuadrados máximo con RECURSIVIDAD:  "<<cuadrado-1;
			cout <<"\n\t\nCuadrados máximo con DINAMICO:  "<<dinamicoCuadro(cuadro, fil, columna)-1;
			cout<<"\n\n";
			cout<<"\n----------------Desea continuar-----(s/n)----------    "<<endl; cin>>rsp;
			system("cls");
			cout<<"\n"; 
			system("pause");
		}
		return 0;
	}
	
