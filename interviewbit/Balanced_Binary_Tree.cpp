/*
Time : Sat Jul 08 2017 20:17:25 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/balanced-binary-tree/
Given a binary tree, determine if it is height-balanced.

Height-balanced binary tree : is defined as a binary tree in which the depth of 
 the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right 
subtree has depth 0. 
         Difference = 2 > 1.

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

int height(TreeNode* root){
    return !root?0:1+max(height(root->left),height(root->right));
}

int Solution::isBalanced(TreeNode* A) {
    if(!A || (!A->left && !A->right))return 1;
    return isBalanced(A->left) * isBalanced(A->right) * (abs(height(A->left) - height(A->right))<=1?1:0);
}

int main(){

	return 0;
}
