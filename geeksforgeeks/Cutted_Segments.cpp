/*
Time : Mon Sep 04 2017 09:20:57 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/cutted-segments/0
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a 
way that the cut length of a line segment each time is integer either x , y or z. and after performing all 
cutting operation the total number of cutted segments must be maximum. 


Input
first line of input 
contains of an integer 'T' denoting number of test cases
first line of each testcase contains N 
.
second line of each testcase contains 3 space separated integers x , y and z.

Output
For each 
test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 
1 1
5
5 3 2


Output
4
2

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

int solve(std::vector<int> v,int n){
	std::vector<int> maxi(n+1);
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
	    maxi[i] = 0;
	}
	maxi[0] = 0;
	int i=1;
	while(i<v[0] && i<n+1)maxi[i++]=-1;
	if(i<n+1)maxi[i] = 1;
	for(int j=i;j<n+1;j++){
	    if(j>=v[0] ){
	        maxi[j] = maxi[j-v[0]]==-1?-1:max(maxi[j], 1+maxi[j-v[0]]);
	    }
	    if(j>=v[1] ){
	        maxi[j] = maxi[j-v[1]]==-1?(maxi[j]==0?-1:maxi[j]):max(maxi[j], 1+maxi[j-v[1]]);
	    }
	    if(j>=v[2] ){
	        maxi[j] = maxi[j-v[2]]==-1?(maxi[j]==0?-1:maxi[j]):max(maxi[j], 1+maxi[j-v[2]]);
	    }
	}
	return maxi[n]==-1?-9998:maxi[n];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> value(3);
	    for(int i=0;i<=2;i++){
            cin >> value[i];
        }
        cout << solve(value,n) << endl;
	}
	return 0;
}