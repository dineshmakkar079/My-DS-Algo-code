/*
Time : Sat Aug 19 2017 14:26:39 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/subsets-ii/
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate 
subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 
2]
]

*/

#include <bits/stdc++.h>

using namespace std;

void subsetHelper(vector<vector<int> >& ans, vector<int>& a, int current,int n){
    if(current == n)
        return;
    int s = ans.size();
    for(int i=0;i<s;i++){
        vector<int> v(ans[i]);
        v.push_back(a[current]);
        ans.push_back(v);
    }
    subsetHelper(ans,a,current+1,n);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    vector<vector<int> > a;
    vector<vector<int> >& ans= a;
    vector<int> v; ans.push_back(v);
    subsetHelper(ans,A,0,n);
    set<vector<int> > s(ans.begin(),ans.end());
    vector< vector<int> > finalans(s.begin(),s.end());
    return finalans;
}

int main(){

	return 0;
}
