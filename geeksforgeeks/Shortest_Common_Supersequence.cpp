/*
Time : Sun Sep 10 2017 14:35:44 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
Given two strings str1 and str2, find the shortest common shortest common subsequence of the two 
strings.

Input:
The first line of input contains an integer T denoting the number of test cases.Each 
test case contains two space separated strings.

Output:
Output the length of the shortest common 
supersequence.

Constraints:
1<=T<=100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6

** For 
More Input/Output Examples Use 'Expected Output' option **

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
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s1,s2;
	    cin >>s1>>s2;
	    int l1,l2;
	    l1=s1.length();l2=s2.length();
	    vvi mem(l1+1);
	    for(int i=0;i<l1+1;i++){
	        vi v(l2+1); mem[i]=v;
	        mem[i][0]=i;
	    }
	    for(int i=0;i<l2+1;i++)mem[0][i]=i;
	    for(int i=1;i<l1+1;i++){
	        for(int j=1;j<l2+1;j++){
	            if(s1[i-1]==s2[j-1])
	                mem[i][j]=1+mem[i-1][j-1];
	            else
	                mem[i][j]=1+min(mem[i][j-1],mem[i-1][j]);
	        }
	    }
	    cout << mem[l1][l2] << endl;
	    for(int i=0;i<l1+1;i++)mem[i].clear();mem.clear();
	}
	return 0;
}