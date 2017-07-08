/*
Time : Fri Jul 07 2017 16:08:08 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/max-depth-of-binary-tree/
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of 
nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path 
has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.

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
int Solution::maxDepth(TreeNode* root) {
    return !root?0:(1+max(maxDepth(root->left),maxDepth(root->right)));
}

int main(){

	return 0;
}
