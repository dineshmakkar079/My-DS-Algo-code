/*
Time : Wed Sep 06 2017 17:59:26 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/special-matrix/0
You are given a matrix having N rows and M columns. The special property of this matrix is that 
some of the cells of this matrix are blocked
i.e. they cannot be reached. Now you have to start 
from the cell (1,1) and reach the end (N,M) provided during the journey you can move horizontally 
right from the current cell or vertically down from the current cell.
Can you answer the number 
of ways you can traverse the matrix obeying the above constraints starting from (1,1) and ending 
at (N,M).

Output your answer modulo 10^9 7.
 

Input :
The first line contains T, the number of 
test cases. Then T test cases follow.
Each test case consists of two lines.
The first line contains  
three integers N,M and K denoting the number of rows, the number of columns and the number of blocked 
cells in the matrix respectively. The next line contains space separated 2*K integers denoting the 
positions of the blocked cells in the form R1 C1 R2 C2 R3 C3…..RK CK.
 

Output :
For each test 
case output the the number of ways modulo 10^9 7 in a new line.
 

Constraints :
1<=T<=100
1<=N<=1000
1<=M<=1000
1<=K<N*M
1<=Ri<=N
1<=Ci<=M
It 
is guaranteed that the cell (1,1) will never be blocked.
 

Example
Input 
1
3 3 2
1 2 3 2
Output 
:   
1
 

Explanation :
For the above test case there is only one path from (1,1) to(3,3) which 
is
(1,1)->(2,1)->(2,2)->(2,3)->(3,3)

**For More Examples Use Expected Output**

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

void solve(vvi& mem, vvi& a){
    int n=mem.size(), m =mem[0].size();
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(!a[i][j]){
                mem[i][j] += a[i-1][j]?0:mem[i-1][j];
                mem[i][j]%=mod;
                mem[i][j] += a[i][j-1]?0:mem[i][j-1];
                mem[i][j]%=mod;
            }
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m,k;
	    cin >> n >> m >>k;
	    vvi arr(n),me(n); vvi&  a = arr;vvi& mem = me;
	    for(int i=0;i<n;i++){
	        vi v(m),m1(m);
            init(v,m,0);
            init(m1,m,0);
            mem[i] = m1;
            a[i] = v;
        }
        for(int i=0;i<k;i++){
            int r,c;
            cin >> r>>c; a[r-1][c-1]=1;
        }
        int reachdown = 1;
        mem[0][0]=1;
        for(int i=1;i<n;i++){
            if(a[i][0]==1)
                reachdown = 0;
            mem[i][0]=reachdown;
        }
        int reachright = 1;
        for(int i=1;i<m;i++){
            if(a[0][i]==1)
                reachright = 0;
            mem[0][i]=reachright;
        }
        solve(mem,a);
        cout << mem[n-1][m-1] << endl;
	}
	return 0;
}