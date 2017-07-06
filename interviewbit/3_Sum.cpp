/*
Time : Thu Jul 06 2017 11:20:38 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/3-sum/
Given an array S of n integers, find three integers in S such that the sum is closest 
to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 

given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1   2   1 = 2)

*/

#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> A, int B) {
	sort(A.begin(), A.end());
	int l = A.size();
	int thissum = INT_MIN;
	for(int i=0;i<l;i++){
		int start = 0,end = l-1;
		int sum = A[i] + A[start==i?++start:start] + A[end==i?--end:end];
		while(start <  end && end >=0 && start <= l-1){
			if(sum == B)
				return B;
			else if(sum < B)
				++start==i?++start:start;
			else
				--end==i?--end:end;
			if(start!=end)
				sum = A[i] + A[start] + A[end];
		}
		if(abs(thissum-B) > abs(sum-B))
			thissum = sum;
	}
	return thissum;
}

int main(){
	std::vector<int> v(4);
	v[0]=-1;
	v[1]=2;
	v[2]=1;
	v[3]=-4;
	cout << threeSumClosest(v,-1);
	return 0;
}
