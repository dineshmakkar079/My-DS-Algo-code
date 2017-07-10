/*
Time : Mon Jul 10 2017 18:30:23 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


        1
       / \
      2   5
     / \   \
    3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             
6
Note that the left child of all nodes should be NULL.

*/

#include <bits/stdc++.h>

using namespace std;

TreeNode* Solution::flatten(TreeNode* root) {
    if(!root)
        return NULL;
    if(!root->left && !root->right){
        return root;
    }
    TreeNode* left = NULL, *right = NULL;
    if(root->left) left = flatten(root->left);
    if(root->right) right = flatten(root->right);
    root->right = left;
    TreeNode* temp = left;
    while(temp && temp->right){
        temp = temp->right;
    }
    if(!temp) temp = root;
    temp->right = right;
    temp = root;
    while(temp){
        temp->left = NULL;
        temp = temp->right;
    }
  return root;
}


int main(){

	return 0;
}
