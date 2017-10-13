/*
Time : Thu Oct 12 2017 23:50:35 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/unsorted-array/0/?ref=self
Given an unsorted array of size N. Find the first element in array such that all of its left elements 
are smaller and all right elements to it are greater than it.

Note: Left and right side elements 
can be equal to required element. And extreme elements cannot be required element.

Input:
The first 
line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case consists of two lines. First line of each test case contains an Integer N denoting 
size of array and the second line contains N space separated array elements.

Output:
For each test 
case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1<=T<=100
3<=N<=106
1<=A[i]<=106

Example:
Input:
3
4
4 
2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7

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
	    vi v(n),ns(n),pg(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        // find next smaller element for each a[i]
        stack<int> s;
        int i=0;
        while(i<n){
            if(s.empty() || v[s.top()] <= v[i])
                s.push(i++);
            else{
                while(!s.empty() && v[s.top()] > v[i]){
                    ns[s.top()] = v[i];
                    s.pop();
                }
                s.push(i++);
            }
        }
        while(!s.empty()){
            ns[s.top()] = -1;
            s.pop();
        }
        // find prev greater element for each a[i]
        i = n-1;
        while(i>=0){
            if(s.empty() || v[s.top()] >= v[i])
                s.push(i--);
            else{
                while(!s.empty() && v[s.top()] < v[i]){
                    pg[s.top()] = v[i];
                    s.pop();
                }
                s.push(i--);
            }
        }
        while(!s.empty()){
            pg[s.top()] = -1;
            s.pop();
        }
        
        bool found = false;
        for(int i=1;i<n-1;i++){
            if(pg[i]==-1 && ns[i]==-1){
                cout << v[i] << endl;
                found = true;
                break;
            }
        }
        if(!found) cout << "-1\n";
	}
	return 0;
}