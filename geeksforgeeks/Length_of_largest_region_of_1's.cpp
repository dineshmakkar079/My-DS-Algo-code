/*
Time : Tue Oct 10 2017 11:11:49 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0
Consider a matrix with rows and columns (n,m), where each cell contains either a ‘0’ or a ‘1’ and 
any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are 
adjacent to each other horizontally, vertically, or diagonally .If one or more filled cells are connected, 
they form a region. Your task is to  find the length of the largest region.

Examples:

Input : 
M[][5] = { 0 0 1 1 0
                   1 0 1 1 0
                   0 1 0 0 0
                 
  0 0 0 0 1 }
Output : 6 
Ex: in the following example, there are 
2 regions one with length 1 and 
the other as 6.
so largest region : 6


Input:
The first line of input will be the no of test cases 
T then T test cases follow. The first line of each test case contains Two space separated integers 
n and m. Then in the next line are the nxm inputs of the matrix A separated by space .

Output:
The 
output in the expected output will be the length of the largest region formed.

Constraints:
1<=T<=100
1<=n,m<=50
0<=A[][]<=1

Example:
Input:
2
3 
3
1 1 0 0 0 1 1 0 1
1 3
1 1 1
Output:
4
3
 

** For More Input/Output Examples Use 'Expected Output' 
option **

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

bool inrange(int i,int j,int m,int n){
    return !(i<0||j<0||i>=m||j>=n);
}

void dfs(vvi& mem, vr<vr<bool> >& vis,int i,int j,int& count,int m,int n){
    if(vis[i][j])return;
    vis[i][j]=true;
    count++;
    if(inrange(i+1,j,m,n) && mem[i+1][j]==1)dfs(mem,vis,i+1,j,count,m,n);
    if(inrange(i-1,j,m,n) && mem[i-1][j]==1)dfs(mem,vis,i-1,j,count,m,n);
    if(inrange(i,j+1,m,n) && mem[i][j+1]==1)dfs(mem,vis,i,j+1,count,m,n);
    if(inrange(i,j-1,m,n) && mem[i][j-1]==1)dfs(mem,vis,i,j-1,count,m,n);
    if(inrange(i+1,j+1,m,n) && mem[i+1][j+1]==1)dfs(mem,vis,i+1,j+1,count,m,n);
    if(inrange(i-1,j-1,m,n) && mem[i-1][j-1]==1)dfs(mem,vis,i-1,j-1,count,m,n);
    if(inrange(i+1,j-1,m,n) && mem[i+1][j-1]==1)dfs(mem,vis,i+1,j-1,count,m,n);
    if(inrange(i-1,j+1,m,n) && mem[i-1][j+1]==1)dfs(mem,vis,i-1,j+1,count,m,n);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int m ,n;
	    cin >> m >> n;
	    vvi me(m); vr<vr<bool> > ve(m);
	    vvi& mem = me; vr<vr<bool> >& vis = ve;
	    for(int i=0;i<m;i++){
	        vi v(n); mem[i]=v;
	        vr<bool> v1(n,false); vis[i]=v1;
	    }
	    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> mem[i][j];
            }
        }
        int cou = 0;int& count = cou;
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && mem[i][j]){
                    count = 0;
                    dfs(mem,vis,i,j,count,m,n);
                    ans = max(ans, count);
                }
            }
        }
        cout << ans << endl;
	}
	return 0;
}