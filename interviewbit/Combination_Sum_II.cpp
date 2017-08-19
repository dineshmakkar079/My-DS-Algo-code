/*
Time : Sat Aug 19 2017 14:18:26 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/combination-sum-ii/#
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations 
in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, 
… , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain 
duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution 
set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING 
COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission 
retroactively and give you penalty points.

*/

#include <bits/stdc++.h>

using namespace std;

void combSumHelper(vector<int> curr,vector<int>& a, int b,int start,int n,int mini,vector<vector<int> >& ans){
    if(b == 0){
        ans.push_back(curr);
        return;
    }
    if(b < mini){
        return;
    }
    for(int i=start;i<n;i++){
        if(b-a[i] >=0 ){
            int prev = ans.size();
            combSumHelper(curr,a,b-a[i],start+1,n,mini,ans);
            int now = ans.size();
            for(int j=prev;j<now;j++){
                ans[j].push_back(a[i]);
            }
        }
    }
    if(start+1<n)
    combSumHelper(curr,a,b,start+1,n,mini,ans);
}

bool checkValid(vector<int> v, map<int,int> m){ // if combination has any number repeated
    // repetition is allowed if number is repeated in input.
    for(int i=0;i<v.size();i++){
        map<int,int>::iterator it;
        it = m.find(v[i]);
        if(it->second==0)
            return false;
        else
            m[v[i]] = it->second - 1;
    }
    return true;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int> > c;
    sort(A.begin(),A.end());
    vector<vector<int> >& ans = c;
    int mini = A[0];
    vector<int> v;
    map<int,int> m;
    map<int,int>::iterator itr;
    for(int i=0;i<n;i++){
        itr = m.find(A[i]);
        if(itr==m.end()){
            m[A[i]] = 1;
        }else{
            m[A[i]] = itr->second +1;
        }
    }
    int start =0;
    combSumHelper(v,A,B,start,n,mini,ans);
    n = ans.size();
    for(int i=0;i<n;i++){ // sort each combination (required for set unique element property)
        sort(ans[i].begin(),ans[i].end());
    }
    if(c.size()==0){ // No combinations found.
        vector< vector<int> > v;return v;
    }
    set<vector<int> > s(ans.begin(),ans.end()); // Get all unique vectors out of all combinations.
    set<vector<int> >::iterator it=s.begin();
    vector<vector<int> > finalans;
    while(it!=s.end()){
        if(checkValid(*it,m)){
            finalans.push_back(*it);
        }
        it++;
    }
    return finalans;
}

int main(){

	return 0;
}
