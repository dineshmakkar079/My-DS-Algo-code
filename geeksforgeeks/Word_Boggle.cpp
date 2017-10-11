/*
Time : Mon Oct 09 2017 14:52:33 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/word-boggle/0
Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one 
character. Find all possible words that can be formed by a sequence of adjacent characters. Note 
that we can move to any of 8 adjacent characters, but a word should not have multiple instances 
of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][] 
  = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output: 
 Following words of dictionary are present
         GEEKS, QUIZ

Input:
The first line of input 
contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains 
an integer x denoting the no of words in the dictionary. Then in the next line are x space separated 
strings denoting the contents of the dictinory. In the next line are two integers N and M denoting 
the size of the boggle. The last line of each test case contains NxM space separated values of the 
boggle.

Output:
For each test case in a new line print the space separated sorted distinct words 
of the dictionary which could be formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS 
FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ

** For More Input/Output Examples Use 'Expected 
Output' option **

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

bool inrange(int i,int j,int n,int m){
    if(i<0||j<0||i>=n||j>=m)return false;
    return true;
}

void dfs(vr<string>& g,int row,int col,int index,string& s,set<string>& found,vvi& vis,int n,int m){
    if(vis[row][col]==1 || index>=s.length() || s[index]!=g[row][col])return;
    vis[row][col]=1;
    if(index==s.length()-1){
        if(g[row][col]==s[index])found.insert(s);
        else return;
    }
    if(inrange(row+1,col,n,m) )dfs(g,row+1,col,index+1,s,found,vis,n,m);
    if(inrange(row+1,col-1,n,m) )dfs(g,row+1,col-1,index+1,s,found,vis,n,m);
    if(inrange(row+1,col+1,n,m) )dfs(g,row+1,col+1,index+1,s,found,vis,n,m);
    if(inrange(row-1,col,n,m) )dfs(g,row-1,col,index+1,s,found,vis,n,m);
    if(inrange(row-1,col-1,n,m) )dfs(g,row-1,col-1,index+1,s,found,vis,n,m);
    if(inrange(row-1,col+1,n,m) )dfs(g,row-1,col+1,index+1,s,found,vis,n,m);
    if(inrange(row,col+1,n,m) )dfs(g,row,col+1,index+1,s,found,vis,n,m);
    if(inrange(row,col-1,n,m) )dfs(g,row,col-1,index+1,s,found,vis,n,m);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int d;
	    cin >> d;
	    vector<string> dict(d);
	    string s;
	    for(int i=0;i<d;i++){
            cin >> dict[i];
        }
        int n,m;
        cin >> n >> m;
        vr<string> gr(n);
        vr<string>& g = gr;
        s = "";
        for(int i=0;i<n;i++){
            s="";
            for(int j=0;j<m;j++){
                char c;
                cin >> c; s+=c;
            }
            g[i]=s;
        }
        string tof;
        string& tofind=tof;
        set<string> fou;
        set<string>& found = fou;
        vvi v(n);
        for(int i=0;i<n;i++){
            vi ve(m,0); v[i]=ve;
        }
        vvi& vis = v;
        for(int i=0;i<d;i++){
            tofind = dict[i];
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++) vis[k][l]=0;
            }
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    if(g[j][k]==tofind[0]){
                        dfs(g,j,k,0,tofind,found,vis,n,m);
                    }
                }
            }
        }
        int f = 0;
        for(auto i=found.begin();i!=found.end();i++){
            cout << *i << " "; f++;
        }
        if(!f)cout << "-1";
        cout << endl;
	}
	return 0;
}