/*
Time : Fri Oct 13 2017 03:03:49 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/maximum-node-level/1/?ref=self
Find the level in a binary tree which has the maximum number of nodes. The root is at level 0.

Note: 
The Input/Output format and Example given are used for system's internal purpose, and should be 
used by a user for Expected Output only. As it is a function problem, hence a user should not read 
any input from stdin/console. The task is to complete the function specified, and not to write the 
full code.

Input:
The first line consists of T test cases. The first line of every test case consists 
of N, denoting the number of edges in the tree. The second and third line of every test case consists 
of N, nodes of the binary tree.

Output:
Print the level number with maximum nodes.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
1 
2 L 1 3 R 2 4 L
3
1 3 L 1 2 R 2 4 R

Output:
1
1

** For More Input/Output Examples Use 'Expected 
Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/

void maxnode(Node* root,vector<int>& v,int level){
    if(root){
        maxnode(root->left,v,level+1);
        v[level] += 1;
        maxnode(root->right,v,level+1);
    }
}

int maxNodeLevel(Node *root)
{
    vector<int> ve(101,0);
    vector<int>& v = ve;
    maxnode(root,v,0);
    return max_element(v.begin(),v.end())-v.begin();
}

int main(){

	return 0;
}
