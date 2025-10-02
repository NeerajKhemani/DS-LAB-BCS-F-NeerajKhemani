#include <iostream>
using namespace std;

int N;
int board[20][20];

bool safe(int r,int c){
    for(int i=0;i<r;i++){
        if(board[i][c]==1){
            return false;
        }
    }
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=r-1,j=c+1;i>=0 && j<N;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

void printB(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==1){
                cout<<"Q ";
            } else {
                cout<<". ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(int r){
    if(r==N){
        printB();
        return;
    }
    for(int c=0;c<N;c++){
        if(safe(r,c)){
            board[r][c]=1;
            solve(r+1);
            board[r][c]=0;
        }
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=0;
        }
    }
    solve(0);
}
