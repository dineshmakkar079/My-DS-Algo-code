/*
Time : Fri Aug 25 2017 20:35:33 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/sudoku/
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by 
the character '.' 
You may assume that there will be only one unique solution.



A sudoku puzzle,



and 
its solution numbers marked in red.

Example :

For the above given diagrams, the corresponding 
input to your program will be

[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], 
[7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the 
above array of array of characters to

[[534678912], [672195348], [198342567], [859761423], [426853791], 
[713924856], [961537284], [287419635], [345286179]]

*/

#include <bits/stdc++.h>

using namespace std;

bool canplace(std::vector<string>& curr,int row,int col,char c){
    for (int i = 0; i < 9; ++i){
        bool one = (c==curr[i][col]) ;
        bool two = (c==curr[row][i]) ;
        bool three = (c==curr[(row/3)*3 + i/3][(col/3)*3 + i%3]);
        if(one || two || three)
            return false;
    }return true;
}

void solve(vector<string>& curr,int starti,int startj,vector<string>& ans,int count){
    if(count == 81){
        ans = curr;
        return;
    }
    for(int i=0;i<starti&&i<9;i++){
        for(int j=0;j<9;j++){
            if(curr[i][j]=='.')
                return;
        }
    }
    for(int j=0;j<startj&&j<9;j++){
        if(curr[starti][j]=='.') return;
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(curr[i][j]=='.'){
                bool placeone = false;
                for(char c='1';c<='9';c++){
                    if(canplace(curr,i,j,c)){
                        placeone = true;
                        curr[i][j] = c;
                        solve(curr,i,j,ans,count+1);
                        curr[i][j] = '.';
                    }
                }
                if(!placeone) return;
            }
        }
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    std::vector<string> in(9);
    std::vector<string> two(9);
    std::vector<string>& vs = in;
    int f = 0; int& fixed = f;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j]!='.')
                fixed++;
            vs[i] += A[i][j];
        }
    }
    vector<string>& ans = two;
    solve(vs,0,0,ans,fixed);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            A[i][j] = ans[i][j];
        }
    }
}

int main(){

	return 0;
}
