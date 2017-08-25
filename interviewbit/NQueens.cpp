/*
Time : Thu Aug 24 2017 19:48:18 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/nqueens/
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens 
attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each 
solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both 
indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions 
to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 
Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

#include <bits/stdc++.h>

using namespace std;

bool canplace(vector<string> curr,int row,int col,int n){
	for(int i=0;i<n;i++) if(curr[row][i]=='Q' || curr[i][col]=='Q') return false;
	int i=row,j=col;
	while(i<n && j<n){ if(curr[i][j]=='Q') return false; i++;j++; }
	i=row,j=col; while(i>=0 && j>=0) { if(curr[i][j]=='Q') return false; i--;j--;}
	i=row,j=col; while(i>=0 && j<n) { if(curr[i][j]=='Q') return false; i--;j++;}
	i=row,j=col; while(i<n && j>=0) { if(curr[i][j]=='Q') return false; i++;j--;}
	return true;
}

void solve(vector<string> curr, int starti,int startj, int n, vector<vector<string> >& ans,int queencount){
	if(queencount==n) ans.push_back(curr);
	if(starti>n || startj>n) return;
	for(int i=starti;i<n;i++){
		for(int j=startj;j<n;j++){
			if(canplace(curr,i,j,n)){
				curr[i][j] = 'Q';
				solve(curr,i+1,0,n,ans,queencount+1);
				curr[i][j] = '.';
			}
		}
		bool noneq = true;
		for(int j=0;j<n;j++){ if(curr[i][j]=='Q') noneq = false;}
		if(noneq) return;
	}
}

vector<vector<string> > Solution::solveNQueens(int A) {
    int n = A;
	string b = "";
	for(int i=0;i<n;i++) b += ".";
	vector<string> init(n); for(int i=0;i<n;i++) init[i] = b;
	vector<vector<string> > a; vector<vector<string> >& ans = a;
	solve(init,0,0,n,ans,0);
	return ans;
}

int main(){

	return 0;
}
