/*
Time : Sat Aug 26 2017 22:56:04 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/stairs/
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 
1 or 2 steps. In how many distinct ways can you climb to the top?

Example :

Input : 3
Return : 
3

Steps : [1 1 1], [1 2], [2 1]

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::climbStairs(int n) {
    int one=1,two=2,ans;
    if(n==0)return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    for (int i = 3; i < n+1; i++){
        ans = one + two;
        int temp = ans;
        one = two; two = ans;
    }
    return ans;
}

int main(){

	return 0;
}
