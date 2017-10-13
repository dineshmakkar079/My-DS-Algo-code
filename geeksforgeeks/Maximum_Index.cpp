/*
Time : Fri Oct 13 2017 02:43:47 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/maximum-index/0/?ref=self
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Example 
:

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

 

Input:

The first line contains an integer 
T, depicting total number of test cases. 
Then following T lines contains an integer N depicting 
the size of array and next line followed by the value of array.


Output:

Print the maximum difference 
of the indexes i and j in a separtate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 
100


Example:

Input
1
2
1 10
Output
1

** For More Input/Output Examples Use 'Expected Output' 
option **

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

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,ts;
	    cin >> n;
	    vr<ii> v(n);
	    for(int i=0;i<n;i++){
            cin >> ts;
            v[i].first = ts;
            v[i].second = i;
        }
        sort(v.begin(),v.end());
        vi right(n);
        right[n-1] = v[n-1].second;
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1], v[i].second);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, right[i] - v[i].second);
        }
        cout << ans << endl;
	}
	return 0;
}