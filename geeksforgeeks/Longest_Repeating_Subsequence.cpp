/*
Time : Thu Sep 14 2017 14:13:34 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
Given a string str, find length of the longest repeating subseequence such that the two subsequence 
don’t have same string character at same position, i.e., any i’th character in the two subsequences 
shouldn’t have the same index in the original string.

Input:

The first line of input contains 
an integer T denoting the number of test cases. Then T test cases follow. The first line of each 
test case contains an integer N denoting the length of string str.

The second line of each test 
case contains the string str consisting only of lower case english alphabets.

Output:

Print the 
length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= 
T <=100

1<= N <=1000


Example:

Input:

2

3

abc

5

axxxy

Output:

0

2

** For More Input/Output 
Examples Use 'Expected Output' option **

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
	    cin >> n;
	    string s;
	    cin >> s;
	    int l = s.length();
	    vvi m(l+1); vvi& mem = m;
	    for(int i=0;i<l+1;i++){
	        vi v(l+1); init(v,l+1,0);
	        mem[i] = v;
	    }
	    for(int i=0;i<l+1;i++)mem[i][l]=mem[l][i]=0;
	    for(int i=l-1;i>=0;i--){
	        for(int j=l-1;j>=0;j--){
	            mem[i][j]=s[i]==s[j]&&i!=j?1+mem[i+1][j+1]:max(mem[i+1][j],mem[i][j+1]);
	        }
	    }
	    cout << mem[0][0] << endl;
	    for(int i=0;i<+1;i++)mem[i].clear(); mem.clear();
	}
	return 0;
}