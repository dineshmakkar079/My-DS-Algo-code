/*
Time : Wed Aug 30 2017 21:21:26 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/min-sum-path-in-triangle/
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent 
numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   
[6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2   3   5   1 = 11).

 
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number 
of rows in the triangle.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::minimumTotal(vector<vector<int> > &tri) {
    int n = tri.size();
    std::vector<std::vector<int> > mem(n);
    for(int i=0;i<n;i++){
        std::vector<int> v(i+1);
        for(int j=0;j<i+1;j++)
            v[j] = INT_MAX;
        mem[i] = v;
    }
    mem[0][0] = tri[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j>0&&j<i){
                mem[i][j] = min(mem[i][j], min(mem[i-1][j] + tri[i][j], mem[i-1][j-1] + tri[i][j]));
            }else if(j==0){
                mem[i][j] =  mem[i-1][j] + tri[i][j];
            }else if(j==i){
                mem[i][j] =  mem[i-1][j-1] + tri[i][j];
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++)ans = min(ans, mem[n-1][i]);
    return ans;
}

int main(){

	return 0;
}
