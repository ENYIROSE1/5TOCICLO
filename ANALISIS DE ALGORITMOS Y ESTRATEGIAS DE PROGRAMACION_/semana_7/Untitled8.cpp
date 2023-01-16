#include<iostream>
using namespace std;

int bottomUp(int p[],int x)
{
	//Declaras el arreglo con las soluciones
	int s[x+1];//Declaras el arreglo con las diferentes soluciones
	//Declara
	int t;//Record revenue
	s[0]=0;
	for(int j=1;j<=x;++j)
	{
		t=-1;//Lo inicializamos en negativo
		for(int i=1;i<=j;i++)
		{
			//
			t=max(t,p[i-1]+s[j-i]);//No longer use recursion//encuentra la maxima posicion//Encuentra el valor maximo del arreglo
			//Cambiando constantemente el valor de q mientras está en el bucle
		}
		s[j]=t;
	}
	return s[x];//Devolver el valor maximo
}

int main()
{
	int arr[11]={1,5,8,9,10,17,17,20,24,50,80};//Declaramos el arreglo
	int b=bottomUp(arr,11);
	cout<<"\n\tEl maximo valor del arreglo es: "<<b;
	
	return 0;
}

