/*
Time : Wed Oct 18 2017 20:15:31 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones 
and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
    
   0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle 
created by (0,1), (0,2), (1,1) and (1,2)

*/

#include <bits/stdc++.h>

using namespace std;

int histarea(vector<int>& v){
    int n = v.size();
    vector<int> lefts(n), rights(n);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty() || v[s.top()] <= v[i])
            s.push(i);
        else{
            while(!s.empty() && v[s.top()] > v[i]){
                rights[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        rights[s.top()] = n; s.pop();
    }
    for(int i=n-1;i>=0;i--){
        if(s.empty() || v[s.top()] <= v[i])
            s.push(i);
        else{
            while(!s.empty() && v[s.top()] > v[i]){
                lefts[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        lefts[s.top()] = -1; s.pop();
    }
    int max_area = INT_MIN;
    for(int i=0;i<n;i++){
        max_area = max(max_area, v[i]*( rights[i] - lefts[i]  - 1 ));
    }
    return max_area;
}

int Solution::maximalRectangle(vector<vector<int> > &v) {
    int n = v.size(), m = v[0].size();
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            v[i][j] = v[i][j]?v[i+1][j]+1:0;
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
        ans = max(ans, histarea(v[i]));
    return ans;
}

int main(){

	return 0;
}
