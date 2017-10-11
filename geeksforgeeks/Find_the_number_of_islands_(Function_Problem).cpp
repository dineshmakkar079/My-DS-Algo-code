/*
Time : Tue Oct 10 2017 22:32:58 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
A group of connected 1s forms an island now your task is to complete the method findIslands which 
returns the no of islands present. The function  takes three arguments the first is the boolean 
matrix A and then the next two arguments are N and M denoting the size of the matrix A . 

Input:
The 
first line of input will be the no of test cases T then T test cases follow. The first line of each 
test case contains Two space separated integers N and M. Then in the next line are the NxM inputs 
of the matrix A separated by space .

Output:
The output in the expected output will be the total 
no of islands present. 

Constraints:
1<=T<=100
1<=N,M<=50
0<=A[][]<=1

Example(To be used only 
for expected output) :
Input
1
3 3
1 1 0 0 0 1 1 0 1
Output
2

Explanation
The graph will look like
1 
1 0
0 0 1
1 0 1
Here  two islands will be formed
First island will be formed by elements { A[0][0] 
,  A[0][1], A[1][2], A[2][2] }
Sec island will be formed by  { A[2][0] } 

Note:The Input/Ouput 
format and Example given are used for system's internal purpose, and should be used by a user for 
Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.

** For More Input/Output 
Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*you are required to complete this method*/
bool inrange(int i,int j,int n,int m){
    if(i>=n || j>=m || i<0 || j<0)return false;
    return true;
}

void dfs(int A[MAX][MAX],vector<vector<int> >& mem,int row,int col,int color,int n,int m){
    if(mem[row][col]!=-1 || A[row][col]==0)return;
    mem[row][col] = color;
    if(inrange(row+1,col,n,m)) dfs(A,mem,row+1,col,color,n,m);
    if(inrange(row-1,col,n,m)) dfs(A,mem,row-1,col,color,n,m);
    if(inrange(row,col+1,n,m)) dfs(A,mem,row,col+1,color,n,m);
    if(inrange(row,col-1,n,m)) dfs(A,mem,row,col-1,color,n,m);
    if(inrange(row+1,col+1,n,m)) dfs(A,mem,row+1,col+1,color,n,m);
    if(inrange(row+1,col-1,n,m)) dfs(A,mem,row+1,col-1,color,n,m);
    if(inrange(row-1,col+1,n,m)) dfs(A,mem,row-1,col+1,color,n,m);
    if(inrange(row-1,col-1,n,m)) dfs(A,mem,row-1,col-1,color,n,m);
}

int findIslands(int A[MAX][MAX], int n, int m)
{
    vector<vector<int> > me(n);
    vector<vector<int> >& mem = me;
    for(int i=0;i<n;i++){
        vector<int> ve(m,-1); mem[i]=ve;
    }
    int color = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1 && mem[i][j]==-1){
                color++;
                dfs(A,mem,i,j,color,n,m);
            }
        }
    }
    return color;
}

int main(){

	return 0;
}
