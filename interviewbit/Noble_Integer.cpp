/*
Time : Thu Aug 31 2017 13:33:21 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/noble-integer/
Given an integer array, find if an integer p exists in the array 
such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::solve(vector<int> &v) {
    int n = v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int pre = v[i];i++;
        while(i<n&pre==v[i])i++;
        i--;
        if(v[i]==n-1-i)
            return 1;
    }
	return -1;
}

int main(){

	return 0;
}
