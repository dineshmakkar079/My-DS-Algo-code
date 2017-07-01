/*
Time : Sat Jul 01 2017 23:57:27 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/evaluate-expression/
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are + , -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+ ", "3", "*"] -> ((2   1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4   (13 / 5)) -> 6

*/

#include <bits/stdc++.h>

using namespace std;

bool isOperator(string str){
	return str=="+" || str=="-" || str=="*" || str=="/";
}

int Solution::evalRPN(vector<string> &A) {
	int l = A.size();
	stack<int> s;
	for(int i=0;i<l;i++){
		if(!isOperator(A[i])){
			s.push(stoi(A[i]));
		}else{
			int two = s.top(); s.pop();
			int one = s.top(); s.pop();
			switch((int)A[i][0]){
				case 43 : s.push(one + two); break;
				case 45 : s.push(one - two); break;
				case 42 : s.push(one * two); break;
				case 47 : s.push(one / two); break;
			}
		}
	}
	return s.top();
}

int main(){
	std::string s = "12";
	cout << std::stoi(s) +1<<endl;
	return 0;
}
