/*
Time : Sun Jul 02 2017 10:47:23 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/nearest-smaller-element/
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that
the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that j is maximum possible AND j < i AND A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10]
Return : [-1, 4, -1, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]

*/

vector<int> Solution::prevSmaller(vector<int> &A) {
	vector<int> v;
	stack<int> s;
	int l = A.size();
	for(int i=0;i<l;i++){
	    while(!s.empty() && s.top() >= A[i]){
	        s.pop();
	    }
	    v.push_back(s.empty() ? -1 :s.top());
	    s.push(A[i]);
	}
	return v;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
