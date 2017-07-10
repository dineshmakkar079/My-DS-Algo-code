/*
Time : Mon Jul 10 2017 18:34:10 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
 
     TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there 
is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are 
set to NULL.

 Note:
You may only use constant extra space.
Example :

Given the following binary 
tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, 
the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
  
  4->5->6->7 -> NULL
 Note 1: that using recursion has memory overhead and does not qualify for 
constant space.
Note 2: The tree need not be a perfect binary tree.

*/

#include <bits/stdc++.h>

using namespace std;

void Solution::connect(TreeLinkNode* root) {
    queue<TreeLinkNode*> q;
    TreeLinkNode* prev = NULL, *current = NULL;
    q.push(root);
    q.push(NULL);
    root->next = NULL;
    int level = 1;
    while(!q.empty()){
        TreeLinkNode* current = q.front(); q.pop();
        if(!current){
            level++;
            if(q.empty()) return;
            q.push(NULL);
            if(prev)
            prev->next = NULL;
        }else{
            if(prev!=current && prev)
            prev->next = current;
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        prev = current;
    }
}

int main(){

	return 0;
}
