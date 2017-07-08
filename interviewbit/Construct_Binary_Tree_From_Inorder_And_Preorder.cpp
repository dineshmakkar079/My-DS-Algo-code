/*
Time : Fri Jul 07 2017 14:13:05 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume 
that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
     
   Inorder  : [2, 1, 3]

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

TreeNode* helperConstructInPre(vector<int>& in, vector<int>& pre, int istart,int iend, int pstart, int pend){
	if(istart > iend || pstart > pend)
		return NULL;
	if(istart == iend)
		return new TreeNode(in[istart]);
	TreeNode* t = new TreeNode(pre[pstart]);
	int inindex;
	for(inindex = istart; inindex <= iend && in[inindex]!=pre[pstart] ; inindex++);
	t->left = helperConstructInPre(in,pre,istart,inindex-1,pstart+1,pstart+inindex-istart);
	t->right = helperConstructInPre(in,pre,inindex+1,iend,pstart+1+inindex-istart,pend);
	return t;
}

TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
	if(inorder.size()==0 || preorder.size() == 0)
		return NULL;
    return helperConstructInPre(inorder,preorder,0,inorder.size()-1,0,inorder.size()-1);
}

int main(){

	return 0;
}
