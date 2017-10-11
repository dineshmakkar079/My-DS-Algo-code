/*
Time : Fri Oct 06 2017 10:55:25 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0
Given an array of integers, find the length of the longest sub-sequence such that elements in the 
subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:

The 
first line of input contains T, number of test cases.

First line of line each test case contains 
a single integer N.

Next line contains N integer array.

Output:

Print the output of each test 
case in a seprate line.

Constraints:

1<=T<=100
1<=N<=100
0<=a[i]<=500

Example:

Input:

2
7
2 
6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:

6
4

** For More Input/Output Examples Use 'Expected Output' 
option **

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
	    vi v(n);
	    int maxi=1;
	    for(int i=0;i<n;i++){
            cin >> v[i];
            maxi = max(maxi, v[i]);
        }
        vi mem(maxi+1);
        for(int i=0;i<maxi+1;i++)mem[i]=0;
        for(int i=0;i<n;i++){
            mem[v[i]]=1;
        }
        int ans = 1;
        for(int i=1;i<=maxi;i++){
            mem[i] = mem[i]==0?0:mem[i-1]+1;
            ans = max(ans,mem[i]);
        }
        cout << ans << endl;
        mem.clear(); v.clear();
	}
	return 0;
}