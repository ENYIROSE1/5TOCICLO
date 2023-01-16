#include <iostream>

using namespace std;

int cont=0;

int FiboPDTDR(int n, int *tabla){
	cont++;
	if(tabla[n] != -1){
		
		return tabla[n];
		
	}else if(n==0){
		
		tabla[n]=0;
		
		return tabla[n];
		
	}else if(n==1){
		
		tabla[n]=1;
		
		return tabla[n];
		
	}else{
		
		tabla[n]=FiboPDTDR(n-1, tabla)+FiboPDTDR(n-2,tabla);
		
		return tabla[n];
		
	}
	
}
	
	int main(int argc, char *argv[]) {
		
		int n;
		
		cout<<"Ingrese un numero: ";cin>>n;
		
		int *tabla = new int[n+1];
		
		for(int i=0;i<=n;i++){
			
			tabla[i] = -1;
			
		}
		
		//for(int i=0;i<n;i++){
			
			cout<<FiboPDTDR(n,tabla);
			
		//}
		
		cout<<"\nCantidad de operaciones: "<<cont;
		
		return 0;
		
	}
