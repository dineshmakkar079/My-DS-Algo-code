/*
Time : Wed Oct 11 2017 11:35:13 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex 
i to a vertex j iff either j = i   1 or j = 3i. The task is to find the minimum number of edges 
in a path in G from vertex 1 to vertex n.

Input:  
The first line of input contains an integer 
T denoting the number of test cases. The description of T test cases follows.

Each test case contains 
a value of n. 

Output:  
Print the number of edges in the shortest path from 1 to n.

Constraints:
1<=T<=30
1<=n 
<=1000

Example:
Input:
2
9
4

Output:
2
2

 

** For More Input/Output Examples Use 'Expected Output' 
option **

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
	    if(n<3){
	        cout << n << endl; continue;
	    }
	    int c = (n%3)?(n%3):0;
	    n -= (n%3);
	    while(n/3){
	        n /= 3; c++;
	        c = (n%3)?(c+n%3):c;
	    }
	    cout << --c << endl;
	}
	return 0;
}
