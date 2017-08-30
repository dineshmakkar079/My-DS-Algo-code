/*
Time : Wed Aug 30 2017 13:56:09 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
Given a 2 * N Grid of numbers, choose numbers such that the sum of the numbers
is maximum and no 
two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Example:

Grid:
	1 
2 3 4
	2 3 4 5
so we will choose
3 and 5 so sum will be 3   5 = 8


Note that you can choose more 
than 2 numbers

*/

#include <bits/stdc++.h>

using namespace std;

int maxsum(vector<vector<int> >& v){
    int n = v[0].size();
    if(n==1) return max(v[0][0], v[1][0]);
    if(n==2) return max(max(v[0][0],v[1][0]), max(v[0][1],v[1][1]));
    int prepreone = v[0][0], prepretwo = v[1][0];
    int preone = v[0][1], pretwo = v[1][1];
    int ans = INT_MIN, tempone, temptwo;
    for(int i=2;i<n;i++){
        int maxi = max(prepreone, prepretwo);
        tempone = v[0][i] + maxi;
        temptwo = v[1][i] + maxi;
        ans = max( ans, max(tempone, temptwo));
        prepreone = max(preone,prepreone);
        prepretwo = max(pretwo,prepretwo);
        preone = max(tempone, preone);
        pretwo = max(temptwo,pretwo);
    }
    return ans;
}

int Solution::adjacent(vector<vector<int> > &A) {
    return maxsum(A);
}

int main(){

	return 0;
}
