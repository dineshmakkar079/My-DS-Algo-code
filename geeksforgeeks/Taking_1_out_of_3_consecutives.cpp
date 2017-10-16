/*
Time : Sun Oct 15 2017 11:22:50 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/taking-1-out-of-3-consecutives/0
Given an array consisting of N non-negative numbers your task is to find the minimum sum of the 
array such that out of 3 consecutive  elements you need to add at-least one.

Input:
First line 
consists of T Test cases. Each test case contains 2 lines . The first line consists of a number 
N specifying the number of elements in an array and the next line contains N elements.

Output:
Output 
in a single line minimum sum that can be obtained.

Constraints:
1<=T<=100
1<=N<=43

Example:
Input:
2
6
1 
2 3 6 7 1
12
1 2 3 6 7 1 8 6 2 7 7 1
Output:
4
7

Explanation:
For First Test case moving from left 
to right 3 1
For second Test case moving from left to right 3 1 2 1. When 3 is added next 3 consecutive 
elements be 6 7 and 1 and so on.

** For More Input/Output Examples Use 'Expected Output' option 
**

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
	    vi v(n), mem(n);
	    int mini = INT_MAX;
	    for(int i=0;i<n;i++){
            cin >> v[i];
            mini = min(v[i], mini);
        }
        if(n <= 3){
            cout << mini << endl;
            continue;
        }
        mem[0] = v[0]; mem[1]=v[1]; mem[2]=v[2];
        for(int i=3;i<n;i++){
            mem[i] = v[i] + min(min(mem[i-1], mem[i-2]), mem[i-3]);
        }
        int ans = min(min(mem[n-1], mem[n-2]), mem[n-3]);
        cout << ans << endl;
	}
	return 0;
}