/*
Time : Tue Aug 29 2017 10:56:28 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/total-decoding-messages/0
A top secret message containing letters from A-Z is being encoded to numbers using the following 
mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total 
number of ways that message can be decoded.
Note: An empty digit sequence is considered to have 
one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are 
leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example 
:
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
So 
total ways are 3.

Input:
First line contains the test cases T.  1<=T<=1000
Each test case have 
two lines
First is length of string N.  1<=N<=40
Second line is string S of digits from '0' to '9' 
of N length.

Example:
Input:
2
3
123
4
2563
Output:
3
2
 

**For More Examples Use Expected Output**

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

int ways(string s){
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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string in ;
	    cin >> in;
        cout << ways(in) << endl;
	}
	return 0;
}