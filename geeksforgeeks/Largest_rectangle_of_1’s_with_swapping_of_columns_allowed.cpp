/*
Time : Thu Oct 19 2017 11:14:24 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/find-the-largest-rectangle-of-1s-with-swapping-of-columns-allowed/0
Given a matrix with 0 and 1’s, find the largest rectangle of all 1’s in the matrix. The rectangle 
can be formed by swapping any pair of columns of given matrix.

Input:

The first line of input 
contains an integer T denoting the number of test cases. 

First line of each test case contains 
two elements R and C.The following line contains R*C numbers each (representing the matrix).
Output:

print 
the max area in a new line for each test case.
Constraints:

1<=T<=100

1<=R,C<=15
Example:

Input:

2

2 
3

1 1 1 0 1 1

2 2

1 0 1 1

Output:

4

2

** For More Input/Output Examples Use 'Expected Output' 
option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
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
#define pb push_back;
#define sz(a) (a).size()

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    vvi v(n, vi(m));
	    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin >> v[i][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                v[i][j] = v[i][j]?1+v[i+1][j]:0;
            }
        }
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<m;j++){
                maxi = max(maxi, v[i][j]*(m-j));
            }
        }
        cout << maxi << endl;
	}
	return 0;
}