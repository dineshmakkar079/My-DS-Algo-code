/*
Time : Wed Oct 04 2017 21:52:53 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/number-following-a-pattern/0
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm 
to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

Input:
The 
first line of input contains an integer T denoting the number of test cases.
The first line of each 
test case is a string, which contains only I's and D's in capital letter.

Output:
Print the minimum 
number following that pattern.

Constraints:
1 ≤ T ≤ 100
1 ≤ Length of String ≤ 8

Example:
Input
5
D
I
DD
IIDDD
DDIDDIID

Output
21
12
321
126543
321654798

** 
For More Input/Output Examples Use 'Expected Output' option **

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
	    string s;
	    cin>>s;
	    int l=s.length();
	    stack<int> st;
	    string ans="";
	    int maxdig=1;
	    for(int i=0;i<l;i++){
	        if(s[i]=='D'){
	            st.push(maxdig++);
	        }else{
	            st.push(maxdig++);
	            while(!st.empty()){
	                ans+=to_string(st.top());
	                st.pop();
	            }
	        }
	    }
	    st.push(l+1);
	    while(!st.empty()){
	        ans+=to_string(st.top()); st.pop();
	    }
	    cout<<ans<<endl;
	}
	return 0;
}