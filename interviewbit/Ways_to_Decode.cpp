/*
Time : Tue Aug 29 2017 10:54:41 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/ways-to-decode/
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' 
-> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number 
of ways to decode it.

Example :

Given encoded message "12", it could be decoded as "AB" (1 2) 
or "L" (12).

The number of ways decoding "12" is 2.

*/

#include <bits/stdc++.h>

using namespace std;

bool isvalid(string s){
    if(s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9")
        return true;
    else if(s=="10"||s=="11"||s=="12"||s=="13"||s=="14"||s=="15"||s=="16")
        return true;
    else if(s=="17"||s=="18"||s=="19")
        return true;
    else if(s=="20"||s=="21"||s=="22"||s=="23"||s=="24"||s=="25"||s=="26")
        return true;
    return false;
}

int Solution::numDecodings(string s) {
    int ans = 0, n = s.length();
    if(n==0) return 0;
	if(n==1) return s[0]=='0' ? 0 : 1;
	if(s[0]=='0') return 0;
	// curr - answer till ith element
	// pre - answer till (i-1)th el
	// prepre - answer till (i-2)th  el
	int curr, prepre = 1, pre = 1;
	for (int i = 1; i < n; i++){
	    string temp1="",temp2 = "";
	    temp1 += s[i-1]; temp1 += s[i];
	    temp2 += s[i];
	    if(isvalid(temp1) && isvalid(temp2)){
	       curr = pre + prepre;
	       prepre = pre;
	       pre = curr;
	    }else if(isvalid(temp2)){
	       curr = pre;
	       prepre = pre;
	    }else if(isvalid(temp1)){
	       curr = prepre; prepre = pre; pre = curr;
	    }else{
	        return 0;
	    }
	}
	return curr;
}

int main(){

	return 0;
}
