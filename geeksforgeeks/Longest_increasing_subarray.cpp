/*
Time : Sun Oct 08 2017 12:54:12 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-increasing-subarray/0
Given an array containing n numbers. The problem is to find the length of the longest contiguous 
subarray such that every element in the subarray is strictly greater than its previous element in 
the same subarray. Time Complexity should be O(n).

Input:
The first line consists of an integer 
T i.e number of test cases. The first line of each test case consists of an integer n. The next 
line contains n spaced integers.

Output:
Print the required output.

Constraints: 
1<=T<=100
1<=n<=100
1<=a[i]<=104

Example:
Input:
2
9
5 
6 3 5 7 8 9 1 2
10
12 13 1 5 4 7 8 10 10 11

Output:
5
4

** For More Input/Output Examples Use 
'Expected Output' option **

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
	    vi v(n),lis(n);
	    int maxi = 1;
	    for(int i=0;i<n;i++){
            cin >> v[i];
            lis[i] = 1;
            if(i > 0)
                lis[i] = v[i]>v[i-1]?lis[i-1]+1:1;
            maxi = max(maxi, lis[i]);
        }
        cout << maxi << endl;
	}
	return 0;
}