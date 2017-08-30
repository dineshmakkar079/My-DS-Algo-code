/*
Time : Tue Aug 29 2017 21:14:29 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/jump-game-array/
Given an array of non-negative integers, you are initially positioned at the first index of the 
array.

Each element in the array represents your maximum jump length at that position.

Determine 
if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = 
[3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::canJump(vector<int> &a) {
    int n = a.size();
    if(n==1&&a[0]==0) return 1;
    if(a[0]==0) return 0;
    int end = 1;
    for(int i=0;i<n;i++){
        if(a[i]!=0 && end >= i)
            end = max(end, i+a[i]);
    }
    return end>=n-1;
}

int main(){

	return 0;
}
