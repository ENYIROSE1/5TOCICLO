#include <iostream>
using namespace std;

int minCaminoR(int M[3][3], int , int );
int minCaminoDinam(int M[3][3],int sol[4][4], int , int );

int cont=0;
int cont1=0;

int main(){
    int caminos[3][3]={
        {9,6,4},
        {8,3,5},
        {2,1,7}
    };
    cout << "\n";
    for (int i = 0; i<3; i++){
        for(int j =0; j<3;j++){
            cout<< "\t"<< caminos[i][j]<<"\t";
        }
        cout<<"\n";    
    }
    cout << "\n";
    int sol[4][4];
    for (int i = 0;i <= 3; i++){
        for (int j =0; j<=3;j++){
            sol[i][j]= -1;
        }
    }
    cout<<" El valor del camino mas corto es con Recursion es: "<<minCaminoR(caminos,2,2);
    cout<<"\n El numero de operaciones es: "<<cont;
    cout<<"\n El valor del camino mas corto con Programacion Dinamica es: "<<minCaminoDinam(caminos,sol,2,2);
    cout<<"\n El numero de operaciones es: "<<cont1;
    return 0;
}

int minCaminoR(int M[3][3], int x , int y){
    cont++;
    if(x==0 && y==0){
        return M[0][0];
    }
    else{
        int costo=M[x][y];
        if(x==0){
            return costo+minCaminoR(M,x,y-1);
        }
        else if(y==0){
            return costo+minCaminoR(M,x-1,y);
        }
        else{
            return costo+min(minCaminoR(M,x-1,y),minCaminoR(M,x,y-1));
        }
    }
}
int minCaminoDinam(int M[3][3],int sol[4][4], int x, int y){
    cont1++;
    if(sol[x][y]!=-1){
        return sol[x][y];
    }
    if(x== 0 && y == 0){
        return M[0][0];
    }
    else{
        sol[x][y] = M[x][y];
        if(x==0){
            sol[x][y] +=minCaminoDinam(M,sol,x,y-1);
            return sol[x][y];
        }
        else if(y==0){
            sol[x][y] += minCaminoDinam(M,sol,x-1,y);
            return sol[x][y];
        }
        else{
            sol[x][y] += min(minCaminoDinam(M,sol,x-1,y),minCaminoDinam(M,sol,x,y-1));
            return sol[x][y];
        }
    }
}


