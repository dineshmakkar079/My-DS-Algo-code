/*
Time : Tue Oct 10 2017 01:33:32 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/knight-walk/0
Given a chess board of order NxM and source points (s1,s2) and destination points (d1,d2), Your 
task to find min number of moves required by the Knight to go to the destination cell. 

Input:
The 
first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains two lines. The first line of each test case contains two space separated 
integers N and M. Then in the next line are four space separated values s1, s2 and d1, d2.

Output:
For 
each test case in a new line print the min no of moves required by the knight to go to the destination 
from the source. If no such move is possible print -1.

Constraints:
1<=T<=100
1<=N,M<=25

Example:
Input:
2
4 
7
2 6 2 4
7 13
2 8 3 4
Output:
2
3

** For More Input/Output Examples Use 'Expected Output' option 
**

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

void util(int n,int m,int i,int j,int d1,int d2,int move,int& minmoves,vvi& mem){
    if(i==d1 && j==d2){
        minmoves = min(minmoves, move);
        mem[i][j] = minmoves;
        return;
    }
    cout << i << " " << j << endl;
    if(mem[i][j]!=-1)return;
    mem[i][j]=1;
    if(inrange(i-1,j+2,n,m))util(n,m,i-1,j+2,d1,d2,move+1,minmoves, mem);
    if(inrange(i+1,j+2,n,m))util(n,m,i+1,j+2,d1,d2,move+1,minmoves, mem);
    if(inrange(i-1,j-2,n,m))util(n,m,i-1,j-2,d1,d2,move+1,minmoves, mem);
    if(inrange(i+1,j-2,n,m))util(n,m,i+1,j-2,d1,d2,move+1,minmoves, mem);
    if(inrange(i+2,j+1,n,m))util(n,m,i+2,j+1,d1,d2,move+1,minmoves, mem);
    if(inrange(i+2,j-1,n,m))util(n,m,i+2,j-1,d1,d2,move+1,minmoves, mem);
    if(inrange(i-2,j+1,n,m))util(n,m,i-2,j+1,d1,d2,move+1,minmoves, mem);
    if(inrange(i-2,j-1,n,m))util(n,m,i-2,j-1,d1,d2,move+1,minmoves, mem);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n ,m, s1,s2,d1,d2;
	    cin >> n >> m >> s1 >> s2 >> d1 >> d2;
	    int minm = INT_MAX;
	    int& minmoves = minm;
	    vvi me(n);
	    for(int i=0;i<n;i++){
	        vi v(m,-1); me[i]=v;
	    }
	    vvi& mem = me;
	    util( n, m, s1, s2, d1, d2, 0, minmoves, mem);
	    cout << minmoves << endl;
	}
	return 0;
}