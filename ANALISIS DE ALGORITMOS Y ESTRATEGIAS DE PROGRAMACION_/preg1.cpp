#include<iostream>
#include<ctime>
#include<math.h>
#include<cstdlib>
using namespace std;

double pointsaleatorios(int n, int rd){
	float ptp = 0;
	float ptc = 0;
	
	for(int i=0; i< n ; i++){
		double cx = -rd + (rd/2 - -rd/2)*((double)rand()/RAND_MAX);
		double cy = -rd + (rd/2 - -rd/2)*((double)rand()/RAND_MAX);
		
		if(cy*cy - 4*cx <=0){
			ptp++;
		}
		ptc++;
	}
	cout<<endl << "Número de puntos en el circulo: "<<ptc<<endl;
	
	cout<<"Número de puntos en la curva: "<<ptp<<endl;   
	
	return ptp/ptc;
}

int main(){
	srand(time(0));
	int n,rd;
	
	system("pause");
	cout << "\nDigite la cantidad de puntos: "; cin >> n;
	cout << "\nDigite el radio del circulo: "; cin >> n;
	
	double acirc = 3.1416*(rd*rd);
	double proportion = pointsaleatorios(n,rd);
	
	double parab = acirc * proportion;
	double aprox = acirc - parab;
	
	cout << "\nArea del circulo: "<<acirc;
	cout << "\nArea de la parabola: "<< parab;
	
	cout << "\nArea del círculo que no se intersecta con una parábola usando numeros decimales aleatorios: "<<aprox;
	return 0;
}
