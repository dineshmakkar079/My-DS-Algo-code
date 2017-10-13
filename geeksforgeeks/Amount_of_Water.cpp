/*
Time : Thu Oct 12 2017 23:24:36 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/amount-of-water/0
An array containing heights of building was given. Its a rainy season. Calculate the amount of water 
collected between all the buildings.

 


Input:

 

The first line of input contains an integer 
T denoting the number of test cases.
The first line of each test case is N,N is the number of buildings.
The 
second line of each test case contains N input H[i],height of buildings.

Output:

Print the amount 
of water collected between all the buildings.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ H[i] ≤ 
1000

Example:

Input
1
6
1 5 3 7 4 2

Output
2

** For More Input/Output Examples Use 'Expected 
Output' option **

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