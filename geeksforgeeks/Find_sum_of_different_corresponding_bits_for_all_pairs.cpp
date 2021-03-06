/*
Time : Wed Oct 18 2017 19:29:27 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs/0
We define f (X, Y) as number of different corresponding bits in binary representation of X and Y. 
For example, f (2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. 
The first and the third bit differ, so f (2, 7) = 2.

You are given an array of N integers, A1, 
A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer 
modulo 109 7.

Input:

The first line of each input consists of the test cases. The description 
of T test cases is as follows:

The first line of each test case contains the size of the array, 
and the second line has the elements of the array.


Output:

In each separate line print sum of all 
pairs for (i, j) such that 1 ≤ i, j ≤ N and return the answer modulo 109 7.


Constraints:

1 ≤ 
T ≤ 70
1 ≤ N ≤ 100
-2,147,483,648 ≤ A[i] ≤ 2,147,483,647


Example:

Input:

2
2
2 4
3
1 3 5

Output:

4
8

Working:

A 
= [1, 3, 5] 

We return

f(1, 1)   f(1, 3)   f(1, 5)  
f(3, 1)   f(3, 3)   f(3, 5)  
f(5, 1)   f(5, 
3)   f(5, 5) =

0   1   1  
1   0   2  
1   2   0 = 8

** For More Input/Output Examples Use 'Expected 
Output' option **

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

int setbits(int n){
    if(!n)return n;
    if(n==1)return n;
    int ans = 0;
    while(n){
        ans++;
        n &= (n-1);
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vl v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        ull ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans += setbits(v[i]^v[j]);
            }
        }
        cout << (2*ans) << endl;
	}
	return 0;
}