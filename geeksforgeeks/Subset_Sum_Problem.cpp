/*
Time : Wed Sep 06 2017 18:31:14 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/subset-sum-problem/0
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of 
elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting 
the total number of test cases. Each test case constitutes of two lines. First line contains 'N', 
representing the number of elements in the set and the second line contains the elements of the 
set.
Output: Print YES if the given set can be partioned into two subsets such that the sum of elements 
in both subsets is equal, else print NO.
Constraints: 

1 <= T<= 100
1 <= N<= 100
0 <= arr[i]<= 
1000

                   
Example:

Input:
2
4
1 5 11 5
3
1 3 5 

Output:

YES
NO

**For More Examples 
Use Expected Output**

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int i=0;i<n;i++) a[i]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int sub(vi& v,vvi& mem,int start,int sum){
    if(sum<0)return 0;
    if(sum==0){
        return 1;
    }
    if(start==0 && sum!=0){
        mem[start][sum]=0;
        return 0;
    }
    if(mem[start][sum]!=-1)return mem[start][sum];
    mem[start][sum] = sub(v,mem,start-1,sum)||sub(v,mem,start-1,sum-v[start]);
    return mem[start][sum];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,sum=0;
	    cin >> n;
	    vi vec(n);vi& v=vec;
	    for(int i=0;i<n;i++){
            cin>>v[i];sum+=v[i];
        }
        if(sum&1){
            cout << "NO\n"; continue;
        }else{
            vvi m(n+1);vvi& mem=m;
            for(int i=0;i<n+1;i++){
                vi v(sum+1);
                init(v,sum+1,-1);
                v[0] =0;
                mem[i]=v;
            }
            init(mem[0],sum+1,0);
            if(sub(v,mem,n,sum/2)){
                cout << "YES\n";
            }else
                cout << "NO\n";
        }
	}
	return 0;
}