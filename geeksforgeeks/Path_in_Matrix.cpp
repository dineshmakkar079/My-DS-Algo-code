/*
Time : Mon Aug 28 2017 10:51:38 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/path-in-matrix/0
Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from 
a cell Matrix[r][c].

1. Matrix[r 1][c]

2. Matrix[r 1][c-1]

3. Matrix[r 1][c 1]

Starting from 
any column in row 0, return the largest sum of any of the paths up to row N-1.

Input:
The first 
line of the input contains an integer T denoting the number of test cases. The description of T 
test cases follows.
The first line of each test case contains a single integer N denoting the order 
of matrix. Next line contains N*N integers denoting the elements of the matrix in row-major form.

Output:
Output 
the largest sum of any of the paths starting from any cell of row 0 to any cell of row N-1. Print 
the output of each test case in a new line.

Constraints:
1<=T<=20
2<=N<=20
1<=Matrix[i][j]<=1000 
(for all 1<=i<=N

*/

#include <bits/stdc++.h>

using namespace std;

int maxpath(vector<vector<int> >& m){
    int n = m.size();
    vector<vector<int> > mem(n);
    for(int i=0;i<n;i++){
        vector<int> v(n);
        for(int j=0;j<n;j++){
            v[j] = -1;
        }
        mem[i] = v;
    }
    for(int i=0;i<n;i++){ mem[0][i] = m[0][i]; }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int one = (j-1)>=0 ? mem[i-1][j-1] : INT_MIN;
            int two = (j+1)<n ? mem[i-1][j+1] : INT_MIN;
            int thr = mem[i-1][j];
            mem[i][j] = m[i][j] + max(one, max(two, thr));
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){ ans = max(ans, mem[n-1][i]); }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<vector<int> > m(n);
	    vector<vector<int> >& mat = m;
	    for(int i=0;i<n;i++){
            vector<int> v(n);
            for(int j=0;j<n;j++){
                cin >> v[j];
            }
            mat[i] = v;
        }
        cout << maxpath(mat) << endl;
	}
	return 0;
}