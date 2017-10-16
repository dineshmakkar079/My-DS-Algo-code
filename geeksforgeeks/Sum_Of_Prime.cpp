/*
Time : Sun Oct 15 2017 11:48:16 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/sum-of-prime/0/?ref=self
Given a number ( greater than 2 ), Print two prime numbers whose sum will be equal to given number, 
else print -1 if no such number exists.

NOTE: A solution will always exist if the number is even. 
Read Goldbach’s conjecture.

If [a, b] is one solution with a <= b,
and [c,d] is another solution 
with c <= d, and a < c then print [a, b] only and not all possible solutions.

 

Input:

The first 
line contains an integer T, depicting total number of test cases. Then following T lines contains 
an integer N.


Output:

Print the two prime numbers in a single line with space in between.


Constraints:

1 
≤ T ≤ 50
1 ≤ N ≤ 1000000


Example:

Input
2
8
3
Output
3 5
-1

** For More Input/Output Examples 
Use 'Expected Output' option **

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
	vr<bool> isp(1000001,true); isp[0]=isp[1]=false;
	int pri = 0;
	for(int i=2;i<ceil(sqrt(1000001));i++){
	    if(isp[i]){
	        for(int j=2;j*i < 1000001; j++)
	            isp[i*j] = false;
	    }
	}
	for(int i=2;i<1000001;i++)pri += isp[i]?1:0;
	vi primes(pri);
	int p = 0;
	for(int i=2;i<1000001;i++)if(isp[i])primes[p++]=i;
	while(t--){
	    int n;
	    cin >> n;
	    bool found = false;
	    int i=0;
	    while(primes[i] < n && !found){
	        if(binary_search(primes.begin(),primes.end(), n-primes[i])){
	            cout << primes[i] << " " << (n - primes[i]) << endl;
	            found = true;
	        }
	        i++;
	    }
	    if(!found)
	        cout << "-1\n";
	}
	return 0;
}