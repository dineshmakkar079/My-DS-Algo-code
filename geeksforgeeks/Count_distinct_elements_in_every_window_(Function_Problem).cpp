/*
Time : Fri Oct 06 2017 11:06:17 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
Given an array A[] of size n and an integer k, your task is to complete the function countDistinct 
which prints the count of distinct numbers in all windows of size k in the array A[].

Example

Input: 
 A[] = {1, 2, 1, 3, 4, 2, 3};
            k = 4
Output:
3 4 4 3
Explanation:
First window is {1, 
2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers 
is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count 
of distinct numbers is 3


Input:
The first line of input contains an integer T denoting the no 
of test cases. Then T test cases follow. Each test case contains two integers n and k. Then in the 
next line are N space separated values of the array A[].

Output:
For each test case in a new line 
print the space separated values denoting counts of distinct numbers in all windows of size k in 
the array A[].

Constraints:
1<=T<=100
1<=n,k<=100
1<=A[]<=100

Example(To be used only for expected 
output):
Input:
2
7 4
1 2 1 3 4 2 3
3 2
4 1 1
Output:
3 4 4 3
2 1

Note:The Input/Ouput format and 
Example given are used for system's internal purpose, and should be used by a user for Expected 
Output only. As it is a function problem, hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.

** For More Input/Output 
Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

void countDistinct(int a[], int k, int n)
{
    map<int,int> m;
    map<int,int>::iterator it;
    int size = 0;
    for(int i=0;i<k;i++){
        it=m.find(a[i]);
        if(it==m.end()){
            m[a[i]]=1;
            size++;
        }else{
            it->second++;
        }
    }
    cout << size << " ";
    for(int i=k;i<n;i++){
        it=m.find(a[i-k]);
        if(it->second==1){
            m.erase(it);
            size--;
        }else{
            it->second--;
        }
        it=m.find(a[i]);
        if(it==m.end()){
            m[a[i]]=1;
            size++;
        }else{
            it->second++;
        }
        cout << size << " ";
    }
}

int main(){

	return 0;
}
