/*
Time : Tue Oct 10 2017 12:06:21 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/n-queen-problem/0
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens 
attack each other. Given an integer n, print all distinct solutions to the n-queens puzzle. Each 
solution contains distinct board configurations of the n-queens’ placement, where the solutions 
are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that 
the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard 
[3 1 4 2].



Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Output:
For 
each test case, output your solutions on one line where each solution is enclosed in square brackets 
'[', ']' separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order 
where the number in the ith place denotes the ith-column queen is placed in the row with that number, 
if no solution exists print -1.

Constraints:
1<=T<=10
1<=n<=10

Example:
Input
2
1
4
Output:
[1 
]
[2 4 1 3 ] [3 1 4 2 ]

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
// #define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

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

vector<vector<string> > solveNQueens(int A) {
    int n = A;
	string b = "";
	for(int i=0;i<n;i++) b += ".";
	vector<string> init(n); for(int i=0;i<n;i++) init[i] = b;
	vector<vector<string> > a; vector<vector<string> >& ans = a;
	solve(init,0,0,n,ans,0);
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vr<vr<string> > ans = solveNQueens(n);
	    if(ans.size()==0){
	        cout << "-1\n"; continue;
	    }
	    for(int i=0;i<ans.size();i++){
	        cout << "[";
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++)
    	            if(ans[i][j][k]=='Q')
    	                cout << k+1<< " ";
	        }
	        cout << "] ";
	    }
	    cout << endl;
	}
	return 0;
}