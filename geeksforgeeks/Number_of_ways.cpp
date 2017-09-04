/*
Time : Mon Sep 04 2017 19:41:09 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/number-of-ways/0
Given a tile of size 1 x 4, how many ways you can construct a grid of size N x 4.

Input:

The first 
line of input contains an integer T denoting the number of test cases.
The first line of each test 
case is N.

Output:

Print number of possible ways.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 80

Example:

Input:
3
1
4
5

Output:
1
2
3

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<ull> v(n+1);
	    if(n<=3){
	        cout << "1\n"; continue;
	    }
	    if(n==4){
	        cout << "2\n"; continue;
	    }
	    v[1]=1;v[2]=1;v[3]=1;v[4]=2;
	    for(int i=5;i<=n;i++){
            v[i] = v[i-1]+v[i-4];
        }
        cout << v[n] << endl;
	}
	return 0;
}