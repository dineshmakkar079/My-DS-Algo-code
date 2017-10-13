/*
Time : Thu Oct 12 2017 22:15:33 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/greater-on-right-side/0/?ref=self
Given an array of integers, replace every element with the next greatest element (greatest element 
on the right side) in the array. Since there is no element next to the last element, replace it 
with -1.

Input:

The first line of input contains an integer T denoting the number of test cases.
The 
first line of each test case is N,N is the size of array.
The second line of each test case contains 
N input A[i].

Output:

Print the modified array.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ A[i] 
≤ 1000

Example:

Input:
2
6
16 17 4 3 5 2
4
2 3 1 9

Output:
17 5 5 5 2 -1
9 9 9 -1
 

** For More 
Input/Output Examples Use 'Expected Output' option **

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
	    vi v(n),ng(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int maxi = v[n-1]; ng[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            ng[i] = maxi;
            maxi = max(v[i] ,maxi);
        }
        ng[n-1]=-1;
        for(int i=0;i<n;i++){
            cout << ng[i] << " ";
        }cout << endl;
	}
	return 0;
}