/*
Time : Sat Oct 14 2017 23:37:19 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-even-length-substring/0
For given string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length 
of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.
 

Input:

The 
first line of input contains an integer T denoting the number of test cases. The description of 
T test cases follows.
Each test case contains a string string of length N.

Output:

Print length 
of the longest substring of length 2k such that sum of left k elements is equal to right k elements 
and if there is no such substring print 0.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input:
2
000000
1234123

Output:
6
4 
 

** For More Input/Output Examples Use 'Expected Output' option **

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
	    string s;
	    cin >> s;
	    n = s.length();
	    vi len(n,0); len[0] = s[0]-'0';
	    for(int i=1;i<n;i++)len[i] = len[i-1]+(s[i]-'0');
	    int maxlen = 0, thislen = 0;
	    for(int i=0;i<n-1;i++){
	        for(int j=i+1;j<n;j++){
	            int st = i==0?0:len[i-1];
	            if((j-i+1)%2==0 && len[(j+i-1)/2]-st==len[j]-len[(j+i-1)/2]){
	                maxlen = max(maxlen, j-i+1);
	            }
	        }
	    }
	    cout << maxlen << endl;
	}
	return 0;
}