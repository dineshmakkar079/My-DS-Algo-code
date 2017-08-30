/*
Time : Tue Aug 29 2017 11:32:22 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
Count number of binary strings without consecutive 1’s

Problem Description:
Given a positive integer 
N, count all possible distinct binary strings of length N such that there 
are no consecutive 1’s. 
Output your answer mod 10^9   7.

Input:
The first line of input contains an integer T denoting 
the number of test cases. The description of T test cases follows.
Each test case contain an integer 
N representing length of the binary string.

Output:
Print the count number of binary strings without 
consecutive 1’s of length N.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
3
2

Output:
5
3

Explaination:
For 
first test case 5 strings are (000, 001, 010, 100, 101)
For second test case 3 strings are (00,01,10)

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int ways(int n){
    if(n==1) return 2;
    if(n==2) return 3;
    // base case nwzae - num with zero at end = 1 nwoae - num with one at end
    int nwzae = 1, nwoae = 1;
    int ans = 0;
    for(int i=2;i<=n;i++){
        ans = ((2*nwzae)%mod + nwoae%mod)%mod;
        int newnwzae = (nwzae%mod + nwoae%mod)%mod;
        int newnwoae = nwzae%mod;
        nwzae = newnwzae;
        nwoae = newnwoae;
    }
    return ans%mod;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
        cout << ways(n) << endl;
	}
	return 0;
}