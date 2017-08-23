/*
Time : Wed Aug 23 2017 14:20:27 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/longest-substring-without-repeat/#
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The 
longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For 
"bbbbb" the longest substring is "b", with the length of 1.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::lengthOfLongestSubstring(string s) {
    int n = s.length();
    int hash[260]; 
    memset(hash, 0, sizeof(hash));
    int ans = 1;
    int start = 0, end = 0;
    while(start <= end && end < n){
        hash[s[end]]++;
        while(hash[s[end]] > 1){
            hash[s[start]]--;
            start++;
        }
        end++;
        ans = max(ans, end-start);
    }
    return ans;
}

int main(){

	return 0;
}
