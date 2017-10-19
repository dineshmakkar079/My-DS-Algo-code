/*
Time : Thu Oct 19 2017 14:06:27 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0
Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis 
substring.

Examples:

Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: 
()()

Input:  ()(()))))
Output: 6
Explanation:  ()(())

Input:
First line contains the test cases 
T.  1<=T<=500
Each test case have one line string S of character'(' and ')' of length  N.  1<=N<=10000

Example:
Input:
2
((()
)()())

Output:
2
4

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
	    cin >> s;
	    int n = s.length();
	    stack<int> st;
	    int maxi = 0;
	    st.push(-1);
	    for(int i=0;i<n;i++){
	        if(s[i]=='('){
	            st.push(i);
	        }else{
	            int tp = st.top(); 
	            st.pop();
	            if(st.empty()){
	                st.push(i);
	            }else{
	                maxi = max(maxi, i - st.top());
	            }
	        }
	    }
	    cout << maxi << endl;
	}
	return 0;
}