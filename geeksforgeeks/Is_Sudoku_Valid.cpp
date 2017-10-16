/*
Time : Mon Oct 16 2017 15:54:43 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/is-sudoku-valid/0/?ref=self
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) the task 
to check if the configuration has a solution or not. 

Input:
The first line of input contains an 
integer T denoting the no of test cases. Then T test cases follow. Each test case contains 9*9 space 
separated values of the matrix mat[][] representing an incomplete Sudoku state where a 0 represents 
empty block.

Output:
For each test case in a new line print 1 if the sudoku configuration is valid 
else print 0.

Constraints:
1<=T<=10
0<=mat[]<=9

Example:
Input:
2
3 0 6 5 0 8 4 0 0 5 2 0 0 0 
0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 
0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
3 6 7 5 3 5 6 2 9 1 2 7 0 9 3 6 0 6 2 6 1 8 7 9 2 0 2 3 7 
5 9 2 2 8 9 7 3 6 1 2 9 3 1 9 4 7 8 4 5 0 3 6 1 0 6 3 2 0 6 1 5 5 4 7 6 5 6 9 3 7 4 5 2 5 4 7 4 
4 3 0 7 

Output:
1
0

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

bool canplace(vvi& curr,int row,int col,int c){
    for (int i = 0; i < 9; ++i){
        bool one = (c==curr[i][col]) ;
        bool two = (c==curr[row][i]) ;
        bool three = (c==curr[(row/3)*3 + i/3][(col/3)*3 + i%3]);
        if(one || two || three)
            return false;
    }return true;
}

bool remaining(vvi& sud,int& row,int& col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            if(sud[i][j]==0){
                row = i; col = j;
                return true;
            }
    }
    return false;
}

bool solve(vvi& sud) {
    int row,col;
    if(!remaining(sud,row,col))return true;
    
    for(int n=1;n<=9;n++){
        if(canplace(sud,row,col,n)){
            sud[row][col] = n;
            if(solve(sud))return true;
            sud[row][col] = 0;
        }
    }
    return false;
}


int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    vvi v(9,vi(9,0)); vvi& sud = v;
	    for(int i=0;i<9;i++){
	        for(int j=0;j<9;j++)
	            cin >> v[i][j];
        }
        if(solve(sud)){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
	}
	return 0;
}