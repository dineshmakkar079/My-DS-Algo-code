/*
Time : Mon Aug 28 2017 10:58:07 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb 
either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order 
does matter).

Input:
The first line contains an integer 'T' denoting the total number of test cases. 
In each test cases, an integer N will be given.


Output:
Print number of possible ways to reach Nth 
stair. Answer your output % 10^9+7.


Constraints:
1<=T<=1000
1<=N<=100

Example:
Input:
3
4
10
24
Output:
5
89
75025

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    long long one=1,two=2,ans;
        if(n==0){
            cout<< 0 << endl; continue;
        }else if(n==1){ cout << 1 << endl; continue; }
        else if(n==2){cout << 2 << endl ; continue; }
        for (int i = 3; i < n+1; i++){
            ans = (one + two)%mod;
            int temp = ans;
            one = two; two = ans;
        }
        cout << ans <<endl ;
	}
	return 0;
}