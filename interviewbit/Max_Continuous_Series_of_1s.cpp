/*
Time : Wed Aug 23 2017 01:02:23 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/max-continuous-series-of-1s/
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number 
of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous 
series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input 
: 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible 
solutions, return the sequence which has the minimum start index.

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::maxone(vector<int> &A, int b) {
    int n = A.size();
    int z=0;
    int head =0, tail =0;
    int maxl=INT_MIN, mh, mt;
    while(tail<n){
        if(z <= b){
            if(A[tail]==0)
                z++;
            tail++;
        }
        if(z > b){
            if(A[head]==0)
                z--;
            head++;
        }
        if(tail - head > maxl){
            maxl = tail-head;
            mh = head; mt = tail;
        }
    }
    vector<int> v;
    for(int i=mh;i<mt && i<n;i++){
        v.push_back(i);
    }
    return v;
}

int main(){

	return 0;
}
