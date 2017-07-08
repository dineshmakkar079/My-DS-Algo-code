/*
Time : Sat Jul 08 2017 23:38:54 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/path-sum/
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up 
all the values along the path equals the given sum.

Example :

Given the below binary tree and 
sum = 22,

              5
             / \
            4   8
           /   / \
          11  13 
 4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 
which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

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
int helperHasPathSum(TreeNode* root,int currentSum, int requiredSum){
	if(!root){
		return 0;
	}else{
		if(!root->left && !root->right && root->val + currentSum == requiredSum)
			return 1;
		if(!root->left && !root->right && root->val + currentSum != requiredSum)
			return 0;
		return helperHasPathSum(root->left, currentSum + root->val, requiredSum) || helperHasPathSum(root->right, currentSum + root->val , requiredSum);
	}
}

int Solution::hasPathSum(TreeNode* root, int requiredSum) {
    return helperHasPathSum(root, 0, requiredSum);
}

int main(){

	return 0;
}
