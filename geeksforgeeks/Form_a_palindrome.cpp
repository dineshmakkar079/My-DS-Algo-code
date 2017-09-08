/*
Time : Fri Sep 08 2017 12:57:16 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/form-a-palindrome/0
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For 
Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 
0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains 
an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print 
the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3

 

**For 
More Examples Use Expected Output**

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
#define init(a, n, v) for (int scz=0;scz<n;scz++) a[scz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

int solve(string s, vvi& mem, int start, int end){
    if(end<start){
        return 0;
    }
    if(start==end){
        mem[start][end]=0;return 0; 
    }
    if(mem[start][end]!=-1){
        return mem[start][end];
    }
    if(s[start]==s[end]){
        mem[start][end] = solve(s,mem,start+1,end-1);
    }else{
        mem[start][end] = 1+min(solve(s,mem,start+1,end), solve(s,mem,start,end-1));
    }
    return mem[start][end];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    int l = s.length();
	    vvi m(l); vvi& mem =m;
	    for(int i=0;i<l;i++){
	        vi v(l); init(v,l,-1); mem[i] = v;
	    }
	    for(int i=0;i<l;i++){
	        mem[i][i] = 0;
	    }
	    int ans = solve(s,mem,0,l-1);
	    cout<<ans<< endl;
	}
	return 0;
}