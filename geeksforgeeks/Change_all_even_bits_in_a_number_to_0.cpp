/*
Time : Fri Oct 13 2017 00:40:11 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/change-all-even-bits-in-a-number-to-0/0/?ref=self
Given a number, change all bits at even positions to 0.

Example:

Input : 30
Output : 10
Binary 
representation of 11110. 
Bits at Even positions are highlighted. 
After making all of them 0, we 
get 01010
Input:
First line consists of T test cases. Only line, consists of a integer N.

Output:
Single 
line output, print the modified number.

Constraints:
1<=T<=100
1<=N<=(32-bit number)

Example:
Input:
2
30
10
Output:
10
10

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
	int mask = 1;
    for(int i=1;i<31;i+=2){
        mask += pow(2,i);
    }
	while(t--){
	    int n;
	    cin >> n;
	    cout << ((n&mask)&(~0 << 1)) << endl;
	}
	return 0;
}