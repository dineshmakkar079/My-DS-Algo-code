/*
Time : Mon Aug 28 2017 01:17:40 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/edit-distance/0
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number 
of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the 
above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the 
input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese 
case consists of two lines. The first line of each test case consists of two space separated integers 
P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test 
case coantains two space separated strings str1 and str2 in order.


Output:
Coreesponding to each 
test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1<=T<=50
1<= 
Length(str1) <= 100
1<= Length(str2) <= 100
 

Example:
Input:
1
4 5
geek gesek

Output:
1

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

int editHelper(string s1,string s2,vector< vector<int> >& mem,int i,int j){
    if(i==0||j==0)return i==0?j:i;
    if(mem[i][j]!=-1)return mem[i][j];
    if(s1[i-1]==s2[j-1]){
        mem[i][j] = editHelper(s1,s2,mem,i-1,j-1);
    }else{
        int one,two,three;
        one = editHelper(s1,s2,mem,i-1,j-1);
        two = editHelper(s1,s2,mem,i,j-1);
        three = editHelper(s1,s2,mem,i-1,j);
        mem[i][j] = 1 + min(one, min(two,three));
    }
    return mem[i][j];
}

int edistance(string s1,string s2){
    int l1=s1.length(), l2 = s2.length();
    if(l1==0)return l2;
    if(l2==0)return l1;
    vector< vector<int> > me(l1+1);
    vector< vector<int> >& mem = me;
    for(int i=0;i<l1+1;i++){
        vector<int> v(l2+1);
        for(int j=0;j<l2+1;j++) v[j] = -1;
        mem[i] = v;
    }
    for(int i=0;i<l1+1;i++){ mem[i][0] = i; } // base case
    for(int i=0;i<l2+1;i++){ mem[0][i] = i; }
    return editHelper(s1,s2,mem,l1,l2);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int l1,l2; cin >> l1 >> l2;
	    string s1,s2; cin >> s1 >> s2;
	    cout << edistance(s1,s2) << endl;
	   // cout << s1 << endl << s2 ;
	}
	return 0;
}