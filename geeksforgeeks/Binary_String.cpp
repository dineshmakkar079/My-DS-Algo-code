/*
Time : Sun Oct 15 2017 11:32:50 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/binary-string/0/?ref=self
Given a binary string, count number of substrings that start and end with 1. For example, if the 
input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.
 

Input:

The 
first line of input contains an integer T denoting the number of test cases.
Each test case consist 
of an integer 'n' denoting the string length and next line is followed by a binary string .


Output:

Print 
the number of substring starting and ending with 1 in a separate line.

Constraints:

1 ≤ T ≤ 40
1 
≤ |s| ≤ 1000


Example:

Input:
1
4
1111
Output:
6
 

** For More Input/Output Examples Use 'Expected 
Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
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
#define pb push_back;
#define sz(a) (a).size()

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin >> s; 
	    int one = 0;
	    for(int i=0;i<n;i++)if(s[i]=='1')one++;
	    if(one==0||one==1)cout<< "0\n";
	    else cout << (one*(one-1)/2) << endl;
	}
	return 0;
}