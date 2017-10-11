/*
Time : Mon Oct 09 2017 00:32:43 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/word-break/0
Given an input string and a dictionary of words, find out if the input string can be segmented into 
a space-separated sequence of dictionary words. See following examples for more details.

Consider 
the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, 
mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: 
Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is 
integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N 
number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. 
Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 
1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile 
ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go 
mango
idontlike
Output:
1
0

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

bool canrep(map<string,bool>& mem,set<string>& dict,string s,int i,int j){
    if(i>=j){
        return true;
    }
    string se(s.begin()+i,s.begin()+j);
    map<string,bool>::iterator it = mem.find(se);
    if(it!=mem.end()){
        return it->second;
    }else if(dict.find(se)!=dict.end()){
        mem[se] = true;
        return true;
    }else{
        for(int k=i+1;k<j;k++){
            if(canrep(mem,dict,s,i,k) && canrep(mem,dict,s,k,j)){
                mem[se] = true;
                return true;
            }
        }
        mem[se] = false;
        return false;
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    set<string> dic;
	    set<string>& dict = dic;
	    string s;
	    for(int i=0;i<n;i++){
            cin >> s;
            dict.insert(s);
        }
        cin >> s;
        string& in = s;
        map<string,bool> m;
        map<string,bool>& mem = m;
        cout << canrep(mem,dict,in,0,in.length()) << endl;
	}
	return 0;
}