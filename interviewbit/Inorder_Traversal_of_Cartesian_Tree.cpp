/*
Time : Sun Jul 09 2017 11:35:42 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all
  the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
  
          3
         /
        2
       /
      1

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
TreeNode* helperBuildTree(vector<int> &A, int start, int end){
	if(start > end)
		return NULL;
	if(start == end)
		return new TreeNode(A[start]);
	int maxindex = start;
	for(int i=start; i<=end;i++)
		if(A[maxindex] < A[i]) maxindex = i;
	TreeNode* root = new TreeNode(A[maxindex]);
	root->left = helperBuildTree(A, start, maxindex - 1);
	root->right = helperBuildTree(A, maxindex + 1 , end);
	return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
	return helperBuildTree(A,0, A.size()-1);
}


int main(){

	return 0;
}
