/*
Time : Sat Aug 26 2017 13:16:53 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/longest-palindromic-substring/
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] 
where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, 
S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first 
( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

*/

#include <bits/stdc++.h>

using namespace std;

string Solution::longestPalindrome(string s) {
    int n = s.length();
	vector<bool> last(n),prev(n), curr(n);
	int maxistart = 0, maxiend = 0, maxi = 1;
	for (int i = 0; i < n-1; ++i)
	{
		last[i] = 1;
		prev[i] = (s[i]==s[i+1])?true:false;
		if (prev[i] && maxi !=2)
		{
			maxi = 2; maxistart=i; maxiend = i+1;
		}
	}
	last[n-1] = true;
	int count = 2;
	for (int diff = 2; diff < n; diff++)
	{
		for (int i = 0; i < n-diff; i++)
		{
			int j = i+diff;
			// Diagonal under consideration uses only previous two diagonals
			// oldest diagonal = last
			// oldest but one diagonal = prev
			curr[i] = s[i]==s[j] && last[i+1] ?true : false;
			if (curr[i] && maxi < j-i+1)
			{
				maxi = j-i+1; maxistart=i; maxiend = j;
			}
		}
		last = prev, prev = curr;
	}
	string ans = "";
	for(int i=maxistart;i<=maxiend;i++) ans+=s[i];
	return ans;
}

int main(){

	return 0;
}
