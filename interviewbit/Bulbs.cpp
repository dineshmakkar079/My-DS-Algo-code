/*
Time : Fri Aug 25 2017 17:36:26 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/bulbs/
N light bulbs are connected by a wire. Each bulb has a switch associated with it, however due to 
faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb. Given 
an initial state of all bulbs, find the minimum number of switches you have to press to turn on 
all the bulbs. You can press the same switch multiple times.

Note : 0 represents the bulb is off 
and 1 represents the bulb is on.

Example:

Input : [0 1 0 1]
Return : 4

Explanation :
	press switch 
0 : [1 0 1 0]
	press switch 1 : [1 1 0 1]
	press switch 2 : [1 1 1 0]
	press switch 3 : [1 1 1 1]

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::bulbs(vector<int> &v) {
    int count = 0;
	int ans = 0, l = v.size();
	for(int i=0;i<l;i++){
		if(!((count%2)^v[i])){
			ans++;
			count++;
		}
	}
	return ans;
}

int main(){

	return 0;
}
