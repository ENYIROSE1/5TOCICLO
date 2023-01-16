#include<iostream>
using namespace std;

float areaTrapecio(float, float, float);

int main(){
	float basem, baseM, h, area;
	cout << "\nHALLAR EL AREA DE UN TRAPECIO: \n\n";
	cout << "Ingrese la base menor: ";
	cin >> basem;
	cout << "Ingrese la base mayor: ";
	cin >> baseM;
	cout << "Ingrese la altura: ";
	cin >> h;
	
	area = areaTrapecio(basem,baseM,h);
	cout << "El area del trapecio es : " << area;
 	return 0;
}

float areaTrapecio(float basem, float baseM, float h){
	float area;
	area = (basem+baseM)/2*h;
	return area;
}
