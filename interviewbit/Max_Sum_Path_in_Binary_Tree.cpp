/*
Time : Sun Oct 15 2017 20:37:34 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example 
:

Given the below binary tree,

       1
      / \
     2   3
Return 6.

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

int util(TreeNode* root,int& res){
    if(!root) return 0;
    int l = util(root->left,res);
    int r = util(root->right,res);
    
    int max_single = max(max(l,r) + root->val, root->val);
    int max_top = max(max_single, l + r + root->val);
    res = max(res, max_top);
    return max_single;
}
 
int Solution::maxPathSum(TreeNode* A) {
    int res = INT_MIN;
    util(A, res);
    return res;
}

int main(){

	return 0;
}
