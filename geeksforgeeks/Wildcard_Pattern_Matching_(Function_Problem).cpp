/*
Time : Thu Oct 19 2017 17:21:08 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
Given a text 'str' and a wildcard pattern 'pattern',your task is to complete the function wildcard that 
returns '1' if the  wildcard pattern is matched with text else returns '0'.The function takes two 
strings as arguments 'str' and 'pattern'.

The wildcard pattern can include the characters ‘?’ and 
‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty 
sequence)

For example,

Text = "baaabab",
Pattern = “*****ba*****ab", output : true
Pattern = "baaa?ab", 
output : true
Pattern = "ba*a?", output : true
Pattern = "a*ab", output : false 

Note: The matching 
should cover the entire text (not partial text).

Input
The first line of input will contain no 
of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of 
each test case represent a string pat denoting the pattern and the next line contains string str 
.

Output
Output will be 1 if the string follows the pattern else it will be 0.

Constraints:
1<=T<=50
1<=length 
of(str,pat) <=50

Example
Input
2
a*a
aa
a?a
aa

Output
1
0

** For More Input/Output Examples Use 
'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

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

int wildCard(string pat,string str){
    int p = pat.length();
    int s = str.length();
    vvi mem(s+1, vi(p+1,0));
    mem[0][0]=1;
    for(int i=1;i<p+1;i++){
        if(pat[i-1]=='*')
            mem[0][i] = mem[0][i-1]; 
    }
    for(int i=1;i<s+1;i++){
        for(int j=1;j<p+1;j++){
            if(pat[j-1]==str[i-1] || pat[j-1]=='?'){
                mem[i][j] = mem[i-1][j-1];
            }else if(pat[j-1]=='*'){
                mem[i][j] = mem[i][j-1] || mem[i-1][j];
            }else{
                mem[i][j] = 0;
            }
        }
    }
    return mem[s][p];
}

int main(){

	return 0;
}
