/*
Time : Sun Aug 27 2017 22:38:50 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
Given an array of integers where each element represents the max number of steps that can be made 
forward from that element. Write a function to return the minimum number of jumps to reach the end 
of the array (starting from the first element). If an element is 0, then cannot move through that 
element.

Input: 
The first line contains an integer T, depicting total number of test cases. 
Then 
following T lines contains a number n denoting the size of the array.
Next line contains the sequence 
of integers a1, a2, ..., an.

Output:
Each seperate line showing the minimum number of jumps. If 
answer is not possible print -1.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
0<=a[N]<=100

Example:

Input:

1
11
1 
3 5 8 9 2 6 7 6 8 9

Output:

3

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

int minjumps(vector<int> a){
    int n = a.size();
    vector<int> minj(n);
    if(n==1) return 0;
    if(a[0]==0) return -1;
    minj[0] = a[0]==0 ? INT_MAX : 0;
    for(int i=1;i<n;i++){
        minj[i] = INT_MAX;
        for(int j=0;j<i;j++){
            if(j + a[j] >= i && minj[j]!=INT_MAX){
                minj[i] = min( minj[j]+1, minj[i] );
            }
        }   
    }
    return minj[n-1]==INT_MAX?-1:minj[n-1];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << minjumps(a) << endl;
	}
	return 0;
}