/*
Time : Tue Sep 05 2017 13:06:05 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0
Given an array of integers. A subsequence of A[] is called Bitonic if it is first increasing, then 
decreasing.

Examples:

Input : A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9}
Output : 194
Explanation 
: Bi-tonic Sub-sequence are :
             {1, 51, 9} or {1, 50, 100, 18, 9} or
             {1, 
15, 51, 100, 18, 9}  or 
             {1, 15, 45, 100, 12, 9}  or 
             {1, 15, 45, 100, 
18, 9} .. so on            
Maximum sum Bi-tonic sub-sequence is 1   15  
51   100   18   9 = 194 
  

Input : A[] = {80, 60, 30, 40, 20, 10} 
Output : 210  

Input:
The first line contains an integer 
T denoting the no of test cases. Each test case consist of two lines. The first line contains an 
integer N denoting the size of the array. Then in the next line are N space separated values of 
the array A[].


Output:
For each test case in a new line print the max sum bitonic subsequence.

Constraints:
1<=T<=100
1<=N<=50
1<=A[]<=100

Example:
Input:
2
6
80 60 30 40 20 
10
9
1 15 51 45 33 100 12 18 9

Output:
210
194

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
        if(n==1) {
            cout << v[0] << endl; continue;
        }
        vector<int> lis(n),lds(n);
        for(int i=0;i<n;i++){
            lis[i] = v[i]; lds[i] = v[i];
        }
        lis[0] = v[0];
        // lis = length of longest increasing subsequence ending at index i;
        int ans = INT_MIN;
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(v[i] < v[j]){
                    lis[j] = max(lis[j], lis[i] + v[j]);
                }
            }
        }
        lds[n-1] = v[n-1];
        // lds = length of longest decreasing subsequence starting at index i;
        for(int j=n-2;j>=0;j--){
        	for(int i=j+1;i<=n-1;i++){
        		if(v[i] < v[j]){
        			lds[j] = max(lds[j], lds[i] + v[j]);
        		}
        	}
        }
        ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[j] < v[i])
                    ans = max(ans, lis[i] + lds[j]);
            }
        }
        ans= max(ans, max(lis[n-1],lds[0]));
        cout << ans << endl;
	}
	return 0;
}