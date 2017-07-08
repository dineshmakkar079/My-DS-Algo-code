/*
Time : Fri Jul 07 2017 11:43:46 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/symmetric-binary-tree/
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example 
:

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following 
is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this 
problem

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
int isSymmetricHelper(TreeNode* A, TreeNode* B){
	if((A && !B) || (!A && B)){
		return 0;
	}else if(!A && !B){
		return 1;
	}else{
		return (A->val == B->val) * isSymmetricHelper(A->right,B->left) * isSymmetricHelper(A->left, B->right);
	}
}

int Solution::isSymmetric(TreeNode* A) {
	return isSymmetricHelper(A,A);
}


int main(){

	return 0;
}
