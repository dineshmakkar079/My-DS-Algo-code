/*
Time : Sat Oct 07 2017 14:52:49 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/count-number-of-hops/0
Frog steps either 1, 2 or 3 steps to go to top. In how many ways it reaches the top?

Input:

The 
first line of input contains an integer T denoting the number of test cases.
The first line of each 
test case is N. Where is the number of steps it has to hop.

Output:

Print the number of ways.

Constraints:

1 
≤ T ≤ 50
1 ≤ N ≤ 50

Example:

Input:
2
1
5

Output:
1
13

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
	    switch(n){
	        case 1: cout << "1\n"; break;
	        case 2: cout << "2\n"; break;
	        case 3: cout << "4\n"; break;
	        default: {
	            int one=1,two=2,th=4;
	            int ans;
	            for(int i=4;i<=n;i++){
	                ans = one+two+th;
	                one = two;
	                two = th;
	                th = ans;
	            }
	            cout << ans << endl;
	        }
	    }
	}
	return 0;
}