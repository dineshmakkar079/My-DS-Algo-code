/*
Time : Thu Sep 14 2017 21:10:29 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference 
between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total 
number of test cases. In each test cases, the first line contains an integer 'N' denoting the size 
of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements 
of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50


Example:
Input:
2
4
1 
6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 
= {11},       sum of Subset2 = 11

** For More Input/Output Examples Use 'Expected Output' option 
**

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int knpsk(vi& v,vvi& mem,int curr,int cap,int to){
    if(to < 0|| cap<=0) return 0;
    if(mem[to][cap]!=-1)return mem[to][cap];
    if(v[to] > cap){
        mem[to][cap] = knpsk(v,mem,curr,cap,to-1);
    }else{
        mem[to][cap] = max(knpsk(v,mem,curr,cap,to-1),v[to] + knpsk(v,mem,curr+v[to],cap-v[to],to-1));
    }
    return mem[to][cap];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    ull sum = (ull)0;
	    vi v(n); vi& ve=v;
	    for(int i=0;i<n;i++){
            cin >> v[i]; sum+=v[i];
        }
        sort(v.begin(),v.end());
        int hsum = sum/2;
        vvi me(n); vvi& mem = me;
        for(int i=0;i<n;i++){
            vi v(hsum+1); init(v,hsum+1,-1); mem[i]=v;
        }
        for(int i=0;i<n;i++)mem[i][0] = 0;
        int ans = knpsk(ve,mem,0,hsum,n-1);
        cout << abs(abs(sum-ans) - ans) << endl;
	}
	return 0;
}