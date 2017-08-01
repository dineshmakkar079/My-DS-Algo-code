/*
Time : Tue Aug 01 2017 19:10:45 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/2-sum/
Given an array of integers, find two numbers such that they add up to a specific target number.

The 
function twoSum should return indices of the two numbers such that they add up to the target, where 
index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 

Put both these numbers in order in an array and return the array from your function ( Looking at 
the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If 
multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions 
with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], 
target=9
Output: index1 = 1, index2 = 2

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::twoSum(const vector<int> &A, int B) {
	std::vector<int> ret;
	std::map<int, int> m;
	std::map<int, int> :: iterator it;
	int l=A.size();
	for(int i=0;i<l;i++){
		it = m.find(B-A[i]);
		if(it == m.end()){
		    if(m.find(A[i])==m.end())
			    m[A[i]] = i;
		}else{
			int index1 = INT_MAX;
			it = m.begin();
			while(it!=m.end()){
				if(it->first==(B-A[i]) && it->second < index1){
					index1 = it->second;
				}
				it++;
			}
			ret.push_back(index1+1);
			ret.push_back(i+1);
			return ret;
		}
	}
	return ret;
}

int main(){

	return 0;
}
