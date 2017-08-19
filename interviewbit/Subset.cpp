/*
Time : Sat Aug 19 2017 10:03:59 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/subset/
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must 
be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets 
should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example 
:

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 
3],
  [3],
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

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    vector<vector<int> > a;
    vector<vector<int> >& ans= a;
    vector<int> v; ans.push_back(v);
    subsetHelper(ans,A,0,n);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){

	return 0;
}
