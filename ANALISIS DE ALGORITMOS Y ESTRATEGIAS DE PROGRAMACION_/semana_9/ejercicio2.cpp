#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
using namespace std;
//int contadorcincos(){
	//caso base
	//caso repetitivo
	
	//divide y venceras
//}
int main(){
	int arr[100][100],tam,x;
	cout << "Ingrese tamaño de la matriz: ";
	cin >> tam;
	srand(time(NULL));
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
		arr[i][j] = rand()%(9);
		cout << arr[i][j] << " ";
	}
		cout << "\n";
	}
	//int n = sizeof(tam)/sizeof(int);
	//int x = 5;
    //cout << contadorcincos(arr,0,n-1,x);
	return 0;
}
