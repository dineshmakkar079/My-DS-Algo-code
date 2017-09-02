/*
Time : Sat Sep 02 2017 16:59:16 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/implement-strstr/
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not 
to use standard library string functions for this question.

Returns the index of the first occurrence 
of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What 
should be the return value if the needle is empty?
What if both haystack and needle are empty?
For 
the purpose of this problem, assume that the return value should be -1 in both cases.

*/

#include <bits/stdc++.h>

using namespace std;

void kmparr(const string& pat,vector<int>& lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.length())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const string& pat,const string& txt){
    int M = pat.length();
    int N = txt.length();
    vector<int> l(M);
    vector<int>& lps = l;
    kmparr(pat,lps);
    int i = 0; 
    int j  = 0; 
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            return (i-j);
            j = lps[j-1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return -1;
}

int Solution::strStr(const string &s1, const string &s2) {
    int l1 = s1.length(), l2 = s2.length();
    if(l1==0 || l2==0 || l1 < l2) return -1;
    return KMPSearch(s2,s1);
}

int main(){

	return 0;
}
