/*
Time : Sat Sep 02 2017 11:21:15 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/search-for-a-range/
Given a sorted array of integers, find the starting and ending position of a given target value.

Your 
algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in 
the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::searchRange(const vector<int> &a, int k) {
    double kr = k+0.5, kl = k-0.5;
	std::vector<int> ans(2);ans[0] = -1; ans[1] = -1;
	if(!binary_search(a.begin(),a.end(),k)){
		 return ans;
	}
	int low = 0,high = a.size()-1,mid;
	while(low<=high){
		mid = (low+high)/2;
		if(a[mid]>kr)
			high = mid - 1;
		else
			low = mid+1;
	}
	ans[1] = mid;
	if(a[mid]!=k){
		if(mid+1 < a.size() && a[mid+1]==k)ans[1] = mid+1;
		if(mid-1 >= 0 && a[mid-1]==k)ans[1] = mid-1;
	}
	low = 0; high = a.size()-1;
	while(low<=high){
		mid = (low+high)/2;
		if(a[mid]>kl)
			high = mid-1;
		else
			low = mid+1;
	}
	ans[0] = mid;
	if(a[mid]!=k){
		if(mid+1 < a.size() && a[mid+1]==k)ans[0] = mid+1;
		if(mid-1 >= 0 && a[mid-1]==k)ans[0] = mid-1;
	}
	return ans;
}

int main(){

	return 0;
}
