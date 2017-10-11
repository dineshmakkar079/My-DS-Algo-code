/*
Time : Sat Sep 16 2017 02:07:35 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/palindromic-patitioning/0
Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of 
the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of 
“ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. 
For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.

Input:
The 
first line of input contains an integer T, denoting the number of test cases. Then T test cases 
follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test 
case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length 
of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1

** For More Input/Output 
Examples Use 'Expected Output' option **

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
	    cin >>s;
	    int l = s.length();
	    vvi is(l); vvi& isp = is;
	    for(int i=0;i<l;i++){
	        vi ve(l); init(ve,l,-1); isp[i] = ve;
	    }
	    for(int i=0;i<l;i++){isp[i][i]=1;if(i+1<l)isp[i][i+1]=s[i]==s[i+1];}
	    for(int i=l-1;i>=0;i--){
            for(int j=i+1;j<l;j++){
                isp[i][j] = s[i]==s[j] && isp[i+1][j-1];
            }
        }
	    vi mem(l);mem[0]=0;
	    for(int i=1;i<l;i++){
	        if(isp[0][i])mem[i]=0;
	        else{
	            mem[i] = INT_MAX;
	            for(int j=0;j<i;j++){
	                mem[i] = isp[j+1][i]?min(mem[i], 1+mem[j]):mem[i];
	            }
	        }
	    }
	    cout << mem[l-1] << endl;
	    for(int i=0;i<l;i++)isp[i].clear();isp.clear();mem.clear();
	}
	return 0;
}