/*
Time : Thu Oct 05 2017 14:31:52 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/generate-binary-numbers/0
Given a number n, Write a program that generates and prints all binary numbers with decimal values 
from 1 to n.

Input:

The first line of input contains an integer T denoting the number of test 
cases.
The first line of each test case is N.

Output:

Print all binary numbers with decimal values 
from 1 to n in a single line.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500

Example:

Input
2
2
5

Output
1 
10
1 10 11 100 101
 

** For More Input/Output Examples Use 'Expected Output' option **

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
	    queue<string> q;
	    if(n==1){
	        cout << "1\n"; continue;
	    }
	    q.push("1");
	    for(int i=1;i<n;){
	        string f = q.front();
	        cout << f << " ";
	        q.pop();
	        q.push(f+"0");i+=1;
	        if(i<n)
	            q.push(f+"1");i+=1;
	    }
	    while(!q.empty()){
	        cout << q.front() << " ";
	        q.pop();
	    }
	    cout << endl;
	}
	return 0;
}