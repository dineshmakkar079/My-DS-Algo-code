/*
Time : Mon Oct 09 2017 16:43:47 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/topological-sort/1
Given a directed graph you need to complete the function topoSort which returns an array having 
the topologically sorted elements of the array and takes two arguments . The first argument is the 
Graph graph represented as adjacency list and the second is the number of vertices N .

Note : There 
can be multiple topological sorts of a Graph.  The driver program that calls your function doesn't 
match your output element by element, but checks whether the output produced by your function is 
a valid topological sort or not.

Input:
The first line of input takes the no of test cases then 
T test cases follow . Each test case contains two lines . The first  line of each test case  contains 
two integers E and N representing no of edges and the no of vertices . Then in the next line are 
E  pairs of integers u v representing an edge from u to v in the graph.

Output:
For each test case 
output will be 1 if the topological sort is done correctly else it will be 0 .

Constraints:
1<=T<=50
1<=E,N<=50
0<=u,v

Example:

Input
1
6 
6 
5 0 5 2 2 3 4 0 4 1 1 3

Output
1

The output 1 denotes that the order is valid.  So if you have 
implemented your function correctly, then output would be 1 for all test cases.

Note:The Input/Ouput 
format and Example given are used for system's internal purpose, and should be used by a user for 
Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.
 

** For More Input/Output 
Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You need to complete this function */
int *topoSort(vector<int> g[], int N)
{
    vector<int> in(N,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<g[i].size();j++){
            in[g[i][j]]++;
        }
    }
    
    queue<int> q;
    for(int i=0;i<N;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    
    vector<int> ans;
    int index = 0;
    vector<bool> vis(N,false);
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        vis[f]=true;
        ans.push_back(f);
        for(int j=0;j<g[f].size();j++)
            if(!vis[g[f][j]] && --in[g[f][j]]==0)
                q.push(g[f][j]);
    }
    
    int *ans1 = new int[N];
    for(int i=0;i<N;i++)ans1[i]=ans[i];
    return ans1;
}

int main(){

	return 0;
}
