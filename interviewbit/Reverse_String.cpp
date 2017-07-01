/*
Time : Sat Jul 01 2017 20:03:23 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/reverse-string/
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"
PROBLEM
APPROACH :

Complete solution in hints.

*/

string Solution::reverseString(string A) {
	stack<char> s;
	string ans = "";
	int l = A.length();
	for(int i=0;i<l;i++){
		s.push(A[i]);
	}
	while(!s.empty()){
		ans += s.top();
		s.pop();
	}
	return ans;
}


#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
