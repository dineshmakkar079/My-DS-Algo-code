/*
Time : Thu Oct 12 2017 22:23:57 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/count-substrings/0/?ref=self
Given a binary string, count number of substrings that start and end with 1. For example, if the 
input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

Input:
The 
first line contains T denoting the number of testcases. Then follows description of testcases. 
Each 
case contains a string containing 0's and 1's.
 

Output:
For each test case, output a single line 
denoting number of substrings possible.

Constraints:
1<=T<=100
1<=Lenght of String<=100


Example:
Input:
1
10101

Output:
3

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
	    int n;
	    string s;
	    cin >> s;
	    n = s.length();
	    vi cnt(n);
	    int c = 0;
	    for(int i=n-1;i>=0;i--){
	        cnt[i]=c;
	        c=s[i]=='1'?1+c:c;
	    }
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        ans += s[i]=='1'?cnt[i]:0;
	    }
	    cout << ans << endl;
	}
	return 0;
}