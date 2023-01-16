#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

bool vocal(char v)
{
	v = toupper(v);
	return (v=='A' || v=='E' || v=='I' );
}

int contador(string c, int x)
{
	//caso base
	if (x == 1)
		return vocal(c[x-1]);
	
	return contador(c, x-1) + vocal(c[x-1]);
}
int main()
{	
	string cadena;
	cout << "Ingrese cadena: ";
	getline(cin,cadena);
	
	
	cout << contador(cadena, cadena.length()) << endl;
	return 0;
}

