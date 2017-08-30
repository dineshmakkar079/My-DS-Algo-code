/*
Time : Tue Aug 29 2017 12:05:15 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/ncr/0
Find nCr for given n and r.

Input:
First line contains no of test cases T, for every test case 
2 integers as inputs (n,r).


Output:
Compute and print the value in seperate line. Modulus your 
output to 109 7. If n


Constraints:
1<=T<=50
1<=n<=1000
1<=r<=800


Example:
Input:
1
3 2

Output:
3

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main() {
    // Preprocessing
    int n1 = 1000, r1 = 800;
    vector<vector<int> > m(n1+1);
    vector<vector<int> >& mem = m;
    for(int i=0;i<n1+1;i++){
        vector<int> v(r1+1);
        for(int j=0;j<r1+1;j++)
            v[j] = 0;
        mem[i] = v;
    }
    mem[0][0] = 1;
    for(int i=1;i<r1+1;i++) mem[0][i] = 0;
    for(int i=1;i<n1+1;i++) mem[i][0] = 1;
    for(int i=1;i<n1+1;i++){
        for(int j=1;j<=i&&j<r1+1;j++){
            mem[i][j] = (mem[i-1][j] + mem[i-1][j-1])%mod;
        }
    }
    
	int t;
	cin >> t;
	while(t--){
	    int n , r;
	    cin >> n >> r;
	    if(n-r < r) r = n-r;
	    if(n<r){ cout << "0\n"; continue; }
	    if(r==0) { cout << "1\n"; continue; }
	    if(r==1) { cout << n << endl ; continue; }
	    cout << mem[n][r] << endl;
	}
	return 0;
}