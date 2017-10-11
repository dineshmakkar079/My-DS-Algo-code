/*
Time : Sun Oct 08 2017 11:08:23 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
Write a program to print all the LEADERS in the array. An element is leader if it is greater than 
all the elements to its right side. The rightmost element is always a leader. 

Input:
The first 
line of input contains an integer T denoting the number of test cases. The description of T test 
cases follows.
The first line of each test case contains a single integer N denoting the size of 
array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements 
of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= A[i]<=100

Example:
Input:
2
6
16 
17 4 3 5 2
5
1 2 3 4 0
Output:
17 5 2
4 0

** For More Input/Output Examples Use 'Expected Output' 
option **

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
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        stack<int> s;
        vi ans(n);
        init(ans,n,-1);
        // Find the next greater element for each element
        for(int i=0;i<n;i++){
            if(s.empty() || v[i] < v[s.top()])
                s.push(i);
            else{
                while(!s.empty() && v[i] >= v[s.top()]){
                    ans[s.top()] = v[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        int a = 0;
        for(int i=0;i<n;i++){
            if(ans[i]==-1)
                cout << v[i] << " ";
        }
        cout << endl;
	}
	return 0;
}