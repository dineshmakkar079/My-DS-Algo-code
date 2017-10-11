/*
Time : Thu Sep 14 2017 14:29:23 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/subsets-with-xor-value/0
Given an array arr[] of N integers and a integer K, find the number of subsets of arr[] having XOR 
of elements as K.

Input:

The first line of input contains an integer T denoting the number of 
test cases. Then T test cases follow. Each test case consists of two lines. The first line of each 
test case contains two space separated integers N and K as described in the problem statement. Second 
line of each test case contains N space separated integers denoting the array arr[].

Output:
Corresponding 
to each test case, print a single line containing an integer denoting the total number of subsets 
of arr[] having XOR of thier elements as K.

Constraints:
1<=T<=10
1<=N<=20
1<=K<=100
0<=arr[i]<=100


Example:
Input:
1
4 
6
6 9 4 2

Output:
2

Explanation:
The subsets are {4,2} and {6}

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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    vi v(n); int maxi = INT_MIN;
	    for(int i=0;i<n;i++){
            cin >> v[i]; maxi = max(maxi, v[i]);
        }
        int m = pow(2,(int)log2(maxi)+1)-1;
        vvi mem(n+1);
        for(int i=0;i<n+1;i++){
            vi ve(m+1); init(ve,m+1,0); mem[i] = ve;
        }
        mem[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                mem[i][j] = mem[i-1][j] + mem[i-1][j^v[i-1]];
            }
        }
        cout << mem[n][k] << endl;
        for(int i=0;i<n+1;i++)mem[i].clear();mem.clear();
	}
	return 0;
}