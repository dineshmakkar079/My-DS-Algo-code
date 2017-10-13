/*
Time : Fri Oct 13 2017 00:55:38 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/check-a-integer-is-power-of-3-or-not/0/?ref=self
Given a positive integer, write a function to find if it is a power of three or not.

Input:
First 
line consists of T test cases. Only line of every test case consists of a 32-bit integer N.

Output:
Single 
line output, print "Yes" if integer is a power of 3 else "No"

Constraints:
1<=T<=100
1<=N<=(32-bit 
largest integer)

Example:
Input:
2
3
6
Output:
Yes
No

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

void print(int n){
    stack<int> s;
    for(int i=0;i<31;i++){
        s.push((n >> i)&1);
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    bool found = false;
	    for(int i=0;i<20;i++){
	        if(n == pow(3,i)){
	            cout << "Yes\n";
	            found = true;
	            break;
	        }
	    }
	    if(!found) cout << "No\n";
	}
	return 0;
}