/*
Time : Mon Aug 28 2017 15:19:57 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/length-of-longest-subsequence/
Given an array of integers, find the length of longest subsequence which is 
first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 
10 4 2 1]

Return value 6

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::longestSubsequenceLength(const vector<int> &v) {
    int n = v.size();
    if(n==0 || n==1) return n;
    vector<int> lis(n),lds(n);
    for(int i=0;i<n;i++){
        lis[i] = 1; lds[i] = 1;
    }
    // lis = length of longest increasing subsequence ending at index i;
    int ans = INT_MIN;
    for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            if(v[i]<v[j]){
                lis[j] = max(lis[j], lis[i] + 1);
            }
        }
    }
    // lds = length of longest decreasing subsequence starting at index i;
    for(int j=n-2;j>=0;j--){
    	for(int i=j+1;i<=n-1;i++){
    		if(v[i]<v[j]){
    			lds[j] = max(lds[j], lds[i] + 1);
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	ans = max(ans, lis[i] + lds[i] - 1); // -1 to avoid inclusion of element at index i
    }                                           // twice .
    return ans;
}

int main(){

	return 0;
}
