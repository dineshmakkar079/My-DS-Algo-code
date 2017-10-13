/*
Time : Thu Oct 12 2017 22:37:59 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/three-great-candidates/0/?ref=self
The hiring team of Google aims to find 3 candidates who are great collectively. Each candidate has 
his or her ability expressed as an integer. 3 candidate are great collectively if product of their abilities 
is maximum. Find the maximum collective ability from the given pool of candidates.

Input:
The first 
line of input contains an integer T denoting the number of test cases. Then T test cases follow. First 
line of each test case conatins an interger N  denoting the number of candidates.
The second line 
of each test case contains N space separated elements denoting the ablities of candidates.


Output:
Corresponding 
to each test case, print the desired output(maximum collective ability of three candidates) in a 
newline.


Constraints:
1 ≤ T ≤ 100
3 ≤ N ≤ 1000
-1000 ≤ ability ≤ 1000


Example:
Input
1
6
0 -1 
3 100 70 50

Output:
350000

Explanation
70*50*100 = 350000 which is the maximum possible.

** For 
More Input/Output Examples Use 'Expected Output' option **

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
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        int maxi = v[n-1]*v[n-2]*v[n-3];
        maxi = max( maxi, v[0]*v[1]*v[n-1]);
        cout << maxi << endl;
	}
	return 0;
}