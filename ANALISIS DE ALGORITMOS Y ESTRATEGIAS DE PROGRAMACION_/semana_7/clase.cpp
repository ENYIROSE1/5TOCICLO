//mientras mas largo sea tu codigo 
//mas probabilidades que tengas equivocaciones
//examen, divide y  venceras(podria ser matrices) y recursion
#include<iostream>
#include<math.h>
using namespace std;

int maxTam(long long u,long long v){
	//devolver el maximo de ellos
	int c1 = 0;
	while(u>1){
		u = u/10;
		c1++;
	} 
	int c2 = 0;
	while(v>=1){
		v = v/10;
		c2++;
	}
	//c1 =4, c2 = 4
	if(c1>c2){
		return c1;
	} else {
		return c2;
	}
	
	return (c1>c2?c1:c2);
	//return fmax(c1,c2); 
}

long long multip(long long u, long long v){
	//divide
	int n = maxTam(u,v);
	if(n==1){
	   return u*v;
	} else {
		
	long long w = u/ pow(10,n/2);
	long long x = u - w*pow(10,n/2);
	   
	long long y = v/pow(10,n/2);
	long long z = v - y*pow(10,n/2);
	
	long long wy = multip(x,y); 
	long long wzxy = multip(w,z) + multip(x,y);
	long long xz = multip(x,z); 
	//resuelve
	//resuelve //junta
	int s = n/2;
	return pow(10,2*s)*wy + pos(10,s)*wzxy+xz;
}

int main(int argc, char *argv[]){
	long long n1,n2,n3;
	cout << "Ingrese n1: ";
	cin >> n1;
	cout << "Ingrese n2: ";
	cin >> n2;
	n3 = multip(n1,n2);
	cout << n1 << " * " << n2 << " = "<<n3;
	return 0;
}
