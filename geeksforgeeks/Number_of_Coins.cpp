/*
Time : Tue Aug 29 2017 14:15:39 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/number-of-coins/0
Given a value V, if we want to make change for V cents,
and we have infinite supply of each of C 
= { C1, C2, .. , Cm} valued coins,
what is the minimum number of coins to make the change?

Input:
The 
first line of input contains an integer T denoting the number of test cases.
The first line of each 
test case is V and N,V is the value of cents and N is the number of coins.
The second line of each 
test case contains N input C[i],value of available coins.

Output:
Print the minimum number of coins 
to make the change, if not possible print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ V ≤ 10000
1 ≤ N ≤ 50
1 
≤ C[i] ≤ 100

Example:
Input
1
7 2
2 1

Output
4

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& deno,vector<int>& mem,int amount,int start){
    if(mem[amount]!=INT_MAX) return mem[amount];
    if(amount==0) return 0;
    int n = deno.size();
    if(amount < deno[start]) return INT_MAX;
    for(int i=start;i<n;i++){
        if(deno[i] == amount){
            mem[amount] = 1;
            return 1;
        }
        else if(deno[i] < amount){
            int thisone = helper(deno,mem,amount-deno[i],i);
            if(thisone!=INT_MAX){
                mem[amount] = min(mem[amount], thisone + 1);
            }
        }
    }
    return mem[amount];
}

int change(int amount, vector<int>& denom){
    if(amount == 0)return 0;
    int n = denom.size();
    vector<int> m(amount+1);
    vector<int>& mem = m;
    for(int i=0;i<amount+1;i++){
        mem[i] = INT_MAX;
    }
    mem[0] = 0;
    helper(denom,mem,amount,0);
    return mem[amount]==INT_MAX?-1:mem[amount];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,c;
	    cin >> n >> c;
	    vector<int> vec(c);
	    vector<int>& v = vec;
	    for(int i=0;i<c;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        cout << change(n,vec) << endl;
	}
	return 0;
}