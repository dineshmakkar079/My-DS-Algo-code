/*
Time : Sun Oct 08 2017 16:04:57 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/coin-change/0
Given a value N, find the number of ways to make change for N cents, if we have infinite supply 
of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, 
for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should 
be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, 
{2,3,5} and {5,5}. So the output should be 5.

Input:

The first line contains an integer 'T' denoting 
the total number of test cases. In each test cases, the first line contains an integer 'M' denoting 
the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting 
the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:

Print 
number of possible ways to make change for N cents.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 1 ≤ 
A[i] ≤ 300

Example:

Input:

2
3
1 2 3
4
4
2 5 3 6
10

Output:

4
5

** For More Input/Output Examples 
Use 'Expected Output' option **

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

int coinchange2(vector<int> &a, int b){
    vector<int> mem(b+1);
    mem[0]=1;
    for(int i=0;i<a.size();i++){
        for(int j=a[i];j<=b;j++){
            mem[j] += mem[j-a[i]];
            // mem[j]%=1000007;
        }
    }
    return mem[b];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi ve(n); vi& v = ve;
	    for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int b;
        cin >> b;
        cout << coinchange2(v,b) << endl;
	}
	return 0;
}