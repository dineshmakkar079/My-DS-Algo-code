/*
Time : Tue Oct 10 2017 01:14:34 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
Write a function to print the bredth first traversal for a graph from a given source s.

Input:
The 
task is to complete the function BFS which takes 3 arguments an integer denoting the starting node 
(s) of the bfs travel , a  graph (g)  and an array of visited nodes (vis)  which are initially all 
set to false . 
There are multiple test cases. For each test case, this method will be called individually.

Output:
The 
function should print the breath first traversal for the graph from the given source.

Note : The 
expected output button always produces BFS starting from node 1.

Constraints:
1 <=T<= 100
1 <=Number 
of  edges<= 100

Example:
Input:
1
4
1 2 1 3 1 4 3 5

Output:
1 2 3 4 5    //bfs from node 1
 

There 
is  one test cases.  First line of each test case represent an integer N denoting no of edges and 
then in the next line N pairs of values a and b are fed which denotes there is a unidirectional edge 
from a to b .

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You have to complete this function*/
void bfs(int s,vector<int> adj[],bool vis[])
{
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        if(!vis[f])
            cout << f << " ";
        vis[f]=true;
        for(int i=0;i<adj[f].size();i++){
            if(!vis[adj[f][i]]){
                q.push(adj[f][i]);
            }
        }
    }
}

int main(){

	return 0;
}
