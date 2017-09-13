/*
Time : Sun Sep 10 2017 15:48:02 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/get-minimum-squares/0
Given a number N. You need to write a program to print the minimum number of squares of this number 
that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5   5*5  
 5*5   5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).

Input:
First 
line of input contains a single integer T, which denotes the number of test cases. Then T test cases 
follows. First line of each test case contains a single integer N.
Output:
For each test case print 
the minimum number of squares that sums to N.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
3
100
6
25
Output:
1
3
1
 

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

int solve(vi& m,int n){
    if(n<=0)return 0;
    if(m[n]!=INT_MAX)return m[n];
    int s = (int)floor(sqrt(n));
    for(int i=1;i<=s;i++){
        m[n] = min(m[n], 1+solve(m,n-i*i));
    }
    return m[n];
}

int main() {
	int t;
	cin >> t;
	vi me(10001); vi& m = me;
	while(t--){
	    int n;
	    cin>>n;
	    if(n<=2){
	        cout << n << endl; continue;
	    }
	    m[0]=0;m[1]=1;m[2]=2;
	    for(int i=3;i<n+1;i++)m[i]=INT_MAX;
	    cout << solve(m,n) << endl;
	}
	return 0;
}