/*
Time : Sun Jul 09 2017 11:45:44 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/invert-the-binary-tree/
Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example 
: 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
 
  /   \
  3     2
 / \   / \
7   6 5   4

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
TreeNode* Solution::invertTree(TreeNode* root) {
	if(!root || (!root->left && !root->right)) return root;
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	if(root->left) root->left = invertTree(root->left);
	if(root->right) root->right = invertTree(root->right);
	return root;
}

int main(){

	return 0;
}
