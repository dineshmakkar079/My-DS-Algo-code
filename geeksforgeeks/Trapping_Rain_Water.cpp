/*
Time : Thu Oct 12 2017 23:21:29 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/trapping-rain-water/0
Given n non-negative integers in array representing an elevation map where the width of each bar 
is 1, compute how much water it is able to trap after raining.
For example:
Input:
3
2 0 2
Output:
2
Structure 
is like below
|  |
|_|
We can trap 2 units of water in the middle gap.

Below is another example.



Input:
The 
first line of input contains an integer T denoting the number of test cases. The description of 
T test cases follows.
Each test case contains an integer N followed by N numbers to be stored in 
array.

Output:
Print trap units of water in the middle gap.

Constraints:
1<=T<=100
3<=N<=100
0<=Arr[i]<10

Example:
Input:
2
4
7 
4 0 9
3
6 9 9

Output:
10
 0
 

** For More Input/Output Examples Use 'Expected Output' option **

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
	    vi v(n),right(n),left(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        for(int i=0;i<n;i++){
            if(i==0)left[i]=v[i];
            else left[i] = max(left[i-1], v[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1)right[i]=v[n-1];
            else right[i]=max(right[i+1], v[i]);
        }
        int ans = 0;
        for(int i=1;i<n-1;i++){
            ans += min(left[i], right[i]) - v[i];
        }
        cout << ans << endl;
	}
	return 0;
}