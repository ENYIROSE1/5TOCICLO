#include<iostream>
using namespace std;

int op=0;

int mayorBene(int mapa[4][4], int memo[5][5], int x, int y){
	op++;
	if(memo[x][y]!=-1){
		return memo[x][y];
	}
	if(x==0 && y==0){
		memo[0][0] = mapa[0][0];
		return memo[0][0];
	}
	else {
		memo[x][y] = mapa[x][y];
		if(x==0){
			memo[x][y] += mayorBene(mapa,memo,0,y-1);
			return memo[x][y];
		}
		else if(y==0){
			memo[x][y] += mayorBene(mapa,memo,x-1,y);
			return memo[x][y]; 
		}
		else{
			memo[x][y] += max(mayorBene(mapa,memo,x-1,y),mayorBene(mapa,memo,x,y-1));
			return memo[x][y];
		}
	}
}

int mayorBeneR(int mapa[4][4],int x, int y){
	op++;
	if(x==0 && y==0){
		return mapa[0][0];
	}
	else {
		int bene = mapa[x][y];
		if(x==0){
			return bene + mayorBeneR(mapa,0,y-1);
		}
		else if(y==0){
			return bene + mayorBeneR(mapa,x-1,0);
		}
		else{
			return bene + max(mayorBeneR(mapa,x-1,y),mayorBeneR(mapa,x-1,y));
		}
	}
}

int main(){
	int mapa[4][4] = {
	   {7,5,2,5},
       {6,4,5,3},
       {2,8,7,5},
	   {5,2,9,6},
    };
    int memo[5][5];
    for(int i=0; i<=4 ; i++){
    	for(int j=0; j<=4 ; j++){
    		memo[i][j] = -1;
		}
	}
	cout << "El mayor beneficio(DP) es: "<<mayorBene(mapa,memo,3,3);
	cout << "\noperaciones: "<<op;
	op = 0;
	cout << "\nEl mayor beneficio(R) es: "<<mayorBeneR(mapa,3,3);
	cout << "\nOperaciones: "<<op;
	return 0;
}
