/*
Time : Sat Oct 21 2017 17:42:19 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/sum-of-query-ii/0/?ref=self
Problem Statement: 

You are given an array and q queries which contains 2 positions in the array 
l and r.

You need to compute the following sum over q queries.

 

Array is 1-Indexed

Input:

The 
first line of input contains T test cases. 

The first line of each test case contains the number 
of elements in the array.

The second line of each test case contains the elements of the array.

The 
third line of each test case contains Q queries.

The final line of each test case contains the 
2 *Q elements where the first element contains l and second element contains r. 

Output:

For each 
test case, print the required sum values in a single line seprated by blank spaces. Print the output 
of each test case in a new line.


Constraints:
 

1 <= T <= 100

1 <= N <= 1000

0 <= Arr[i] <= 
10^6 

1 <= Q <= 1000

1 <= l <= r <= N

 Example:

Input:

1
4
1 2 3 4
2 
1 4 2 3 

Output:

10 
5

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
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
#define pb push_back;
#define sz(a) (a).size()

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi v(n);
	    vr<ull> sum(n+1,0);
	    for(int i=0;i<n;i++){
            cin >> v[i];
            sum[i+1]= v[i]+sum[i];
        }
        sum[n] = v[n-1] + sum[n-1];
        int q;
        cin >> q;
        int l,r;
        while(q--){
            cin >> l >> r;
            cout << sum[r] - sum[l-1] << " ";
        }
        cout << endl;
	}
	return 0;
}