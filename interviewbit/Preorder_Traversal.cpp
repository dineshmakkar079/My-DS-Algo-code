/*
Time : Thu Jul 06 2017 23:09:53 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/preorder-traversal/
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

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
vector<int> Solution::preorderTraversal(TreeNode* A) {
	stack<TreeNode*> s;
	vector<int> v;
	TreeNode* temp = A, *root = A;
    if(A)
    	s.push(A);
    while(!s.empty()){
    	TreeNode* top = s.top();
    	s.pop();
    	if(top->right) s.push(top->right);
    	if(top->left) s.push(top->left);
    	v.push_back(top->val);
    }
    return v;
}

int main(){

	return 0;
}
