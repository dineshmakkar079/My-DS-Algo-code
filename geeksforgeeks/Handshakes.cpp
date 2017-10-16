/*
Time : Sat Oct 14 2017 22:15:02 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/handshakes/0
We have N persons sitting on a round table. Any person can do a handshake with any other person.

 
   1
2        3
    4
Handshake with 2-3 and 1-4 will cause cross.

In how many ways these N people 
can make handshakes so that no two handshakes crosses each other. N would be even. 

For example, 
in above diagram, there are two non-crossing ways to handshake {{1, 2}, {3, 4}} and {{1, 3}, {2, 
4}}.

Input:

The first line of input contains an integer T denoting the number of test cases.
The 
first line of each test case is N.

Output:

Print number of ways.

Constraints:

1 ≤ T ≤ 20
2 ≤ 
N ≤ 30

Example:

Input:
2
2
8

Output:
1
14

** For More Input/Output Examples Use 'Expected Output' 
option **

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
	vi mem(17,0); mem[0]=1;mem[1]=1;mem[2]=2;
    for(int i=3;i<=16;i++){
        for(int j=0;j<i;j++){
            mem[i] += (mem[i-j-1]* mem[j]);
        }
    }
	while(t--){
	    int n;
	    cin >> n;
	    cout << mem[n/2] << endl;
	}
	return 0;
}