/*
Time : Wed Aug 16 2017 23:38:40 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/valid-sudoku/
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board 
could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding 
to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", 
"7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells 
need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::isValidSudoku(const vector<string> &A) {
    vector< vector<int> > sud(9);
    // Build matrix sudoku from strings replacing dots by zeroes.
    for(int i=0;i<9;i++){
        vector<int> row(9);
        for(int j=0;j<9;j++){
            if(A[i][j]=='.')
                row[j] = 0;
            else
                row[j] = (int)A[i][j] - 48;
        }
        sud[i] = row;
    }
    bool ans = true;
    int bitvec = 0;
    // Check if any element repeated row wise.
    for(int i=0;i<9;i++){
        bitvec = 0;
        for(int j=0;j<9;j++){
            if(sud[i][j]!=0){
                int mask=  pow(2,sud[i][j]);
                if(bitvec & mask){
                return false;}
                bitvec |= mask;
            }
        }
    }
    // Check if any element repeated column wise.
    for(int i=0;i<9;i++){
        bitvec = 0;
        for(int j=0;j<9;j++){
            if(sud[j][i]!=0){
                int mask = pow(2,sud[j][i]);
                if(bitvec & mask){
                return false;}
                bitvec |= mask;
            }
        }
    }
    // Check each 3x3 square if any element repeated.
    for(int i=0;i<=6;i+=3){
        for(int j=0;j<=6;j+=3){
            bitvec = 0;
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    if(sud[k][l]!=0){
                        int mask = pow(2,sud[k][l]);
                        if(bitvec & mask){
                        return false;}
                        bitvec |= mask;
                    }
                }
            }
        }
    }
    return true;
}

int main(){

	return 0;
}
