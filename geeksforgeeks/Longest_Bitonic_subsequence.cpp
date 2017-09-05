/*
Time : Tue Sep 05 2017 12:27:35 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0
Given an array of positive integers. The task is to print the maximum length of Bitonic subsequence. 
a subsequenceof 
array is called Bitonic if it is first increasing, then decreasing.

Input:
First line contains 
T test cases. First line of every test case consists of N , denoting number of elements in an array. 
Second line of every test consists of elements in array.

Output:
Single line output, print the 
longest bitonic sequence.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
1 2 5 3 2
8
1 11 
2 10 4 5 2 1
Output:
5
6

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi; 

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        if(n==0 || n==1) {
            cout << n << endl; continue;
        }
        vector<int> lis(n),lds(n);
        for(int i=0;i<n;i++){
            lis[i] = 1; lds[i] = 1;
        }
        // lis = length of longest increasing subsequence ending at index i;
        int ans = INT_MIN;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(v[i]<v[j]){
                    lis[j] = max(lis[j], lis[i] + 1);
                }
            }
        }
        // lds = length of longest decreasing subsequence starting at index i;
        for(int j=n-2;j>=0;j--){
        	for(int i=j+1;i<=n-1;i++){
        		if(v[i]<v[j]){
        			lds[j] = max(lds[j], lds[i] + 1);
        		}
        	}
        }
        for(int i=0;i<n;i++){
        	ans = max(ans, lis[i] + lds[i] - 1); // -1 to avoid inclusion of element at index i
        }                                           // twice .
        cout << ans << endl;
	}
	return 0;
}