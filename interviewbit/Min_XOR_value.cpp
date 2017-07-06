/*
Time : Sun Jul 02 2017 23:13:19 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/min-xor-value/
Given an array of N integers, find the pair of integers in the array which have minimum XOR value.
Report the minimum XOR value.

Examples :
Input
0 2 5 7
Output
2 (0 XOR 2)
Input
0 4 7 9
Output

3 (4 XOR 7)

Constraints:
2 <= N <= 100 000
0 <= A[i] <= 1 000 000 000

*/
int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int ans = A[0] ^ A[1];
    int l = A.size();
    for(int i=1;i<l-1;i++){
        ans = min(ans, A[i] ^ A[i+1]);
    }
    return ans;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
