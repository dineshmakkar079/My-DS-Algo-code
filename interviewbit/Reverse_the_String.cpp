/*
Time : Wed Aug 23 2017 21:55:38 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/reverse-the-string/
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return 
"blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string 
should not contain leading or trailing spaces, even if it is present in the input string.
If there 
are multiple spaces between words, reduce them to a single space in the reversed string.

*/

#include <bits/stdc++.h>

using namespace std;

void Solution::reverseWords(string &s) {
    vector<string> v;
    int n = s.length();
    string t = "";
    int i=0;
    while(i<n){
        while(i<n&&s[i]==' ')
            i++;
        while(i<n&&s[i]!=' '){
            t+=s[i];i++;
        }
        v.push_back(t);
        t="";
    }
    int c = v.size();
    string ans = "";
    for(int i=c-1;i>=0;i--){
        ans += v[i];
        if(i!=0)
            ans += " ";
    }
    s = ans;
}

int main(){

	return 0;
}
