/*
Time : Thu Sep 07 2017 12:41:40 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
The problem is to find shortest distances between every pair of vertices in a given edge weighted 
directed Graph.

Input:
The first line of input contains an integer T denoting the no of test cases 
. Then T test cases follow . The first line of each test case contains an integer V denoting the 
size of the adjacency matrix  and in the next line are V*V space separated values of the matrix 
(graph) .

Output:
For each test case output will be V*V space separated integers where the i-jth 
integer denote the shortest distance of ith vertex from jth vertex.

Constraints:
1<=T<=20 
1<=V<=20
-1000<=graph[][]<=1000

Example:
Input
2
2
0 
25 25 0
3
0 1 43 1 0 6 43 6 0

Output
0 25 25 0 
0 1 7 1 0 6 7 6 0 

**For More Examples Use Expected 
Output**

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int i=0;i<n;i++) a[i]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vvi g(n),ans(n);
	    for(int i=0;i<n;i++){
            vi v(n),a(n);
            for(int j=0;j<n;j++){
                cin >> v[j]; a[j] = v[j];
            }
            ans[i] = a;
            g[i] = v;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++)
                    ans[j][k] = min(ans[j][k], ans[j][i]+ans[i][k]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
	}
	return 0;
}