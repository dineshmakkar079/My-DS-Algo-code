/*
Time : Fri Oct 20 2017 17:19:50 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/word-break-part-2/0
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each 
word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict 
= ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           
"snake sand ladder"].

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every 
test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=20.
Second line contains 
N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains 
a string S of length less than 1000.

Output:
Print all possible strings in one line. Each string 
enclosed in ().See Example.
If no string possible print "Empty" (without qoutes).

Note:Make sure 
the strings are sorted in your result.

Exapmle:
Input:
1
5
lr m lrm hcdar wk
hcdarlrm

Output:
(hcdar 
lr m)(hcdar lrm)

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define vs vr<string>
#define ss set<string>
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";
#define pb push_back;
#define sz(a) (a).size()

using namespace std;

void print(ss& dict,string& s,string curr,int index,int end){
    if(index >= end){
        curr = curr.substr(0,curr.length()-1);
        cout << "(" << curr << ")";
        return;
    }
    for(int i=index;i<end;i++){
        string t = s.substr(index, i-index+1);
        ss::iterator it = dict.find(t);
        if(it!=dict.end()){
            print(dict,s,curr + t + " ",i+1,end);
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    ss dict;
	    string s;
	    for(int i=0;i<n;i++){
            cin >> s; dict.insert(s);
        }
        cin >> s;
        print(dict,s,"",0,s.length());
        cout << endl;
	}
	return 0;
}