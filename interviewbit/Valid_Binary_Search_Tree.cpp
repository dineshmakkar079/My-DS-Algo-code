/*
Time : Thu Jul 06 2017 23:58:36 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/valid-binary-search-tree/
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined 
as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The 
right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left 
and right subtrees must also be binary search trees.
Example :

Input : 
   1
  /  \
 2    3

Output 
: 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 
Return 0 / 1 ( 0 for false, 1 for true 
) for this problem

SOLUTION APPROACH :

Complete solution in the hints.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::isValidBST(TreeNode* A) {
    stack<TreeNode*> s;
	TreeNode* temp = A;
	int prev, current;
	while(temp){
		prev = temp->val;
		s.push(temp);
		temp = temp->left;
	}
	bool notFirstNode = false;
	while(!s.empty()){
		TreeNode* top = s.top();
		current = top->val;
		if(current <= prev && notFirstNode)
			return 0;
		prev = current;
		s.pop();
		notFirstNode = true;
		TreeNode* t = top->right;
		while(t){
			s.push(t);
			t = t->left;
		}
	}
	return 1;
}

int main(){

	return 0;
}
