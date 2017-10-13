/*
Time : Thu Oct 12 2017 22:19:26 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/finding-position/0/?ref=self
Some people are standing in a queue. A selection process follows a rule where people standing on 
even positions are selected. Of the selected people a queue is formed and again out of these only people 
on even position are selected. This continues until we are left with one person. Find out the position 
of that person in the original queue.

Input:

The first line of input contains an integer T denoting 
the number of test cases.
The first line of each test case is N,number of people standing in a queue.

Output:

Print 
the position(original queue) of that person who is left.

Constraints:

1 ≤ T ≤ 1000
1 ≤ N ≤ 100000000

Example:

Input
1
5

Output
4

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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int ans = 1;
	    while(ans*2 < n){
	        ans = ans*2;
	    }
	    cout << ans << endl;
	}
	return 0;
}