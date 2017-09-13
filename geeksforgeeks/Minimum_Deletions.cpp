/*
Time : Fri Sep 08 2017 13:25:29 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/minimum-deletitions/0
Given a string of S as input. Your task is to write a program to remove or delete minimum number 
of characters from the string so that the resultant string is palindrome.

Note: The order of characters 
in the string should be maintained.

Input:
First line of input contains a single integer T which 
denotes the number of test cases. Then T test cases follows. First line of each test case contains 
a string S.

Output:
For each test case, print the deletions required to make the string palindrome.

Constraints:
1<=T<=100
1<=length(S)<=10000

Example:
Input:
2
aebcbda
geeksforgeeks
Output:
2
8

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int j=0;j<n;j++) a[j]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >>s;
	    int l=s.length();
	    vvi m(l); vvi& mem = m;
	    for(int i=0;i<l;i++){
	        vi v(l); init(v,l,-1);
	        v[i] = 1;
	        mem[i] = v;
	    }
	    // sl = substring length
	    // First calculating length of longest palindromic subsequence
	    for(int sl=2;sl<=l;sl++){
	        for(int i=0;i<l-sl+1;i++){
	            int j = i+sl-1;
	            if(j==i+1){
	                mem[i][j] = s[i]==s[j]?2:1;
	            }else{
	                mem[i][j] = s[i]==s[j]?2+mem[i+1][j-1]:max(mem[i+1][j],mem[i][j-1]);
	            }
	        }
	    }
	    cout << l-mem[0][l-1] << endl;
	}
	return 0;
}