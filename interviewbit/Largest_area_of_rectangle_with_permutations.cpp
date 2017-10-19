/*
Time : Thu Oct 19 2017 11:30:42 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
Given a binary grid i.e. a 2D grid only consisting of 0’s and 1’s, find the area of the largest 
rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them. 
You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order 
in the final grid. Please follow the below example for more clarity.

 Lets say we are given a binary 
grid of 3 * 3 size.
1 0 1
0 1 0
1 0 0 
At present we can see that max rectangle satisfying the criteria 
mentioned in the problem is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it. Now 
since we are allowed to permutate the columns of the given matrix, we can take column 1 and column 
3 and make them neighbours. One of the possible configuration of the grid can be:
1 1 0
0 0 1
1 
0 0 
 Now In this grid, first column is column 1, second column is column 3 and third column is 
column 2 from the original given grid. Now, we can see that if we calculate the max area rectangle, 
we get max area as 1 * 2 = 2 which is bigger than the earlier case. Hence 2 will be the answer in 
this case.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::solve(vector<vector<int> > &v) {
    int n = v.size();
    int m = v[0].size();
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            v[i][j] = v[i][j]?1+v[i+1][j]:0;
        }
    }
    for(int i=0;i<n;i++){
        vector<int> count(n+1,0);
        for(int j=0;j<m;j++)
            count[v[i][j]]++;
        int col = 0;
        for(int j=n;j>=0;j--){
            for(int k=0;k<count[j];k++){
                v[i][col++] = j;
            }
        }
    }
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxi = max(maxi, v[i][j]*(j+1));
        }
    }
    return maxi;
}

int main(){

	return 0;
}
