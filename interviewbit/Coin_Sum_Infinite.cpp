/*
Time : Sun Oct 08 2017 15:58:34 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/coin-sum-infinite/
You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount 
of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this 
problem is O(N).

Example :

Input : 
	S = [1, 2, 3] 
	N = 4

Return : 4

Explanation : The 4 possible 
ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}	
Note that the answer can overflow. So, give us the 
answer % 1000007

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::coinchange2(vector<int> &a, int b){
    vector<int> mem(b+1);
    mem[0]=1;
    for(int i=0;i<a.size();i++){
        for(int j=a[i];j<=b;j++){
            mem[j] += mem[j-a[i]];
            mem[j]%=1000007;
        }
    }
    return mem[b];
}

int main(){

	return 0;
}
