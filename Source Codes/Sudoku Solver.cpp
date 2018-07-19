#include<bits/stdc++.h>
using namespace std;

int sudoku[9][9];
bool flag= false;


bool blocked(int val, int i, int j){
    int m,n;

    m= i - (i%3);
    n= j - (j%3);

    for(int x=m; x<m+3;x++){
        for(int y=n;y<n+3;y++){
            if(sudoku[x][y]==val)
                return true;
        }
    }

    return false;


}


bool notIllegal(int val, int i, int j){
    for(int m=0;m<9;m++){
        if(sudoku[m][j]==val)
            return false;
    }

    for(int n=0;n<9;n++){
        if(sudoku[i][n]==val)
            return false;
    }

    if(blocked(val,i,j))
        return false;

    return true;


}


void solve(int cell){
    int i,j;

    i=cell/9;
    j=cell%9;

    if(i==9){
        flag=true;
        puts("");
        for(int m=0;m<9;m++){
            for(int n=0;n<9;n++)
                cout<<sudoku[m][n]<<" ";
            puts("");
        }
        return;
    }

    if(sudoku[i][j]!=0){
        solve(cell+1);
        return;
    }

    for(int x=1; x<=9; x++){
        if(notIllegal(x,i,j)){
            sudoku[i][j]=x;
            solve(cell+1);

            if(flag)
                return;

            sudoku[i][j]=0;
        }

    }



}

main(){

    puts("/*Input 0 For Cells That Don't Have Any Entry*/");

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>> sudoku[i][j];

    solve(0);




}
