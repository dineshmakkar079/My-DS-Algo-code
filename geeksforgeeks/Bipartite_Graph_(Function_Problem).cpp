/*
Time : Mon Oct 09 2017 23:04:43 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/bipartite-graph/1
Given an adjacency matrix representation of a graph g having 0 based index your task is to complete 
the function isBipartite which returns true if the graph is a bipartite graph else returns false.

Input:
The 
first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains an integer v denoting the no of vertices of the graph then in the next line 
are v*v space separated values of the adjacency matrix representation of the graph g.

Output:
For 
each test case in a new line output will be 1 if the graph is bipartite else 0.

Constraints:
1<=T<=100
1<=v<=15
0<=g[][]<=1

Example(To 
be used only for expected output):
Input:
2
4
0 1 0 1 1 0 1 0 0 1 0 1 1 0 1 0
3
0 1 0 0 0 1 1 0 
0
Output:
1
0

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, hence a user 
should not read any input from stdin/console. The task is to complete the function specified, and 
not to write the full code.

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

void explore(int g[][MAX],vector<int>& color,int index,int col,bool& res,int v){
    if(!res)return;
    if(color[index]==1-col){
        res = false;
        return;
    }
    if(color[index]!=-1)return;
    color[index] = col;
    for(int i=0;i<v;i++){
        if(g[index][i]){
            explore(g,color,i,1-col,res,v);
        }
    }
}

bool isBipartite(int g[][MAX],int v)
{
    vector<int> co(v,-1);
    vector<int>& color = co;
    bool r = true;
    bool& res = r;
    queue<int> q;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(g[i][j] && color[i]==-1)
                explore(g,color,i,1,res,v);
        }
    }
    return res;
}

int main(){

	return 0;
}
