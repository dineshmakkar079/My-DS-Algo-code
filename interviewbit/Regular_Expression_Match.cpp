/*
Time : Thu Oct 19 2017 17:26:31 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/regular-expression-match/
Implement wildcard pattern matching with support for '?' and '*'.

'?' : Matches any single character.
'*' 
: Matches any sequence of characters (including the empty sequence).
The matching should cover the 
entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, 
const char *p)
Examples :

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", 
"*") → 1
isMatch("aa", "a*") → 1
isMatch("ab", "?*") → 1
isMatch("aab", "c*a*b") → 0
Return 1/0 
for this problem.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::isMatch(const string &s, const string &p) {
    int n = s.length();
    int m = p.length();
    vector<vector<bool> > mem(n+1,vector<bool>(m+1,false));
    mem[0][0] = true;
    for(int i=1;i<m+1;i++){
        if(p[i-1]=='*')
            mem[0][i] = mem[0][i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p[j-1]=='?' || p[j-1]==s[i-1])
                mem[i][j] = mem[i-1][j-1];
            else if(p[j-1]=='*')
                mem[i][j] = mem[i-1][j] || mem[i][j-1];
            else
                mem[i][j] = false;
        }
    }
    return mem[n][m];
}

int main(){

	return 0;
}
