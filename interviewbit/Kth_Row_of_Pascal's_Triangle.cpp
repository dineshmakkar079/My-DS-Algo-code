/*
Time : Thu Aug 31 2017 01:05:23 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate 
A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return 
: [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your 
algorithm to use only O(k) extra space?

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::getRow(int n) {
    std::vector<int> ans(n+1);
	for(int i=0;i<n;i++) ans[i] = -1;
	ans[0] = 1; if(n==0) return ans;
	ans[1] = 1; if(n==1) return ans;
	for(int i=2;i<n+1;i++){
		ans[i] = 1;
		for(int j=i-1;j>=1;j--){
			ans[j] += ans[j-1];
		}
	}
	return ans;
}

int main(){

	return 0;
}
