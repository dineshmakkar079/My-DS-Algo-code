/*
Time : Sat Aug 19 2017 11:29:31 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/combinations/
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make 
sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. 
[1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example 
:
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations 
in python.
If you do, we will disqualify your submission retroactively and give you penalty points.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > combineHelper(int current, int n, int k){
    if(k == 1){ // Case for singleton set
        vector<vector<int> >  v(n-current+1);
        for(int i=current;i<=n;i++){
            vector<int> c(1); c[0] = i;
            v[i-current] = c;
        }
        return v;
    }
    if(n-current >= k-1){ // if set of cardinality k-1 can be formed by remaining elements greater than current
        vector<vector<int> > v = combineHelper(current+1,n,k-1);
        for(int i=0;i<v.size();i++){
            v[i].push_back(current);
        } // if set of cardinality k can be formed by remaining elements greater than current
        if(n-current >= k){
            vector<vector<int> > u = combineHelper(current+1,n,k);
            for(int i=0;i<u.size();i++){
                v.push_back(u[i]);
            }
        }
        return v;
    }
    vector<vector<int> > v1; 
    return v1;
}

vector<vector<int> > Solution::combine(int n, int k) {
    if(k>n){
        vector<vector<int> > v1; 
        return v1;
    }
    if(k==n){
        vector<vector<int> > ans; vector<int> v(n);
        for(int i=1;i<=n;i++) v[i-1]=i; ans.push_back(v); return ans;
    }
    vector<vector<int> > v = combineHelper(1,n,k);
    for(int i=0;i<v.size();i++){
        sort(v[i].begin(),v[i].end());
    }
    sort(v.begin(),v.end());
    return v;
}

int main(){

	return 0;
}
