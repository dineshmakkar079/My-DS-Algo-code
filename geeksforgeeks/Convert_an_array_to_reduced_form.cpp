/*
Time : Fri Oct 06 2017 22:28:41 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/convert-an-array-to-reduced-form/0
Given an array with n distinct elements, convert the given array to a reduced form where all elements 
are in range from 0 to n-1. The order of elements is same, i.e., 0 is placed in place of smallest 
element, 1 is placed for second smallest element, … n-1 is placed for largest element.

Input:

The 
first line of input contains an integer T denoting the number of test cases.
The first line of each 
test case is N, where N is the size of array.
The second line of each test case contains N input 
arr[i].

Output:

Print the reduced form of the array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 
≤ arr[i] ≤ 1000

Example:

Input:
2
3
10 40 20
5
5 10 40 30 20

Output:
0 2 1
0 1 4 3 2

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
	    vi v(n),sv(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
            sv[i]=v[i];
        }
        sort(sv.begin(),sv.end());
        map<int,int> m;
        map<int,int>::iterator it;
        for(int i=0;i<n;i++){
            it=m.find(sv[i]);
            if(it==m.end()){
                m[sv[i]]=i;
            }
        }
        for(int i=0;i<n;i++){
            cout << m[v[i]] << " ";
        }
        cout << endl;
	}
	return 0;
}