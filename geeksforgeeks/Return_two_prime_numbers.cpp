/*
Time : Fri Oct 13 2017 01:32:07 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/return-two-prime-numbers/0
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given 
number. There are several combinations possible. Print only first such pair. 

NOTE: A solution 
will always exist, read Goldbach’s conjecture.

Also, solve the problem in linear time complexity, 
i.e., O(n).

 

Input:

The first line contains T, the number of test cases. The following T lines 
consist of a number each, for which we'll find two prime numbers.

Note: The number would always 
be an even number.

 
Output:

For every test case print two prime numbers space separated, such 
that the smaller number appears first. Answer for each test case must be in a new line.


Constraints:

1 
≤ T ≤ 70
1 ≤ N ≤ 10000


Example:

Input:

5
74
1024
66 
8
9990

Output:

3 71
3 1021
5 61
3 5
17 
9973

 
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
	vr<bool> primes(10001,true);
	for(int i=2;i<=9999;i++){
	    if(primes[i]){
	        for(int j=2;j*i<=10000;j++){
	            primes[j*i] = false;
	        }
	    }
	}
	while(t--){
	    int n;
	    cin >> n;
	    for(int i=2;i<n/2+1;i++){
            if(primes[i] && primes[n-i]){
                cout << i << " " << n-i << endl;
                break;
            }
        }
	}
	return 0;
}