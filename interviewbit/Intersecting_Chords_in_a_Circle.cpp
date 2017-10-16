/*
Time : Sat Oct 14 2017 22:24:55 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/
Given a number N, return number of ways you can draw N chords in a circle with 2*N points such that 
no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way 
and not in other.

For example,

N=2
If points are numbered 1 to 4 in clockwise direction, then 
different ways to draw chords are:
{(1-2), (3-4)} and {(1-4), (2-3)}

So, we return 2.
Notes:

1 ≤ N ≤ 1000
Return answer modulo 109 7.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::chordCnt(int A){
    vector<unsigned long long> mem(A+1,0); mem[0]=1;mem[1]=1;mem[2]=2;
    for(int i=3;i<=A;i++){
        for(int j=0;j<i;j++){
            unsigned long long t = mem[i-j-1]* mem[j];
            mem[i] += t%1000000007;
            mem[i] %= 1000000007;
        }
    }
    return mem[A]%1000000007;
}

int main(){

	return 0;
}
