/*
Time : Mon Oct 16 2017 16:28:24 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0/?ref=self
Given an input stream of n characters consisting only of small case alphabets the task is to find 
the first non repeating character each time a character is inserted to the stream.

Example

Flow 
in stream : a, a, b, c
a goes to stream : 1st non repeating element a (a)
a goes to stream : no 
non repeating element -1 (5, 15)
b goes to stream : 1st non repeating element is b (a, a, b)
c goes 
to stream : 1st non repeating element is b (a, a, b, c)

Input:
The first line of input contains 
an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an 
integer N denoting the size of the stream. Then in the next line are x characters which are inserted 
to the stream.

Output:
For each test case in a new line print the first non repeating elements 
separated by spaces present in the stream at every instinct when a character is added to the stream, 
if no such element is present print -1.

Constraints:
1<=T<=200
1<=N<=500

Example:
Input:
2
4
a 
a b c
3
a a c 
Output:
a -1 b b
a -1 c
 

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

string first(vi& v,char c,int mp[26],int j){
    if(mp[c-'a']!=0) mp[c-'a']=INT_MAX;
    else mp[c-'a']=j;
    int mini = INT_MAX; string s = "-1";
    for(int i=0;i<26;i++){
        if(mp[i]!=0 && mp[i]!=INT_MAX){
            if(mp[i] < mini){
                mini = mp[i];
                char c = (char)(i + 97);
                s = c;
            }
        }
    }
    return s;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vi v(n);
	    char c;
	    int mp[26]; for(int i=0;i<26;i++)mp[i]=0;
	    for(int i=0;i<n;i++){
            cin >> c;
            v[i] = (int)c;
            if(i==0){
                cout << c << " ";
                mp[c-'a']=1;
            }else{
                cout << first(v,c,mp,i+1) << " ";
            }
        }
        cout << endl;
	}
	return 0;
}