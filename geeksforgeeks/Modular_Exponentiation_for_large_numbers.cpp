/*
Time : Sat Oct 21 2017 17:31:00 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers/0
Implement pow(A, B) % C.

In other words, given A, B and C, find (AB)%C.

 

Input:

The first line 
of input consists number of the test cases.

 The following T lines consist of 3 numbers each separated 
by a space and in the following order:

A B C

'A' being the base number, 'B' the exponent (power 
to the base number) and 'C' the modular.

 

Output:

In each separate line print the modular exponent 
of the given numbers in the test case.


Constraints:

1 ≤ T ≤ 70

1 ≤ A ≤ 10^5

1 ≤ B ≤ 10^5

1 
≤ C ≤ 10^5


Example:

Input:

3
3 2 4
10 9 6
450 768 517

Output:

1
4
34

** For More Input/Output 
Examples Use 'Expected Output' option **

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

ull powe(int a,int b,int c){
    if(b==0 || a==1)return 1;
    if(b==1)return a%c;
    ull one = powe(a,b/2,c);
    ull ans = (b%2)?( ( (one*a)%c * one)%c )%c:(one*one)%c;
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int a,b,c;
	    cin >> a >> b >> c;
	    cout << powe(a,b,c) << endl;
	}
	return 0;
}