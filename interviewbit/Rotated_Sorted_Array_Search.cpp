/*
Time : Thu Jul 06 2017 10:47:45 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/rotated-sorted-array-search/
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 
 might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return 
its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 
6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does 
your current solution work? How does the time complexity change?*

*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int> A, int B) {
    int shift,low,high,mid;
    if(A[0]<A[A.size()-1])
        shift = 0;
    else{
        low = 0,high = A.size()-1;
        mid = (low+high)/2;
        while(low<high){
            if(A[mid] > A[mid+1]){
                shift = mid+1;
                break;
            }
            if(A[mid] < A[low])
                high = mid;
            else
                low = mid;
            mid = (low+high)/2;
        }
    }
    int flow = 0, fhigh = shift-1, slow = shift, shigh = A.size()-1;
    int fmid = (flow + fhigh)/2, smid = (slow + shigh)/2;
    while(flow <= fhigh){
        if(A[fmid] == B)
            return fmid;
        else if(A[fmid] > B)
            fhigh = fmid-1;
        else
            flow = fmid+1;
        fmid = (flow+fhigh)/2;
    }
    while(slow <= shigh){
        if(A[smid]==B)
            return smid;
        else if(A[smid] > B)
            shigh = smid-1;
        else
            slow = smid+1;
        smid = (slow+shigh)/2;
    }
    return -1;
}


int main(){
	std::vector<int> v(5);
	v[0]=8; 
	v[1]=9;
	v[2]=10;
	v[3]=11;
	v[4]=12;
	for(int i=0;i<5;i++){
		cout << search(v,v[i]) << endl;
	}
	return 0;
}
