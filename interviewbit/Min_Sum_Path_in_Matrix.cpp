/*
Time : Sun Aug 27 2017 12:03:42 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/min-sum-path-in-matrix/
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which 
minimizes the sum of all numbers along its path.

 Note: You can only move either down or right 
at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output 
: 8
     1 -> 3 -> 2 -> 1 -> 1

*/

#include <bits/stdc++.h>

using namespace std;

int getminsum(vector<vector<int> >& grid,vector<vector<int> >& sums,int m,int n){
    if(m<0 || n<0) return 0;
    if(sums[m][n]!=-1) return sums[m][n];
    int one = getminsum(grid, sums, m-1, n);
    int two = getminsum(grid, sums, m, n-1);
    sums[m][n] = (grid[m][n] + min(one,two));
    return sums[m][n];
}

int Solution::minPathSum(vector<vector<int> > &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int> > p(m);
    vector<vector<int> >& sums = p;
    for (int i = 0; i < m; i++){
        vector<int> v(n);
        for(int j=0;j<n;j++) v[j] = -1;
        sums[i] = v; 
    }
    sums[0][0] = grid[0][0];
    for (int i=1;i<m;i++){ sums[i][0] = grid[i][0] + sums[i-1][0];}
    for (int i=1;i<n;i++){ sums[0][i] = grid[0][i] + sums[0][i-1];}
    return getminsum(grid, sums, m-1, n-1);
}

int main(){

	return 0;
}
