/*
Time : Mon Aug 21 2017 19:27:47 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/diffk/
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 
indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 
4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing 
this in less than linear space complexity.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::diffPossible(vector<int> &A, int k) {
    int n = A.size();
    int one = 0, two = 1;
    while(one<n && two<n){
        if(A[two]-A[one]==k && one!=two){
            return 1;
        }else if(A[two]-A[one]==k && one==two){
            two++;
        }else if(A[two]-A[one] < k){
            two++;
        }else{
            one++;
        }
    }
    return 0;
}

int main(){

	return 0;
}
