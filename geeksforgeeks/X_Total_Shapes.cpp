/*
Time : Mon Oct 09 2017 09:37:38 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/x-total-shapes/0
Given N * M string array of O's and X's
Return the number of 'X' total shapes. 'X' shape consists 
of one or more adjacent X's (diagonals not included).

Example (1):

OOOXOOO
OXXXXXO
OXOOOXO

answer 
is 1 , shapes are  :
(i)     X
    X X X X
    X     X
 

Example (2):

XXX
OOO
XXX

answer is 2, 
shapes are
(i)  XXX

(ii) XXX

Input:
The first line of input takes the number of test cases, T.
Then 
T test cases follow. Each of the T test cases takes 2 input lines.
The first line of each test case 
have two integers N and M.The second line of N space separated strings follow which indicate the 
elements in the array.

Output:

Print number of shapes.

Constraints:

1<=T<=100

1<=N,M<=50

Example:

Input:
2
4 
7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

** 
For More Input/Output Examples Use 'Expected Output' option **

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

bool inrange(int i,int j,int n,int m){
    if(i>=n || j>=m || i<0 || j<0)return false;
    return true;
}

void dfs(vr<string>& v,vvi& mem,int row,int col,int color,int n,int m){
    if(mem[row][col]!=-1 || v[row][col]=='O')return;
    mem[row][col] = color;
    if(inrange(row+1,col,n,m)) dfs(v,mem,row+1,col,color,n,m);
    if(inrange(row-1,col,n,m)) dfs(v,mem,row-1,col,color,n,m);
    if(inrange(row,col+1,n,m)) dfs(v,mem,row,col+1,color,n,m);
    if(inrange(row,col-1,n,m)) dfs(v,mem,row,col-1,color,n,m);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int m ,n;
	    cin >> n >> m;
	    vector<string> ve(n);
	    vr<string>& v= ve;
	    for(int i=0;i<n;i++)cin>>v[i];
	    vvi me(n);
	    vvi& mem = me;
	    for(int i=0;i<n;i++){
	        vi ve(m,-1); mem[i]=ve;
	    }
	    int color = 0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(v[i][j]=='X' && mem[i][j]==-1){
	                color++;
	                dfs(v,mem,i,j,color,n,m);
	            }
	        }
	    }
	    cout << color << endl;
	}
	return 0;
}