/*
Time : Sun Jul 02 2017 21:03:24 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/single-number-ii/#
Given an array of integers, every element appears thrice except for one which occurs once.

Find
that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could
you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output
: 4

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::singleNumber(const vector<int> &A) {
    vector<int> count(31);vector<int> po(31);
    int l = A.size();
    po[0]= 1;
    for(int i=1;i<31;i++)po[i] = 2*po[i-1];
    for(int i=0;i<31;i++)count[i]=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<31;j++){
			if(A[i] & po[j])
            	count[j] += 1;
        }
    }
    int ans = 0;
    for(int i=0;i<31;i++){
        if(count[i]%3==1)
            ans += po[i];
    }
    return ans;
}
