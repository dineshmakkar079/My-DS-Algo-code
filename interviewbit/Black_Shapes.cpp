/*
Time : Mon Oct 09 2017 09:52:12 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/black-shapes/
Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black 
shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer 
is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking 
for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.

*/

#include <bits/stdc++.h>

using namespace std;

bool inrange(int i,int j,int n,int m){
    if(i>=n || j>=m || i<0 || j<0)return false;
    return true;
}

void dfs(vector<string>& v,vector< vector<int> >& mem,int row,int col,int color,int n,int m){
    if(mem[row][col]!=-1 || v[row][col]=='O')return;
    mem[row][col] = color;
    if(inrange(row+1,col,n,m)) dfs(v,mem,row+1,col,color,n,m);
    if(inrange(row-1,col,n,m)) dfs(v,mem,row-1,col,color,n,m);
    if(inrange(row,col+1,n,m)) dfs(v,mem,row,col+1,color,n,m);
    if(inrange(row,col-1,n,m)) dfs(v,mem,row,col-1,color,n,m);
}

int Solution::black(vector<string> &v) {
    int n=v.size(), m=v[0].size();
    vector< vector<int> > me(n);
    vector< vector<int> >& mem = me;
    for(int i=0;i<n;i++){
        vector<int> ve(m,-1); mem[i]=ve;
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
    return color;
}

int main(){

	return 0;
}
