/*
Time : Mon Sep 04 2017 09:56:49 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/max-length-chain/1
You are given N pairs of numbers. In every pair, the first number is always smaller than the second 
number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this 
fashion. Your task is to complete the function maxChainLen which returns an integer denoting the 
longest chain which can be formed from a given set of pairs. 

Input:
The first line of input contains 
an integer T denoting the no of test cases then T test cases follow .Then T test cases follow . 
The first line of input contains an integer N denoting the no of pairs . In the next line are 2*N 
space separated values denoting N pairs.

Output:
For each test case output will be the length of 
the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected 
output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 

Output
3
1
​
Explanation
(i) the 
given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the longest chain that can be 
formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
(ii) The max length chain 
possible is only of length one.


Note:The Input/Ouput format and Example given are used for system's 
internal purpose, and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console. The task is to complete the function 
specified, and not to write the full code.

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/

bool isLessThan(struct val l,struct val r){
    return l.first<r.first;
}

int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,isLessThan);
    int* maxi = new int[n];
    for(int i=0;i<n;i++) maxi[i] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            maxi[i] = p[i].first>p[j].second?max(maxi[i],1+maxi[j]):maxi[i];
        }
    }
    int ret = maxi[n-1];
    delete maxi;
    return ret;
}

int main(){

	return 0;
}
