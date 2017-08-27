/*
Time : Sun Aug 27 2017 20:03:21 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
Given two sequences, find the length of longest subsequence present in both of them. Both the strings 
are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases 
follow.
Each test case consist of 2 space separated integers A and B denoting the size of string 
str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .


Output:
For 
each test case print the length of longest  common subsequence of the two strings .


Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100


Example:
Input:
2
6 
6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” 
is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
 

**For More Examples Use Expected 
Output**

*/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int lcshelper(string s1,string s2,vector<vector<int> >& mem,int r,int c){
	if(r==0 || c==0) return 0;
	if(mem[r][c]!=-1) return mem[r][c];
	if(s1[r-1]==s2[c-1]){
		mem[r][c] = 1 + lcshelper(s1,s2,mem,r-1,c-1);
	}else{
		mem[r][c] = max(lcshelper(s1,s2,mem,r,c-1) , lcshelper(s1,s2,mem,r-1,c));
	}
	return mem[r][c];
}

int lcs(string s1,string s2){
    int l1 = s1.length(), l2 = s2.length();
    if(!l1||!l2) return 0;
    vector<vector<int> > m(l1+1);
    vector<vector<int> >& mem = m;
    for(int i=0;i<l1+1;i++){ vector<int> v(l2+1); mem[i] = v; }
    for(int i=0;i<l1+1;i++){ for(int j=0;j<l2+1;j++){ mem[i][j] = -1;} }
    for(int i=0;i<l1+1;i++){ mem[i][0] = 0; }
    for(int i=0;i<l2+1;i++){ mem[0][i] = 0; }
    return lcshelper(s1,s2,mem,l1,l2);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s1,s2;
	    int l1,l2; cin >> l1 >> l2; cin >> s1 >> s2;
	    cout << lcs(s1,s2) << endl;
	}
	return 0;
}
