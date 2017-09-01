/*
Time : Thu Aug 31 2017 19:33:55 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/max-distance/
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If 
there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 
4)

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<pair<int,int> > vec(n);
    for(int i=0;i<n;i++){
        pair<int,int> p(A[i],i);
        vec[i] = p;
    }
    sort(vec.begin(),vec.end());
    vector<int> maxIndex(n);
    maxIndex[n-1] = vec[n-1].second;
    int mi = maxIndex[n-1];
    for(int i=n-2;i>=0;i--){
        mi = max(mi, vec[i].second);
        maxIndex[i] = mi;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, maxIndex[i] - vec[i].second);
    }
    if(ans >=0)
        return ans;
    return -1;
}

int main(){

	return 0;
}
