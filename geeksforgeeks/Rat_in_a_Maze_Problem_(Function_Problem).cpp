/*
Time : Mon Oct 16 2017 14:54:44 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination 
at (n-1, n-1). Your task is to complete the function which returns a sorted array of strings denoting 
all the possible directions which the rat can take to reach the destination at (n-1, n-1). The directions 
in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

For example
1 0 0 0
1 
1 0 1
1 1 0 0
0 1 1 1

For the above matrix the rat can reach the destination at (3, 3) from (0, 
0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.

Input:
The 
first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains two lines. The first line contains an integer n denoting the size of the 
square matrix. The next line contains n*n space separated values of the matrix m where 0's represents 
blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated 
sorted strings denoting all directions, which the rat could take to reach the destination.

Constraints:
1<=T<=10
2<=n<=10
0<=m[][]<=1

Example(To 
be used only for expected output):
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 
1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR 
 

 

** For More Input/Output Examples Use 'Expected 
Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */

bool inrange(int i,int j,int n){
    return (i<n && j<n && i>=0 && j>=0);
}

void find(int i,int j,int m[MAX][MAX],int n,vector<string>& ans,string path,vector<vector<bool> >& vis){
    if(!inrange(i,j,n) || vis[i][j] || m[i][j]==0)return;
    if(i==n-1 && j==n-1){
        ans.push_back(path);
    }
    vis[i][j] = true;
    find(i+1,j,m,n,ans,path+"D",vis);
    find(i,j-1,m,n,ans,path+"L",vis);
    find(i,j+1,m,n,ans,path+"R",vis);
    find(i-1,j,m,n,ans,path+"U",vis);
    vis[i][j] = false;
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> a;
    vector<string>& ans = a;
    vector<vector<bool> > v(n,vector<bool>(n,false));vector<vector<bool> >& vis=v;
    string s = "";
    if(m[0][0]==0 || m[n-1][n-1]==0)
        return ans;
    find(0,0,m,n,ans,"",vis);
    return ans;
}

int main(){

	return 0;
}
