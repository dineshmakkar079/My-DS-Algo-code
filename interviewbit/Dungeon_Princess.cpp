/*
Time : Fri Oct 20 2017 17:28:56 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/dungeon-princess/
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially 
positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The 
knight has an initial health point represented by a positive integer. If at any point his health 
point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the 
knight loses health (negative integers) upon entering these rooms; other rooms are either empty 
(0’s) or contain magic orbs that increase the knight’s health (positive integers).

In order to 
reach the princess as quickly as possible, the knight decides to move only rightward or downward 
in each step.

Write a function to determine the knight’s minimum initial health so that he is able 
to rescue the princess.

For example, given the dungeon below, the initial health of the knight 
must be at least 7 if he follows the optimal path

RIGHT-> RIGHT -> DOWN -> DOWN.





Input arguments 
to function:
Your function will get an M*N matrix (2-D array) as input which represents the 2D grid 
as described in the question. Your function should return an integer corresponding to the knight’s 
minimum initial health required. 



 Note:
The knight’s health has no upper bound.
Any room can 
contain threats or power-ups, even the first room the knight enters and the bottom-right room where 
the princess is imprisoned.

*/

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>

int Solution::calculateMinimumHP(vector<vector<int> > &v){
    int n = v.size();
    int m = v[0].size();
    vvi mem(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mem[i][j] = v[i][j];
        }
    }
    mem[n-1][m-1] = v[n-1][m-1]>=0?1:abs(v[n-1][m-1])+1;
    for(int i=n-2;i>=0;i--){
        mem[i][m-1] = max(mem[i+1][m-1] - v[i][m-1],1);
    }
    for(int i=m-2;i>=0;i--){
        mem[n-1][i] = max(mem[n-1][i+1] - v[n-1][i],1);
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            mem[i][j] = max(min(mem[i+1][j], mem[i][j+1]) - v[i][j],1);
        }
    }
    return mem[0][0];
}

int main(){

	return 0;
}
