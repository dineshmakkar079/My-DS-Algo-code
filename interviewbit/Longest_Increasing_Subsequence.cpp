/*
Time : Sun Aug 27 2017 19:37:14 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/longest-increasing-subsequence/
Find the longest increasing subsequence of a given sequence / array.

In other words, find a subsequence 
of array in which the subsequence’s elements are in strictly increasing order, and in which the 
subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.
In 
this case, we only care about the length of the longest increasing subsequence.

Example :

Input 
: [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output : 6
The sequence : [0, 2, 6, 9, 
13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::lis(const vector<int> &v) {
    int n = v.size();
    if(n==0 || n==1) return n;
    vector<int> lis(n);
    for(int i=0;i<n;i++){
        lis[i] = 1;
    }
    int ans = INT_MIN;
    for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            if(v[i]<v[j]){
                lis[j] = max(lis[j], lis[i] + 1);
            }
        }
        ans = max(ans, lis[j]);
    }
    return ans;
}

int main(){

	return 0;
}
