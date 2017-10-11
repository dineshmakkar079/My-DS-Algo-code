/*
Time : Wed Oct 04 2017 19:07:32 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
Find the largest rectangular area possible in a given histogram where the largest rectangle can 
be made of a number of contiguous bars. For simplicity, assume that all bars have same width and 
the width is 1 unit.

 



Input:
The first line contains an integer 'T' denoting the total number 
of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. 
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the 
array. The elements of the array represents the height of the bars.


Output:
In each seperate line 
the maximum rectangular area possible from the contigous bars.


Constraints:
1<=T<=30
1<=N<=100
1<=A[i]<=1000


Example:
Input: 
1
7
6 
2 5 4 5 1 6

Output:
12

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
using namespace std;
 
// The main function to find the maximum rectangular area under given
// histogram with n bars
int getMaxArea(int n)
{
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin >> A[i];
    stack<int> s;
 
    int maxi=INT_MIN;
    vector<int> left(n),right(n);
    // Find the next smaller element on right
    for(int i=0;i<n;i++){
        if(s.empty() || A[s.top()] <= A[i])
            s.push(i);
        else{
            while(!s.empty() && A[s.top()]>A[i]){
                right[s.top()]=i; s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        right[s.top()]=n; s.pop();
    }
    // Find the previous smaller element on left
    for(int i=n-1;i>=0;i--){
        if(s.empty() || A[s.top()]<=A[i])
            s.push(i);
        else{
            while(!s.empty() && A[s.top()]>A[i]){
                left[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        left[s.top()]=-1;
        s.pop();
    }
    // Find the area by taking ith element as the smallest in the window
    // specified by (right[i]-left[i]-1) and get the maximum of those.
    for(int i=0;i<n;i++)
        maxi=max(maxi,(right[i]-left[i]-1)*A[i]);
    return maxi;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    cout << getMaxArea(n) << endl;
	}
	return 0;
}