/*
Time : Thu Oct 19 2017 11:57:11 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/coins-in-a-line/
There are N coins (Assume N is even) in a line. Two players take turns to take a coin from one of 
the ends of the line until there are no more coins left. The player with the larger amount of money 
wins. Assume that you go first.

Write a program which computes the maximum amount of money you 
can win.

Example:

suppose that there are 4 coins which have value
1 2 3 4
now you are first so 
you pick 4
then in next term
next person picks 3 then
you pick 2 and
then next person picks 1
so 
total of your money is 4   2 = 6
next/opposite person will get 1   3 = 4
so maximum amount of value 
you can get is 6

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::maxcoin(vector<int> &v) {
    int n = v.size();
    vector<vector<int> > mem(n, vector<int>(n,0));
    for(int gap = 0;gap < n;gap++){
        for(int i=0, j=gap; j<n; ++i, ++j){
            int x = (i+2)<=j ? mem[i+2][j]:0;
            int y = (i+1)<=(j-1)? mem[i+1][j-1]:0;
            int z = i<=(j-2)? mem[i][j-2] : 0;
            mem[i][j]= max(v[i]+ min(x,y), v[j]+min(y,z));
        }
    }
    return mem[0][n-1];
}

int main(){

	return 0;
}
