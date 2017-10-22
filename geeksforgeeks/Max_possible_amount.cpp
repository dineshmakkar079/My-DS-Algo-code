/*
Time : Sat Oct 21 2017 17:35:20 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/max-possible-amount/0
Given a row of n coins of values v1 , v2 ... vn, where n is even. We play a game against an opponent 
by alternating turns. In each turn, a player selects either the first or last coin from the row, 
removes it from the row permanently, and receives the value of the coin. Determine the maximum possible 
amount of money we can definitely win if we move first.

Note : The opponent is as clever as the 
user.

Input:
The first line of input contains an integer T denoting the number of test cases. Then 
T test cases follow. Each test case consists of two lines.
The first line of each test case contains 
an integer N, where N is the number of coins.
The second line of each test case contains N  space 
separated integers denoting input for v[ ].

Output:

Corresponding to each test case, print in 
a new line, the maximum possible amount of money.

Constraints:
1 ≤ T ≤ 100
2 ≤ N ≤ 100
1 ≤ v[i] 
≤ 500

Example:
Input
2
4
5 3 7 10
4
8 15 3 7

Output
15
22

** For More Input/Output Examples Use 
'Expected Output' option **

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

int maxcoin(vector<int> &v) {
    int n = v.size();
    vector<vector<int> > mem(n, vector<int>(n,0));
    for(int gap = 0;gap < n;gap++){
        for(int i=0, j=gap; j<n; ++i, ++j){
            int x = (i+2)<=j ? mem[i+2][j]:0;
            int y = (i+1)<=(j-1)? mem[i+1][j-1]:0;
            int z = i<=(j-2)? mem[i][j-2] : 0;
            mem[i][j]= max(v[i]+ min(x,y), v[j]+min(y,z));
        }
    }
    return mem[0][n-1];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        cout << maxcoin(v) << endl;
	}
	return 0;
}