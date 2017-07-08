/*
Time : Sat Jul 08 2017 17:18:34 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/min-depth-of-binary-tree/
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the 
shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on 
a leaf node. 
Example :

         1
        /
       2
min depth = 2.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* root) {
    queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	int level = 1;
	while(!q.empty()){
		TreeNode* front = q.front(); q.pop();
		if(!front){
			q.push(NULL);
			level++;
		}else{
		    if(!front->left && !front->right)
		        return level;
			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
	}
	return level;
}


int main(){

	return 0;
}
