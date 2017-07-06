/*
Time : Thu Jul 06 2017 21:23:27 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/inorder-traversal/
Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

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
vector<int> inorderTraversal(TreeNode* A) {
	stack<TreeNode*> s;
	vector<int> v;
	TreeNode* temp = A, *root = A;
	while(temp){
		s.push(temp);
		temp = temp->left;
	}
	while(!s.empty()){
		TreeNode* top = s.top();
		v.push_back(top->val);
		s.pop();
		TreeNode* t = top->right;
		while(t){
			s.push(t);
			t = t->left;
		}
	}
	return v;
}


int main(){

	return 0;
}
