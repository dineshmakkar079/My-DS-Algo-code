/*
Time : Sat Sep 02 2017 11:43:28 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/matrix-search/
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the 
following properties:

Integers in each row are sorted from left to right.
The first integer of 
each row is greater than or equal to the last integer of the previous row.
Example:

Consider the 
following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 
3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the 
element is present ) for this problem

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::searchMatrix(vector<vector<int> > &m, int k) {
    int low = 0, high = m.size()-1, mid;
	int row,col;
	while(low<=high){
		mid = (low+high)/2;
		if(m[mid][0] == k) return 1;
		else if(m[mid][0] < k)
			low=mid+1;
		else
			high=mid-1;
		if(m[mid][0] < k && m[mid][m[0].size()-1] >= k){
			row = mid; break;
		}
	}
	low = 0, high = m[0].size()-1;
	while(low<=high){
		mid=(low+high)/2;
		if(m[row][mid]==k) return 1;
		else if(m[row][mid] < k)
			low=mid+1;
		else
			high=mid-1;
	}
	return 0;
}

int main(){

	return 0;
}
