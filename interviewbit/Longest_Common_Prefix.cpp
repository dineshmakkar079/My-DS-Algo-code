/*
Time : Sat Sep 02 2017 17:05:56 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/longest-common-prefix/
Write a function to find the longest common prefix string amongst an array of strings.

Longest 
common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both 
S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the 
array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given 
the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.

*/

#include <bits/stdc++.h>

using namespace std;

string helper(string a,string b){
    int l1 = a.length(), l2 = b.length();
    if(l1==0 || l2==0) return "";
    string ans = "";
    for(int i=0,j=0;i<l1&&j<l2;i++,j++){
        if(a[i]!=b[j])return ans;
        ans += a[i];
    }
    return ans;
}

string Solution::longestCommonPrefix(vector<string> &a) {
    int n = a.size();
    if(n==0) return "";
    if(n==1) return a[0];
    string ans = a[0];
    for(int i=1;i<n;i++){
        ans = helper(a[i], ans);
    }
    return ans;
}

int main(){

	return 0;
}
