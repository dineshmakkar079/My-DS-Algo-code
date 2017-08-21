/*
Time : Mon Aug 21 2017 19:01:40 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/minimize-the-absolute-difference/
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute 
difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs 
arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : 
[ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum 
difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> *maxv = NULL;
    int i=A.size()-1,j=B.size()-1,k=C.size()-1;
    int *maxi = NULL;
    int one,two,three,ans=INT_MAX,ma,mi;
    while(i>=0 && j>=0 && k>=0){
        one = A[i]; two= B[j]; three = C[k];
        ma = max(one, max(two,three));
        mi = min(one, min(two,three));
        if(ma==one){
            while(i>=0&&A[i]==max(A[i], max(B[j],C[k]))){
                ans = min(ans,abs(max(A[i], max(B[j],C[k]))-min(A[i], min(B[j],C[k]))));
                i--;
            }
        }else if(ma==two){
            while(j>=0&&B[j]==max(A[i], max(B[j],C[k]))){
                ans = min(ans,abs(max(A[i], max(B[j],C[k]))-min(A[i], min(B[j],C[k]))));
                j--;
            }
        }else{
            while(k>=0&&C[k]==max(A[i], max(B[j],C[k]))){
                ans = min(ans,abs(max(A[i], max(B[j],C[k]))-min(A[i], min(B[j],C[k]))));
                k--;
            }
        }
    }
    return ans;
}

int main(){

	return 0;
}
