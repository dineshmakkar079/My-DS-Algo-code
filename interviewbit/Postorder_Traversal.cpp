/*
Time : Thu Jul 06 2017 23:42:44 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/postorder-traversal/
Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

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
vector<int> postorderTraversal(TreeNode* A) {
	stack<pair<TreeNode*,bool> > s;
	vector<int> v;
	TreeNode* temp = A, *root = A;
	if(A){
		pair<TreeNode*, bool> p; p.first = A; p.second = false;
		s.push(p);
	}
	while(!s.empty()){
		pair<TreeNode*, bool> top = s.top();s.pop();
		if(top.second){
			v.push_back(top.first->val);
		}else{
			top.second = true;
			s.push(top);
			pair<TreeNode*, bool> l,r;
			r.first = top.first->right; l.first = top.first->left;
			r.second = l.second = false;
			if(r.first) s.push(r);
			if(l.first) s.push(l);
		}
	}
	return v;
}

int main(){

	return 0;
}
