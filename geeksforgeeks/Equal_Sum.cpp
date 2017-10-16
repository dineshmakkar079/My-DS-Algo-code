/*
Time : Sun Oct 15 2017 11:27:45 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/equal-sum/0/?ref=self
Given an array A of length N. Determine if there exists an element in the array such that the sum 
of the elements on its left is equal to the sum of
the elements on its right. If there are no elements 
to the left/right, then the sum is considered to be zero. 
Formally, find an i, such that, A1 A2...Ai-1 
=Ai 1 Ai 2...AN.
 

Input:

 The first line contains T, the number of test cases. For each test 
case, the first line contains N, the number of elements in the array A. The
second line for each 
test case contains N space-separated integers, denoting the array A.


Output:

For each test case 
print YES if there exists an element in the array, such that the sum of the elements on its left 
is equal to the sum of the
elements on its right; otherwise print NO in a separate line.


Constraints:

1≤ 
T ≤ 30 
1≤ N ≤100000 
1≤ Ai ≤ 2×10000 
1≤ i ≤N


Example:

Input
1
4
1 2 3 3
Output:
YES

** For 
More Input/Output Examples Use 'Expected Output' option **

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
	    vi v(n); vl mem(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
            mem[i] = i==0?v[i]:v[i]+mem[i-1];
        }
        bool found = false;
        for(int i=0;i<n && !found;i++){
            int left = i==0?0:mem[i-1];
            int right = i==n-1?0:(mem[n-1]-mem[i]);
            if(left==right){
                cout << "YES\n"; found = true;
            }
        }
        if(!found)cout << "NO\n"; 
	}
	return 0;
}