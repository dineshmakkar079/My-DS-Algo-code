/*
Time : Mon Aug 28 2017 16:04:46 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
Say you have an array for which the ith element is the price of a given stock on day i.

If you 
were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Example :

Input : [1 2]
Return :  1

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::maxProfit(const vector<int> &v) {
    int n = v.size();
    if(n==0||n==1) return 0;
	std::vector<int> great(n);
	great[n-1] = -1;
	int ans = 0;
	int lor = v[n-1]; // lor - largest on right of ith element
	for(int i=n-2;i>=0;i--){
		if(v[i] < lor)
			great[i] = lor;
		else{
			lor = v[i];
			great[i] = -1;
		}
		if(great[i]!=-1)
		    ans = max(ans, (great[i] - v[i]));
	}
	return ans;
}

int main(){

	return 0;
}
