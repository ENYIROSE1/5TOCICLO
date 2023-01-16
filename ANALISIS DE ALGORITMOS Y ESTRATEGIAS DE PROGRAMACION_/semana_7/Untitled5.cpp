#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
 

bool vocal(char ch)
{
    ch = toupper(ch);
    return (ch=='A' || ch=='E' || ch=='I' );
}
 
// to count total number of vowel from 0 to n
int contador(string c, int x)
{
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
