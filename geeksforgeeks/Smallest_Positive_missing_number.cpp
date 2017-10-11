/*
Time : Sun Oct 08 2017 10:58:57 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0
You are given an unsorted array with both positive and negative elements. You have to find the smallest 
positive number missing from the array in O(n) time using constant extra space.

Input:
First line 
consists of T test cases. First line of every test case consists of N, denoting the number of elements 
in array. Second line of every test case consists of elements in array.

Output:
Single line output, 
print the smallest positive number missing.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
1 
2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

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
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
            v[i] = v[i]<0 ? 0 :v[i];
            v[i] = v[i]>n ? 0 :v[i];
        }
        if(n==1){
            if(v[0]==1)cout << "2\n";
            else cout << "1\n";
            continue;
        }
        for(int i=0;i<n;i++){
            v[v[i]%(n)] += n;
        }
        bool d=false;
        for(int i=0;i<n;i++){
            if(v[i]<n){
                cout << i << endl;
                d=true;
                break;
            }
        }
        if(!d)cout << n+1 << endl;
	}
	return 0;
}