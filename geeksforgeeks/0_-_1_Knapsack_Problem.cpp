/*
Time : Mon Aug 28 2017 10:09:12 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
You are given weights and values of N items, put these items in a knapsack of capacity W to get 
the maximum total value in the knapsack. Note that we have only one quantity of each item, In other 
words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated 
with N items respectively. Also given an integer W which represents knapsack capacity, find out 
the maximum value subset of val[] such that sum of the weights of this subset is smaller than or 
equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 

Input:

The 
first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each 
test case consists of four lines. The first line consists of N the number of items. The second line 
consists of W, the maximum capacity of the knapsack. In the next  line are N space separated positive 
integers denoting the values of the N items and in the fourth line are N space separated positive 
integers denoting the weights of the corresponding items.
 

Output:

Print the maximum possible 
value you can get with the given conditions that you can obtain for each test case in a new line.
 

Constraints:

1≤T≤100

1≤N≤100

1≤W≤100

1≤wt[i]≤100

1≤v[i]≤100


Example:

Input:
1
3
4
1 
2 3
4 5 1
Output:
3

 

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

int helper(int n,int c,vector<int> val,vector<int> wt,vector<vector<int> >& mem,int i){
    if(n==0||c==0)return 0;
    if(mem[n][c]!=-1) return mem[n][c];
    if(c >= wt[i])
        mem[n][c] = max(mem[n][c] ,max(val[i]+helper(n-1,c-wt[i],val,wt,mem,i+1), helper(n-1,c,val,wt,mem,i+1)));
    else
        mem[n][c] = max(mem[n][c] ,helper(n-1,c,val,wt,mem,i+1));
    return mem[n][c];
}

int zonpsk(int n,int c,vector<int> val, vector<int> wt){
    vector<vector<int> > me(n+1);
    vector<vector<int> >& mem = me;
    for(int i=0;i<n+1;i++){
        vector<int> v(c+1);
        for(int j=0;j<c+1;j++) v[j] = -1;
        mem[i] = v;
    }
    // Base cases
    // 0 items left - no more value can be added to knapsack
    for(int i=0;i<n+1;i++){ mem[i][0] = 0; }
    // 0 capacity remaining - no more value can be added to knapsack.
    for(int i=0;i<c+1;i++){ mem[0][i] = 0; }
    
    return helper(n,c,val,wt,mem,0);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, c;
	    cin >> n >> c;
	    vector<int> val(n), wt(n);
	    for(int i=0;i<n;i++){
            cin >> val[i];
        }
        for(int i=0;i<n;i++){
            cin >> wt[i];
        }
        // zonpsk == zero one knapsack
        cout << zonpsk(n,c,val,wt) << endl;
	}
	return 0;
}