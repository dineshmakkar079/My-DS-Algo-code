/*
Time : Tue Sep 05 2017 12:03:17 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one/0
Given an array A of size N, the task is to find the longest subsequence such that difference between 
adjacents is one.

Input:
The first line of input contains an integer T denoting the number of test 
cases. Then T test cases follow. The first line of each test case contains an integer N denoting 
the size of array A.

The second line of each test case contains N space separated integers denoting 
elements of the array A[ ].

Output:
Print the length of the longest subsequence such that difference 
between adjacents is one. Print the answer for each test case in a new line.

Constraints:
1<= T 
<=100
1<= N <=1000
1<= A[ ] <=1000

Example:
Input:
1
7
10 9 4 5 4 8 6
Output:
3

**For More Examples 
Use Expected Output**

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
	    vi a(n),sum(n);
	    for(int i=0;i<n;i++){
            cin >> a[i];
            sum[i]=1;
        }
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(abs(a[i]-a[j])==1)
                    sum[i] = max(sum[i], 1+sum[j]);
            }
            ans = max(ans,sum[i]);
        }
        a.clear(); sum.clear();
        cout << ans << endl;
	}
	return 0;
}