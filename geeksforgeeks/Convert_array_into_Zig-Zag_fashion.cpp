/*
Time : Fri Oct 13 2017 00:06:31 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0/?ref=self
Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) 
time. The converted array should be in form a < b > c < d > e < f.The relative order of elements 
is same in the output i.e you have to iterate on the original array only.

Input:
The first line 
of input contains an integer T denoting the number of test cases. The description of T test cases 
follows.
The first line of each test case contains a single integer N denoting the size of array.
The 
second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print 
the array in Zig-Zag fashion.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
0 ≤A[i]<=10000

Example:
Input:
2
7
4 
3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3

 

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
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        bool inc = true;
        for(int i=0;i<n-1;i++){
            if(inc){
                if(v[i+1] < v[i]) swap(v[i], v[i+1]);
                inc = !inc;
            }else{
                if(v[i+1] > v[i]) swap(v[i], v[i+1]);
                inc = !inc;
            }
        }
        for(int i=0;i<n;i++)
            cout << v[i] << " ";
        cout << endl;
	}
	return 0;
}