/*
Time : Sun Sep 10 2017 11:27:46 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/#
Say you have an array for which the ith element is the price of a given stock on day i.

Design 
an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may 
not engage in multiple transactions at the same time (ie, you must sell the stock before you buy 
again).

Example :

Input : [1 2 1 2]
Output : 2

Explanation : 
  Day 1 : Buy 
  Day 2 : Sell
 
 Day 3 : Buy
  Day 4 : Sell

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::maxProfit(const vector<int> &v) {
    int n=v.size();
    if(n==0||n==1)return 0;
    vector<int> maxright(n);
    int mr = v[n-1];
    maxright[n-1]=INT_MIN;
    for(int i=n-2;i>=0;i--){
        if(mr > v[i]){
            maxright[i] = mr;
        }else{
            mr = v[i];
            maxright[i] = INT_MIN;
        }
    }
    int ml = v[0];
    vector<int> minleft(n); minleft[0] = INT_MAX;
    for(int i=1;i<n;i++){
        if(ml < v[i]){
            minleft[i] = ml;
        }else{
            ml = v[i];
            minleft[i] = INT_MAX;
        }
    }
    vector<int> maxpftr(n); maxpftr[n-1]=INT_MIN;
    int mp = INT_MIN;
    for(int i=n-2;i>=0;i--){
        if(maxright[i] - v[i] < mp){
            maxpftr[i] = mp;
        }else{
            if(maxright[i]!=INT_MIN)
                mp = maxright[i] - v[i];
            maxpftr[i] = mp;
        }
    }
    vector<int> maxpftl(n); maxpftl[0]=INT_MIN;
    int mpl = INT_MIN;
    for(int i=1;i<n;i++){
        if(v[i]-minleft[i] < mpl){
            maxpftl[i] = mpl;
        }else{
            if(minleft[i]!=INT_MAX)
                mpl = v[i] - minleft[i];
            maxpftl[i] = mpl;
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        int lef = maxpftl[i]==INT_MIN?0:maxpftl[i];
        int rig = maxpftr[i+1]==INT_MIN?0:maxpftr[i+1];if(i==n-1)rig=0;
        ans = max(ans, lef + rig);
    }
    return ans==INT_MIN?0:ans;
}

int main(){

	return 0;
}
