/*
Time : Mon Aug 21 2017 22:48:35 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/sort-by-color/
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same 
color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 
0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort 
function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 
0 1 1 2 2]

*/

#include <bits/stdc++.h>

using namespace std;

void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int z=0,o=0,t=0;
    for(int i=0;i<n;i++){
        switch(A[i]){
            case 0 : z++; break;
            case 1 : o++; break;
            case 2 : t++; break;
        }
    }
    for(int i=0;i<z;i++){
        A[i] = 0;
    }
    for(int i=z;i<z+o;i++){
        A[i] = 1;
    }
    for(int i=z+o;i<n;i++){
        A[i] = 2;
    }
}

int main(){

	return 0;
}
