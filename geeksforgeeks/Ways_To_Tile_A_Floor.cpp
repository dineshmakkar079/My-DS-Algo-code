/*
Time : Mon Sep 04 2017 12:20:50 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor/0
Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, write code to find the number of 
ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically 
i.e as 2 x 1 tile.

Input:

The first line of input contains an integer T denoting the number of 
test cases.
The first line of each test case is W.

Output:

Print number of ways the floor can 
be tiled in a separate line.

Constraints:

1 ≤ T ≤ 50
1 ≤ W ≤ 70

Example:

Input
2
5
3

Output
8
3

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull ways(int n){
    if(n==1||n==2) return n;
    ull prepre = 1, pre = 2;
    ull ans;
    for(int i=3;i<=n;i++){
        ans = pre + prepre;
        prepre = pre;
        pre = ans;
    }
    return ans;
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