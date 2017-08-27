/*
Time : Sun Aug 27 2017 11:31:20 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/unique-paths-in-a-grid/
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). 
At any instance, if you are on (x,y), you can either go to (x, y   1) or (x   1, y).

Now consider 
if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and 
empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the 
middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number 
of unique paths is 2.

 Note: m and n will be at most 100.

*/

#include <bits/stdc++.h>

using namespace std;

int unique(vector<vector<int> >& grid, vector<vector<int> >& paths,int m,int n){
    if(m<0 || n<0)  return 0;
    if(grid[m][n]){ paths[m][n] = 0; return 0; }
    if(paths[m][n]!=-1)return paths[m][n];
    int one = unique(grid,paths,m,n-1);
    int two = unique(grid,paths,m-1,n);
    paths[m][n] = one + two;
    return paths[m][n];
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int> > p(m);
    vector<vector<int> >& paths = p;
    for (int i = 0; i < m; i++){ vector<int> v(n); for (int j = 0; j < n; j++) { v[j] = -1; } paths[i] = v; }
    int i=0;
    while(i<m && !grid[i][0])
        paths[i++][0] = 1;
    while(i<m)
        paths[i++][0] = 0;
    i=0;
    while(i<n && !grid[0][i])
        paths[0][i++] = 1;
    while(i<n)
        paths[0][i++] = 0;
    return grid[0][0]==0?unique(grid, paths,m-1,n-1):0;
}

int main(){

	return 0;
}
