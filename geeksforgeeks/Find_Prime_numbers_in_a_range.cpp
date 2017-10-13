/*
Time : Fri Oct 13 2017 02:02:37 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range/0
Generate all prime numbers between two given numbers.

Input:

The first line of the input contains 
an integer T denoting the number of test cases. Then T test cases follow. Each test case consists 
of a single line containing two space separated integers m and n.
Output:

For every test case print 
all prime numbers p such that m <= p <= n, space separated. Separate the answers for each test case 
by a new line.

Constraints:
1<=T<=60
1 <= m <= n <= 100000,
n - m <= 100000

Example:

Input:

2

1 
10

3 5

Output:

2 3 5 7

3 5

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
	vr<bool> primes(100001,true);
	for(int i=2;i<=4000;i++){
	    if(primes[i]){
	        for(int j=2;j*i<=100000;j++){
	            primes[j*i] = false;
	        }
	    }
	}
	while(t--){
	    int m , n;
	    cin >> m >> n;
	    for(int i=m;i<=n;i++){
            if(primes[i] && i>=2){
                cout << i << " " ;
            }
        }
        cout << endl;
	}
	return 0;
}