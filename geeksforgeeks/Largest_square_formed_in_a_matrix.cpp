/*
Time : Wed Oct 11 2017 12:00:02 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first 
line of input contains an integer T denoting the number of test cases.
The first line of each test 
case is n and m,n is the number of rows and m is the number of columns.
The second line of each 
test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 
≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 
0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0
 

** For More Input/Output Examples 
Use 'Expected Output' option **

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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    vvi v(n, vi(m));
	    vvi mem(n, vi(m,0)) , row(n,vi(m,0)), col(n,vi(m,0));
	    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
                mem[i][j] = v[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i)row[i][j] = v[i][j];
                else{
                    if(!v[i][j]) row[i][j] = 0;
                    else row[i][j] = v[i][j]+ row[i-1][j];
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(!j) col[i][j] = v[i][j];
                else{
                    if(!v[i][j]) col[i][j] = 0;
                    else{
                        if(!v[i][j]) col[i][j] =0;
                        else col[i][j] = v[i][j] + col[i][j-1];
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i || !j) mem[i][j] = v[i][j];
                else if(!v[i][j]) mem[i][j] = 0;
                else{
                    mem[i][j] = min(1 + mem[i-1][j-1], min(row[i][j],col[i][j]) );
                }
                ans = max(ans, mem[i][j]);
            }
        }
        cout << ans << endl;
        for(int i=0;i<n;i++){
            mem[i].clear(); row[i].clear(); col[i].clear(); v[i].clear();
        }
        mem.clear(); row.clear(); col.clear(); v.clear();
	}
	return 0;
}