/*
Time : Thu Oct 12 2017 21:59:55 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0
Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, 
j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked 
for the 2 subsequences are different.


Examples:

Input  : abbc
Output : 3
Subsequences are abc, 
abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc


Input:
The 
first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains a string s.

Output:
For each test case in a new line print the required 
output.

Constraints:
1<=T<=100
1<=Length of string <=100

Example:
Input:
2
abbc
abcabc
Output:
3
7

** 
For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    int n = s.length();
	    int ac=0,bc=0,cc=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='a') ac=1+2*ac;
	        else if(s[i]=='b') bc=ac+2*bc;
	        else cc=bc+2*cc;
	    }
	    cout << cc <<endl;
	}
	return 0;
}