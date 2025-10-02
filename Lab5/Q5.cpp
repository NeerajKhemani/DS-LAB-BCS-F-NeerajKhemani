#include <iostream>
using namespace std;

int N=9;

bool canPlace(int b[9][9],int r,int c,int n){
    for(int i=0;i<N;i++){
        if(b[r][i]==n){
            return false;
        }
        if(b[i][c]==n){
            return false;
        }
    }
    int sr=(r/3)*3, sc=(c/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b[sr+i][sc+j]==n){
                return false;
            }
        }
    }
    return true;
}

bool findEmpty(int b[9][9],int &r,int &c){
    for(r=0;r<N;r++){
        for(c=0;c<N;c++){
            if(b[r][c]==0){
                return true;
            }
        }
    }
    return false;
}

bool solve(int b[9][9]){
    int r,c;
    if(!findEmpty(b,r,c)){
        return true;
    }
    for(int n=1;n<=9;n++){
        if(canPlace(b,r,c,n)){
            b[r][c]=n;
            if(solve(b)){
                return true;
            }
            b[r][c]=0;
        }
    }
    return false;
}

void printB(int b[9][9]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int g[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    if(solve(g)){
        printB(g);
    } else {
        cout<<"no sol\n";
    }
}
