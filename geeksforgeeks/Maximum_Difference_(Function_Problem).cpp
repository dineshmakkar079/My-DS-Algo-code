/*
Time : Wed Oct 04 2017 19:59:25 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/maximum-difference/1
Given array A[] of integers, the task is to complete the function findMaxDiff which finds the maximum 
absolute difference between nearest left and right smaller element of every element in array.If 
the element is the leftmost element, nearest smaller element on left side is considered as 0. Similarly 
if the element is the rightmost elements, smaller element on right side is considered as 0.

Examples:

Input 
: arr[] = {2, 1, 8}
Output : 1
Left smaller  LS[] {0, 0, 1}
Right smaller RS[] {1, 0, 0}
Maximum 
Diff of abs(LS[i] - RS[i]) = 1 

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4
Left smaller 
  LS[] = {0, 2, 4, 4, 4, 7, 2}
Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
Maximum Diff of abs(LS[i] 
- RS[i]) = 7 - 3 = 4 

Input : arr[] = {5, 1, 9, 2, 5, 1, 7}
Output : 1
Input:
The first line of 
input contains an integer T denoting the no of test cases. Then T test cases follow .Each test case 
contains an integer N denoting the size of the array A. In the next line are N space separated values 
of the array A.

Output:
For each test case output will be in a new line denoting the the maximum 
absolute difference between nearest left and right smaller element of every element in array.

Constraints:
1<=T<=100
1<=N<=100
1<=A[ 
]<=100

Example(To be used only for expected output) :
Input:
2
3
2 1 8
7
2 4 8 7 7 9 3
Output
1
4

** 
For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method */
int findMaxDiff(int A[], int n)
{
    stack<int> s;
    int maxi=INT_MIN;
    vector<int> left(n),right(n);
    // Find the next smaller element on right
    for(int i=0;i<n;i++){
        if(s.empty() || A[s.top()] <= A[i])
            s.push(i);
        else{
            while(!s.empty() && A[s.top()]>A[i]){
                right[s.top()]=A[i]; s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        right[s.top()]=0; s.pop();
    }
    // Find the previous smaller element on left
    for(int i=n-1;i>=0;i--){
        if(s.empty() || A[s.top()]<=A[i])
            s.push(i);
        else{
            while(!s.empty() && A[s.top()]>A[i]){
                left[s.top()]=A[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        left[s.top()]=0;
        s.pop();
    }
    
    for(int i=0;i<n;i++){
        maxi = max(maxi, abs(right[i] - left[i]));
    }
    return maxi;
}

int main(){

	return 0;
}
