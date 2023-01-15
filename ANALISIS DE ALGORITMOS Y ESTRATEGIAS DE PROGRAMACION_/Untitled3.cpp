#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdlib>
using namespace std;

double puntos(int p, int r){
	
	float pcurva = 0;
	float pcirculo = 0;
	
	for(int i=0;i<p;i++){
		double x=-r/2+(r/2 - -r/2)*((double)rand()/RAND_MAX);
		double y=-r/2+(r/2 - -r/2)*((double)rand()/RAND_MAX);
		
		if(y*y-4*x <= 0){
			pcurva++; 
		}
		pcirculo++;
		
	}
	
	cout<<"\nNúmero de puntos que cayeron en el círculo: "<<pcirculo<<endl;
	cout<<"Número de puntos que cayeron en la curva: "<<pcurva<<endl;   
	
	return pcurva/pcirculo;
}

int main(){
	srand(time(0));
	int p;
	int r;
	
	cout<<"Ingrese el radio del circulo: ";
	cin>>r;
	cout<<"Ingrese cantidad de puntos: ";
	cin>>p;
	
	double area = 3.1416*(r*r);
	double proporcion = puntos(p,r);
	
	double parabolac = area * proporcion;
	double aproximado = area - parabolac;
	
	cout<<"\nEl area del circulo es: "<<area;
	
	cout<<"\nEl area de la parabola es: "<<parabolac;
	
	cout<<"\nArea aproximada que no intersecta con el círculo : "<<aproximado;
	
	return 0;
}
	

