/*
Time : Sat Aug 19 2017 16:13:49 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/letter-phone/
Given a digit string, return all possible letter combinations that the number could represent.

A 
mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 
maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", 
"bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

*/

#include <bits/stdc++.h>

using namespace std;

void letterCombHelper(string s,int start,int end,vector<string>& ans,map<char,string>& m){
    if(start>end)
        return;
    if(start==end){
        char c = s[start];
        string pat = m[c];
        int l = pat.length();
        for(int i=0;i<l;i++){
            ans.push_back(string(1,pat[i]));
        }
        return;
    }
    string pat = m[s[start]];
    int prev = ans.size();
    letterCombHelper(s,start+1,end,ans,m);
    int now = ans.size();
    for(int i=1;i<pat.length();i++){
        for(int j=prev;j<now;j++){
            string old = ans[j];
            string curr = pat[i] + ans[j];
            ans.push_back(curr);
        }
    }
    for(int j=prev;j<now;j++){
        ans[j] = pat[0] + ans[j];
    }
}

vector<string> Solution::letterCombinations(string A) {
    map<char, string> m; map<char,string>& mapkeys = m;
    m['0']="0";m['1']="1";m['2']="abc";m['3']="def";m['4']="ghi";m['5']="jkl";
    m['6']="mno";m['7']="pqrs";m['8']="tuv";m['9']="wxyz";
    vector<string> a;
    vector<string>& ans = a;
    letterCombHelper(A,0,A.length()-1,ans,mapkeys);
    return ans;
}

int main(){

	return 0;
}
