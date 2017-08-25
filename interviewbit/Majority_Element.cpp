/*
Time : Fri Aug 25 2017 18:28:02 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/majority-element/
Given an array of size n, find the majority element. The majority element is the element that appears 
more than floor(n/2) times.

You may assume that the array is non-empty and the majority element 
always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which 
is greater than 3/2.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::majorityElement(const vector<int> &a) {
    int n = a.size();
	int major = a[0], majorcount = 1;
	for(int i=1;i<n;i++){
		if(a[i]==major){
			majorcount++;
		}else{
			majorcount--;
		}
		if(majorcount==0){
			major = a[i];
			majorcount = 1;
		}
	}
	return major;
}

int main(){

	return 0;
}
