#include<bits/stdc++.h>
#define MAX 105
using namespace std;
char mat[MAX][MAX];
void mutateCell(int i, int j, int n, int m, char ch){
    char newCh;
    if(i>=0 && i<n && j>=0 && j<m && mat[i][j] == '.'){
        mat[i][j] = ch;
        if(ch == 'W'){
            newCh = 'B';
        }
        else{
            newCh = 'W';
        }
        mutateCell(i+1, j, n, m, newCh);
        mutateCell(i, j+1, n, m, newCh);
        mutateCell(i-1, j, n, m, newCh);
        mutateCell(i, j-1, n, m, newCh);
    }
}

void mutate(int n, int m){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(mat[i][j] == '.'){
                mutateCell(i+1, j, n, m, 'W');
                mutateCell(i, j+1, n, m, 'W');
                mutateCell(i-1, j, n, m, 'W');
                mutateCell(i, j-1, n, m, 'W');
                mat[i][j] = 'B';
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            cin>>mat[i][j];
    }
    mutate(n, m);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(mat[i][j] == '.'){
                cout<<'W';
            }
            else{
                cout<<mat[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}