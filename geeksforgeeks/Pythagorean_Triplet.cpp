/*
Time : Thu Oct 12 2017 23:36:45 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/pythagorean-triplet/0/?ref=self
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that 
satisfies a2   b2 = c2.

Input:
The first line contains 'T' denoting the number of testcases. Then 
follows description of testcases.
Each case begins with a single positive integer N denoting the 
size of array.
The second line contains the N space separated positive integers denoting the elements 
of array A.

Output:
For each testcase, print "Yes" or  "No" whtether it is Pythagorean Triplet or 
not.

Constraints:
1<=T<=50
 1<=N<=100
 1<=A[i]<=100

Example:
Input:
1
5
3 2 4 6 5
Output:
Yes

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
	    int ts;
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> ts;
            v[i] = ts*ts;
        }
        set<int> s(v.begin(),v.end());
        bool found = false;
        int i=0,j=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j && s.find(v[i]+v[j]) != s.end()){
                    cout << "Yes\n"; i=n+1; j=n+1; found = true;
                }
            }
        }
        if(!found)cout << "No\n";
	}
	return 0;
}