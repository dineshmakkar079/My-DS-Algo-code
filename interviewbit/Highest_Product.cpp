/*
Time : Fri Aug 25 2017 13:35:50 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/highest-product/
Given an array of integers, return the highest product possible by multiplying 3 numbers from the 
array

Input:

array of integers e.g {1, 2, 3}
 NOTE: Solution will fit in a 32-bit signed integer 

Example:

[0, -1, 3, 100, 70, 50]

=> 70*50*100 = 350000

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::maxp3(vector<int> &v) {
    int l = v.size();
	priority_queue<int, std::vector<int>, greater<int> > q;
	q.push(v[0]); q.push(v[1]); q.push(v[2]);
	for(int i=3;i<l;i++){
	    int t = q.top();
	    q.pop();
	    if(t < v[i])
	        q.push(v[i]);
	    else
	        q.push(t);
	}
	int one = q.top(); q.pop();
	int two	= q.top(); q.pop();
	int three = q.top(); q.pop();
	
	int maxp = INT_MIN;
	for(int i=0;i<l;i++){ if(v[i]>0) maxp = max(maxp, v[i]); }
	if(maxp < 0) return (one*two*three);
	priority_queue<int> q1;
	int count = 0;
	int endindex = 0;
	for(int i=0;i<l;i++){
	    if(v[i]<0){
	        q1.push(v[i]);
	        count++;
	        endindex=i+1;
	    }
	    if(count == 2)
	        break;  
	}
	if(count < 2)
	    return (one*two*three);
	for(int i=endindex;i<l;i++){
	    int t = q1.top();
	    q1.pop();
	    if(t > v[i])
	        q1.push(v[i]);
	    else
	        q1.push(t);
	}
	if(q1.size()!=2)
	    return (one*two*three);
	int negone = q1.top(); q1.pop();
	int negtwo = q1.top(); q1.pop();
	if(one*two*three < maxp*negone*negtwo)
	    return maxp*negone*negtwo;
	return one*two*three;
}

int main(){

	return 0;
}
