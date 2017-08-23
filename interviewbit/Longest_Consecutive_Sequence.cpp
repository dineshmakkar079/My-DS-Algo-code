/*
Time : Wed Aug 23 2017 16:53:49 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/longest-consecutive-sequence/
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 

Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return 
its length: 4.

Your algorithm should run in O(n) complexity.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::longestConsecutive(const vector<int> &A) {
    int n = A.size();
    if(n==1) return 1;
    map<int,int> m;
    map<int,int>::iterator it,it2;
    for(int i=0;i<n;i++){
        it = m.find(A[i]);
        if(it==m.end()){
            m[A[i]]=1;
        }else{
            (it->second)++;
        }
    }
    int start = 0,end = 0, ans = 1;
    it2 = m.begin(); it2++;
    for(it=m.begin();it2!=m.end();it++, it2++){
        if(it2->first - it->first == 1){
            end++;
            ans = max(ans, end-start+1);
        }else{
            start = end;
        }
    }
    return ans;
}

int main(){

	return 0;
}
