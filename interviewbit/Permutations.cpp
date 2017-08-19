/*
Time : Sat Aug 19 2017 17:06:26 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/permutations/
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the 
following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries 
in the permutation sequence should be the same.
For the purpose of this problem, assume that all 
the numbers in the collection are unique.
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING 
PERMUTATIONS.
Example : next_permutations in C   / itertools.permutations in python.
If you do, 
we will disqualify your submission retroactively and give you penalty points.

*/

#include <bits/stdc++.h>

using namespace std;

void permuteHelper(vector<int>& a,int index,int end,vector<vector<int> >& ans){
    if(index == end){
        vector<int> c(1); c[0] = a[index];
        ans.push_back(c);
        return;
    }
    int curr = a[index];
    permuteHelper(a,index+1,end,ans); // Get permutations of remaining array excluding 
    int size = ans.size();            // current element
    int lastElLen = ans[0].size();
    for(int i=0;i<lastElLen;i++){   // Put current element one by one at all positions
        vector<int> v(lastElLen+1); // in older permutations
        for(int j=0;j<size;j++){
            for(int k=0;k<i;k++){
                v[k] = ans[j][k];
            }
            v[i] = curr;
            for(int k=i+1;k<lastElLen+1;k++){
                v[k] = ans[j][k-1];
            }
            ans.push_back(v);
        }
        
    }
    for(int i=0;i<size;i++){
        ans[i].push_back(curr);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<vector<int> > a; vector<vector<int> >& ans = a;
    permuteHelper(A,0,A.size()-1,ans);
    sort(a.begin(),a.end());
    return ans;
}

int main(){

	return 0;
}
