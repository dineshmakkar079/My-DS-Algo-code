/*
Time : Fri Oct 06 2017 11:27:31 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0
Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) 
with 0 sum.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an integer n denoting the size of the array. The 
next line contains n space separated integers forming the array.

Output:
Print "Yes" ( without 
quotes) if there exist a subarray of size at least one with sum equal to 0 or else print "No" ( 
without quotes).

Constraints:
1<=T<=100
1<=n<=10^4
-10^5<=a[i]<=10^5

Example:
Input:
2
5
4 2 -3 
1 6
5
4 2 0 1 6

Output:
Yes
Yes

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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi v(n); bool z=false;
	    for(int i=0;i<n;i++){
            cin>>v[i];
            if(!z&&!v[i])z=true;
        }
        if(z){
            cout << "Yes\n";
            continue;
        }else{
            int sum=0;
            map<int,int> m;
            map<int,int>::iterator it;
            for(int i=0;i<n;i++){
                sum += v[i];
                it=m.find(sum);
                if(it!=m.end() || sum==0){
                    cout << "Yes\n"; z=true; i=n;
                }else{
                    m[sum]=1;
                }
            }
            if(!z)
                cout << "No\n";
        }
	}
	return 0;
}