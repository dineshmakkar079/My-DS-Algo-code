/*
Time : Fri Jul 07 2017 14:04:51 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-postorder/
Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume 
that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
     
   Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

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
TreeNode* helperConstructInPost(vector<int>& in, vector<int>& post, int istart,int iend, int pstart, int pend){
	if(istart > iend || pstart > pend) 
	    return NULL;
	if(istart == iend)
		return new TreeNode(in[istart]);
	TreeNode* t = new TreeNode(post[pend]);
	int inindex;
	for(inindex = istart; inindex <= iend && in[inindex]!=post[pend] ; inindex++);
	t->left = helperConstructInPost(in,post,istart,inindex-1,pstart,pstart+inindex-istart-1);
	t->right = helperConstructInPost(in,post,inindex+1,iend,pstart+inindex-istart,pend-1);
	return t;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
	if(inorder.size()==0 || postorder.size() == 0)
		return NULL;
	return helperConstructInPost(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
}

int main(){

	return 0;
}
