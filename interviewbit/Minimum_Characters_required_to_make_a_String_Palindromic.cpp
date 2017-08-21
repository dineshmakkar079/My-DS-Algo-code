/*
Time : Mon Aug 21 2017 23:53:32 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
You are given a string. The only operation allowed is to insert characters in the beginning of the 
string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: 
ABC
Output: 2
Input: AACECAAAA
Output: 2

*/

#include <bits/stdc++.h>

using namespace std;

string reverse(string str){
    string s = "";
    for(int i=str.length()-1;i>=0;i--)
        s += str[i];
    return s;
}

int Solution::solve(string str) {
    int l = str.length();
    string calc = str + reverse(str);
    bool sim = true;
    for(int i=0;i<l;i++){
        if(str[i]!=str[l-1-i]){
            sim = false;
            break;
        }
    }
    if(sim)return 0;
    int c = calc.length();
    vector<int> lps(c);
    int len = 0, i = 1; 
    lps[0] = 0;
    while(i<c){
        if(calc[i]==calc[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0)
                len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return (l-lps[c-1]);
}

int main(){

	return 0;
}
