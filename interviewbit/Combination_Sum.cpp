/*
Time : Sat Aug 19 2017 12:27:34 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/combination-sum/
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C 
where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited 
number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a 
combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations 
themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = 
b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai 1 > bi 1)
The solution set must not 
contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set 
is:

[2, 2, 3]
[7]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : 
itertools.combinations in python.
If you do, we will disqualify your submission retroactively and 
give you penalty points.

*/

#include <bits/stdc++.h>

using namespace std;

void combSumHelper(vector<int> curr,vector<int>& a, int b,int n,int mini,vector<vector<int> >& ans){
    if(b == 0){
        ans.push_back(curr);
        return;
    }
    if(b < mini){
        return;
    }
    for(int i=0;i<n;i++){
        if(b-a[i] >=0 ){
            int prev = ans.size();
            combSumHelper(curr,a,b-a[i],n,mini,ans);
            int now = ans.size();
            for(int j=prev;j<now;j++){
                ans[j].push_back(a[i]);
            }
        }
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n = A.size();
    int mini = INT_MAX, maxi = INT_MIN;
    vector<vector<int> > c;
    vector<vector<int> >& ans = c;
    for(int i=0;i<n;i++){
        mini = min(A[i],mini);
    }
    vector<int> v;
    combSumHelper(v,A,B,n,mini,ans);
    n = ans.size();
    for(int i=0;i<n;i++){ // sort each combination (required for set unique element property)
        sort(ans[i].begin(),ans[i].end());
    }
    if(c.size()==0){ // No combinations found.
        vector< vector<int> > v;return v;
    }
    set<vector<int> > s(ans.begin(),ans.end()); // Get all unique vectors out of all combinations.
    vector<vector<int> > finalans(s.begin(),s.end()); 
    return finalans;
}

int main(){

	return 0;
}
