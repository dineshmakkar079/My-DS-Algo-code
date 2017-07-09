/*
Time : Sun Jul 09 2017 13:06:08 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example 
:

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 
NOTE : You may assume 1 <= k <= Total number of nodes in BST

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::kthsmallest(TreeNode* root, int k) {
	stack<TreeNode*> s;
	TreeNode* temp = root;
	while(temp){
		s.push(temp);
		temp = temp->left;
	}
	int count = 0;
	while(!s.empty()){
		TreeNode* top = s.top();
		count++;
		if(count == k)
			return top->val;
		s.pop();
		TreeNode* t = top->right;
		while(t){
			s.push(t);
			t = t->left;
		}
	}
}

int main(){

	return 0;
}
