/*
Time : Sat Jul 01 2017 22:19:34 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/redundant-braces/
Write a program to validate if the input string has redundant braces?
Return 0/1
 0 -> NO 1 -> YES

Input will be always a valid expression

and operators allowed are only   , * , - , /

Example:

((a +  b)) has redundant braces so answer will be 1
(a  + (a +  b)) doesn't have have any redundant braces
so answer will be 0

*/

int Solution::braces(string str) {
    int l = str.length();
	stack<int> s;
	int prev = -10,now = -1;
	bool first = false,second = false;
	for(int i=0;i<l;i++){
		if(str[i]=='('){
			s.push(i);
		}else if(str[i]==')'){
			now = i - s.top(); s.pop();
			if(now == prev + 2 || now == 2)
				return 1;
			prev = now;
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
	char c = '0';
	cout << to_int(c) + 1 <<endl;
	return 0;
}
