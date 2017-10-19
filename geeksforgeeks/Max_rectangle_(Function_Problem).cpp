/*
Time : Wed Oct 18 2017 20:18:32 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/max-rectangle/1
Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle 
area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the 
Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of the matrix 
M. Your function should return an integer denoting the area of the maximum rectangle .

Input:
The 
first line of input is an integer T denoting the no of test cases . Then T test cases follow. The 
first line of each test case are 2 integers n and m denoting the size of the matrix M . Then in 
the next line are n*m space separated values of the matrix M.

Output:
For each test case output 
will be the area of the maximum rectangle .

Constraints:
1<=T<=50
1<=n,m<=50
0<=M[][]<=1

Example:
Input
1
4 
4 
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

Explanation
For the above test case the matrix will 
look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 
4 *2 = 8

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, hence a user 
should not read any input from stdin/console. The task is to complete the function specified, and 
not to write the full code.

** For More Input/Output Examples Use 'Expected Output' option **

*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method*/
#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

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

int maximalRectangle(vector<vector<int> > &v) {
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


int maxArea(int v[MAX][MAX],int n,int m)
{
    vvi vec(n, vi(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            vec[i][j] = v[i][j];
    return maximalRectangle(vec);
}

int main(){

	return 0;
}
