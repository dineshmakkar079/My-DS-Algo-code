/*
Time : Mon Aug 21 2017 22:43:43 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that 
each element can appear atmost twice and return the new length.

Do not allocate extra space for 
another array, you must do this in place with constant memory.

Note that even though we want you 
to return the new length, make sure to change the original array as well in place

For example,
Given 
input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int head = 0,parth = 0, partt = 0;
    int count = 0;
    // parth - part head && partt = part tail
    // [ parth ,  partt ] is the raange of array under consideration.
    for(int i=0;i<n;i++){
        count = 0;
        while(parth<n&&partt<n&&A[partt]==A[parth]){
            partt++;
            count++;
        }
        if(count <= 2){
            for(int j=0;j<count;j++){
                A[head++] = A[j+parth];
            }
            parth = partt;
            continue;
        }else{
            A[head] = A[parth];
            A[head+1] = A[parth];
            head += 2;
            while(partt<n && A[parth]==A[partt])
                partt++;
        }
    }
    return head;
}

int main(){

	return 0;
}
