/*
Time : Sun Jul 09 2017 12:25:24 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/next-greater-number-bst/
Given a BST node, return the node which has value just greater than the given node.

Example:

Given 
the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 98 as thats 
the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is 
the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is 
always present in the tree.

PROBLEM APPROACH:

Complete solution in the hint.

*/

#include <bits/stdc++.h>

using namespace std;

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
	stack<TreeNode*> s;
	TreeNode* root = A;
	s.push(root);
	while(root->val != B){
		if(root->val < B){
			root = root->right;
		}
		else{
			root = root->left;
		}
		s.push(root);
	}
	if(root->right){
		while(!s.empty())s.pop();
		root = root->right;
		while(root->left){
			root = root->left;
		}
		return root;
	}else{
		TreeNode* root = s.top(); s.pop();
		TreeNode* parent = s.top();
		while(!s.empty()){
			parent = s.top();
			if(parent->left == root)
				return parent;
			s.pop();
			root = parent;
		}
		if(s.empty())
		    return NULL;
	}
}



int main(){

	return 0;
}
