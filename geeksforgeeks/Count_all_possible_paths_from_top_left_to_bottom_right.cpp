/*
Time : Mon Aug 28 2017 14:46:36 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right/0
The task is to count all the possible paths from top left to bottom right of a mXn matrix with the 
constraints that from each cell you can either move only to right or down.

Input: 
First line consists 
of T test cases. First line of every test case consists of N and M, denoting the number of rows 
and number of column respectively.

Output: 
Single line output i.e count of all the possible paths 
from top left to bottom right of a mXn matrix. Since output can be very large number use ^9 7.

Constraints:
1<=T<=100
1<=N<=100
1<=M<=100

Example:
Input:
1
3 
3
Output:
6

**For More Examples Use Expected Output**

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
#define mod 1000000007
#define ull unsigned long long

using namespace std;

int ways(int m,int n){
    vector<vector<ull> > mem(m);
    for(int i=0;i<m;i++){
        vector<ull> v(n);
        for(int j=0;j<n;j++) v[j] = 0;
        mem[i] = v;
    }
    for(int i=0;i<m;i++) mem[i][0] = 1;
    for(int j=0;j<n;j++) mem[0][j] = 1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            mem[i][j] = (mem[i-1][j] + mem[i][j-1])%mod;
        }
    }
    return mem[m-1][n-1];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int m,n;
	    cin >> m >> n;
	    cout << ways(m,n) << endl;
	}
	return 0;
}