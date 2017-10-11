/*
Time : Sun Oct 08 2017 15:59:11 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/max-product-subarray/
Find the contiguous subarray within an array (containing at least one number) which has the largest 
product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 
3, -2, 4]
Return : 6 

Possible with [2, 3]

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::maxProduct(const vector<int> &v) {
    int l=v.size(),maxo;
    vector<int> maxi(l),mini(l); maxo=v[0]; maxi[0]=mini[0]=v[0];
    for(int i=1;i<l;i++){
        if(v[i]>0){
            maxi[i]=max(v[i],maxi[i-1]*v[i]);
            mini[i]=min(v[i],mini[i-1]*v[i]);
        }else{
            maxi[i]=max(v[i],mini[i-1]*v[i]);
            mini[i]=min(v[i],maxi[i-1]*v[i]);
        }
        maxo=max(maxo,maxi[i]);
    }
    return maxo;
}


int main(){

	return 0;
}
