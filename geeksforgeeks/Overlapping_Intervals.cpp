/*
Time : Thu Oct 05 2017 01:48:42 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/overlapping-intervals/0
Given a collection of Intervals,merge all the overlapping Intervals.
For example:

Given [1,3], 
[2,6], [8,10], [15,18],

return [1,6], [8,10], [15,18].

Make sure the returned intervals are sorted.

 

Input:

The 
first line contains an integer T, depicting total number of test cases. 
Then following T lines 
contains an integer N depicting the number of Intervals and next line followed by the intervals 
starting and ending positions 'x' and 'y' respectively.


Output:

Print the intervals after overlapping 
in sorted manner.  There should be a newline at the end of output of every test case.

Constraints:

1 
≤ T ≤ 50
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 100


Example:

Input
2
4
1 3 2 4 6 8 9 10
4
6 8 1 9 2 4 4 7

Output
1 
4 6 8 9 10
1 9

** For More Input/Output Examples Use 'Expected Output' option **

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
	    vr<ip> v(n);
	    for(int i=0;i<n;i++){
	        cin >> v[i].first >> v[i].second;
	    }
	    sort(v.begin(),v.end());
	    stack<ip> s;
	    s.push(v[0]);
	    for(int i=1;i<n;i++){
	        ip p = v[i];
	        ip tp = s.top();
	        if(tp.first > p.second || p.first > tp.second){
	            s.push(p);
	        }else{
	            s.pop();
	            tp.first = min(tp.first,p.first);
	            tp.second = max(tp.second,p.second);
	            s.push(tp);
	        }
	    }
	    vr<ip> ans;
	    while(!s.empty()){
	        ans.push_back(s.top()); s.pop();
	    }
	    int l = ans.size();
	    for(int i=l-1;i>=0;i--){
	        cout << ans[i].first << " " << ans[i].second << " ";
	    }
	    cout << endl;
	}
	return 0;
}