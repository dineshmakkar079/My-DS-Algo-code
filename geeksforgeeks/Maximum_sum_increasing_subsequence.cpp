/*
Time : Mon Aug 28 2017 10:30:59 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence 
of the given array such that the integers in the subsequence are sorted in increasing order.

Input:

The 
first line of input contains an integer T denoting the number of test cases.
The first line of each 
test case is N,N is the size of array.
The second line of each test case contains N input A[].

Output:

Print 
the sum of maximum sum sequence of the given array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ A[] 
≤ 1000

Example:

Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
For input:
7
1 
101 2 3 100 4 5
All the increasing subsequences : (1,101); (1,2,3,100); (1,2,3,4,5), out of this 
(1,2,3,100) has maximum sum,i.e., 106. Hence the output is stated as 106.

**For More Examples Use 
Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

int msis(vector<int>& v){
    int n = v.size();
    if(n==1) return v[0];
    vector<int> mem(n);
    for(int i=0;i<n;i++){ mem[i] = v[i] ;}
    int ans = v[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j] < v[i]){
                // Try extending all previous msis
                mem[i] = max(mem[i], mem[j] + v[i]);
            }
        }
        mem[i] = max(mem[i] , v[i]); // Should msis start from this element only
        ans = max(ans, mem[i]);
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> vec(n);
	    vector<int>& v = vec;
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        // msis - maximum sum increasing subsequence
        cout << msis(v) << endl;
	}
	return 0;
}