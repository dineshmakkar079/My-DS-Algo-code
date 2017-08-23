/*
Time : Wed Aug 23 2017 18:47:36 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/distinct-numbers-in-window/
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct 
numbers in all windows of size K.

Formally, return an array of size N-K 1 where i’th element in 
this array contains number of distinct elements in sequence Ai, Ai 1 ,…, Ai k-1.

Note:
- If K > 
N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 
2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::dNums(vector<int> &a, int b) {
    vector<int> ans;
    int n = a.size();
    if(b > n)return ans;
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0;i<b;i++){
        it = m.find(a[i]);
        if(it==m.end()){
            m[a[i]] = 1;
        }else{
            m[a[i]] = m[a[i]] +1 ;
        }
    }
    // print(m);
    int size = m.size();
    ans.push_back(size);
    int head = 0, tail = b-1;
    while(tail < n-1){
        it = m.find(a[head]);
        if(it->second==1){
            m.erase(it);
            size--;
        }else{
            m[a[head]] = m[a[head]] - 1;
        }
        it = m.find(a[tail+1]);
        if(it==m.end()){
            m[a[tail+1]]=1;
            size++;
        }else{
            m[a[tail+1]] = m[a[tail+1]] + 1;
        }
        ans.push_back(size);
        tail++;head++;
    }
    return ans;
}

int main(){

	return 0;
}
