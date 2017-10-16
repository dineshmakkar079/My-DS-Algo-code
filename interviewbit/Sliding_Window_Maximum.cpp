/*
Time : Sun Oct 15 2017 21:03:46 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/sliding-window-maximum/
A long array A[] is given to you. There is a sliding window of size w which is moving from the very 
left of the array to the very right. You can only see the w numbers in the window. Each time the 
sliding window moves rightwards by one position. You have to find the maximum for each window. The 
following example will give you more clarity.

Example :

The array is [1 3 -1 -3 5 3 6 7], and 
w is 3.

Window position	Max
 	 
[1 3 -1] -3 5 3 6 7	3
1 [3 -1 -3] 5 3 6 7	3
1 3 [-1 -3 5] 3 6 7	5
1 
3 -1 [-3 5 3] 6 7	5
1 3 -1 -3 [5 3 6] 7	6
1 3 -1 -3 5 [3 6 7]	7
Input: A long array A[], and a window 
width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i w-1]
Requirement: Find 
a good optimal way to get B[i]

 Note: If w > length of the array, return 1 element with the max 
of the array.

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::slidingMaximum(const vector<int> &v, int b) {
    int n = v.size();
    if(n <= b){
        int maxi = v[0]; for(int a : v)maxi = max(maxi, a);
        return vector<int>(1,maxi);
    }
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<b;i++){
        if(q.empty())q.push_back(i);
        else{
            while(!q.empty() && v[q.back()] < v[i])
                q.pop_back();
            q.push_back(i);
        }
    }
    for(int i=b;i<n;i++){
        int f = q.front();
        ans.push_back(v[f]);
        while(!q.empty() && q.front() <= i-b)
            q.pop_front();
        while(!q.empty() && v[q.back()] < v[i])
            q.pop_back();
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);
    return ans;
}

int main(){

	return 0;
}
