/*
Time : Sat Jul 01 2017 19:44:54 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/generate-all-parentheses/
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all
valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

PROBLEM
APPROACH :

Complete solution in hints.

*/

int Solution::isValid(string A) {
	stack<char> s;
	int l = A.length();
	for(int i=0;i<l;i++){
	    bool cond = A[i] == '{' || A[i] == '[' || A[i] == '(';
		if(s.empty() && !cond){
			return 0;
		}else{
			if(cond){
				s.push(A[i]);
			}else{
				switch(A[i]){
					case ')' : if(s.top() != '(') return 0; s.pop(); break;
					case '}' : if(s.top() != '{') return 0; s.pop(); break;
					case ']' : if(s.top() != '[') return 0; s.pop(); break;
				}
			}
		}
	}
	if(!s.empty())
		return 0;
	return 1;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
