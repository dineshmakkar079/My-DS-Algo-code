/*
Time : Sun Sep 10 2017 13:16:57 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
Say you have an array for which the ith element is the price of a given stock on day i.

Design 
an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, 
buy one and sell one share of the stock multiple times). However, you may not engage in multiple 
transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input 
: [1 2 3]
Return : 2

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::maxProfit(const vector<int> &v) {
    int n = v.size();
    if(n==0||n==1)return 0;
    vector<int> maxp(n);maxp[n-1]=0;int maxi=0;
    maxp[n-2]=v[n-1]>v[n-2]?v[n-1]-v[n-2]:0;maxi=maxp[n-2];
    for(int i=n-3;i>=0;i--){
        int j = i+1;
        if(v[j] > v[i])
            maxp[i] = max( maxp[i], v[j]-v[i] + maxp[j]);
        else
            maxp[i] = maxp[j];
        maxp[i] = max(maxi, maxp[i]);
        maxi = max(maxi, maxp[i]);
    }
    return maxi;
}

int main(){

	return 0;
}
