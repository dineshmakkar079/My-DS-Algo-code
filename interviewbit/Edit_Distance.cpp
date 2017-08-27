/*
Time : Mon Aug 28 2017 01:23:17 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/edit-distance/
Given two words A and B, find the minimum number of steps required to convert A to B. (each operation 
is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete 
a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 
1: Replace s with t.
Operation 2: Insert i.

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

int Solution::minDistance(string A, string B) {
    return edistance(A,B);
}

int main(){

	return 0;
}
