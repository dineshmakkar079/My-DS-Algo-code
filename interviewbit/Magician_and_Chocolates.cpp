/*
Time : Wed Aug 23 2017 21:30:54 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/magician-and-chocolates/
Given N bags, each bag contains Ai chocolates. There is a kid and a magician. In one unit of time, 
kid chooses a random bag i, eats Ai chocolates, then the magician fills the ith bag with floor(Ai/2) 
chocolates.

Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units 
of time.

For example,

K = 3
N = 2
A = 6 5

Return: 14
At t = 1 kid eats 6 chocolates from bag 
0, and the bag gets filled by 3 chocolates
At t = 2 kid eats 5 chocolates from bag 1, and the bag 
gets filled by 2 chocolates
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 
1 chocolate
so, total number of chocolates eaten: 6   5   3 = 14

Note: Return your answer modulo 
10^9 7

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::nchoc(int a, vector<int> &b) {
    int n = b.size();
    priority_queue<int> q;
    for(int i=0;i<n;i++)
        q.push(b[i]);
    int c = a;
    long long ans = 0;
    while(c>0 && !q.empty()){
        int t = q.top();q.pop();
        ans += t;
        ans %= 1000000007;
        if(t/2)
            q.push(t/2);
        c--;
    }
    return ans;
}

int main(){

	return 0;
}
