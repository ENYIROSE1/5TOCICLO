#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdlib>
using namespace std;

double pointsaleatorios(int n, int rd){
	
	float ptp = 0;
	float ptc = 0;
	
	for(int i=0;i<n;i++){
		double cx=-rd/2+(rd/2 - -rd/2)*((double)rand()/RAND_MAX);
		double cy=-rd/2+(rd/2 - -rd/2)*((double)rand()/RAND_MAX);
		
		if(cy*cy-4*cx <= 0){
			ptp++; 
		}
		ptc++;
		
	}
	
	cout<<"\nNumero de puntos aleatorios que cayeron en el circulo: "<<ptc<<endl;
	cout<<"\nNumero de puntos aleatorios que cayeron en la curva:   "<<ptp<<endl;   
	
	return ptp/ptc;
}

int main(){
	srand(time(0));
	int n; 
	int rd;
	
	system("pause");
	
	cout<<"\nDigite el radio del circulo: ";
	cin>>rd;
	cout<<"\nDigite la cantidad de numeros aleatorios: ";
	cin>>n;
	
	double acirculo = 3.1416*(rd*rd);
	double proportion = pointsaleatorios(n,rd);
	
	double parabola = acirculo * proportion;
	double aprox = acirculo - parabola;
	
	cout<<"\nArea del circulo : "<<acirculo;
	
	cout<<"\nArea de la parabola: "<<parabola;
	
	cout<<"\nArea del circulo que no se intersecta con una parabola usando numeros decimales aleatorios: "<<aprox;
	
	return 0;
}
	
