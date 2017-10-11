/*
Time : Tue Oct 10 2017 22:54:56 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Given an adjacency matrix (graph), the task is to find the shortest distance of all the vertex's 
from the source vertex. You are required to complete the function dijkstra which takes 3 arguments. 
The first argument is the adjacency matrix (graph) , the second argument is the source vertex s 
and the third argument is V denoting the size of the matrix. The function prints  V space separated 
integers where i'th integer denotes the shortest distance of the i'th vertex from source vertex.

Input:
The 
first line of input contains an integer T denoting the no of test cases . Then T test cases follow 
.The first line of each test case contains an integer V denoting the size of the adjacency matrix 
 and in the next line are V space separated values of the matrix (graph) .The third line of each 
test case contains an integer denoting the source vertex s.

Output:
For each test case output will 
be V space separated integers where the ith integer denote the shortest distance of ith vertex from 
source vertex.

Constraints:
1<=T<=20 
1<=V<=20
0<=s 1<=graph[][]<=1000

Example:
Input
2
2
0 25 
25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output
0 25
7 6 0

 

** For More Input/Output Examples Use 'Expected 
Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
    
int getmindex(int v,vector<int>& dis,vector<bool>& conf){
    int mindex = 0, minval = INT_MAX;
    for(int i=0;i<v;i++){
        if(dis[i] < minval && !conf[i]){
            minval = dis[i]; mindex = i;
        }
    }
    return mindex;
}

void dijkstra(int g[MAX][MAX], int s,int v)
{
    vector<int> d(v,INT_MAX);
    vector<int>& dis = d;
    dis[s]=0;
    vector<bool> con(v,false);
    vector<bool>& conf = con;
    for(int k=0;k<v;k++){
        int m = getmindex(v,dis,conf);
        conf[m] = true;
        for(int i=0;i<v;i++){
            if(g[m][i] && !conf[i] && dis[m]!=INT_MAX && dis[i] > dis[m]+g[m][i]){
                dis[i] = dis[m]+g[m][i];
            }
        }
    }
    for(int i=0;i<v;i++)
        cout << dis[i] << " ";
}

int main(){

	return 0;
}
