/*
Time : Thu Oct 19 2017 14:13:06 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/longest-valid-parentheses/
Given a string containing just the characters '(' and ')', find the length of the longest valid 
(well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", 
which has length = 2.

Another example is ")()())", where the longest valid parentheses substring 
is "()()", which has length = 4.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::longestValidParentheses(string s) {
    stack<int> st;
    int n = s.length();
    st.push(-1);
    int maxi = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }else{
                maxi = max(maxi, i - st.top());
            }
        }
    }
    return maxi;
}

int main(){

	return 0;
}
