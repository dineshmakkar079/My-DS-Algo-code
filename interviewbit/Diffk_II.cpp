/*
Time : Thu Aug 17 2017 18:17:28 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/diffk-ii/
Given an array A of integers and another non negative integer k, find if there exists 2 indices 
i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 
3 - 1 = 2

Return 0 / 1 for this problem.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::diffPossible(const vector<int> &A, int k) {
    int n = A.size();
    map<int,int> m;
    map<int,int>::iterator it1,it2;
    for(int i=0;i<n;i++){
        it1 = m.find(A[i]+k);
        it2 = m.find(A[i]-k);
        if(it1==m.end() && it2==m.end()){
            m[A[i]] = i;
        }else{
            return 1;
        }
    }
    return 0;
}

int main(){

	return 0;
}
