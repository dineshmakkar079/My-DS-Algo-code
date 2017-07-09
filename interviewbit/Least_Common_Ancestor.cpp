/*
Time : Sat Jul 08 2017 21:37:31 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/least-common-ancestor/
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest 
common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic 
graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


 
       _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of 
nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes 
represented by val1 and val2. No guarantee that val1 and val2 exist in the tree. 
If one value doesn’t exist in the tree then return 
-1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the 
node struct but, you can’t add a parent pointer.

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

bool inorderTraversal(TreeNode* A,int value) {
	stack<TreeNode*> s;
	TreeNode* temp = A;
	while(temp){
		s.push(temp);
		temp = temp->left;
	}
	while(!s.empty()){
		TreeNode* top = s.top();
		if(top->val == value) return true;
		s.pop();
		TreeNode* t = top->right;
		while(t){
			s.push(t);
			t = t->left;
		}
	}
	return false;
}

void getPathToNode(stack<TreeNode*>& s,int val, TreeNode* root,bool& found,TreeNode* parent){
	if(!root){
		return;
	}
	if(root && root->val == val && !found){
		s.push(root);
		found = true;
		if(parent) val = parent->val;
		return;
	}
	if(!found) getPathToNode(s,val,root->left,found,root);
	if(!found) getPathToNode(s,val,root->right,found,root);
	if(found && root ){
		s.push(root);
		if(parent) {val = parent->val;} 
		return;
	}
}

int Solution::lca(TreeNode* root, int val1, int val2) {
	stack<TreeNode*> sone,stwo;
	stack<TreeNode*>& s1 = sone;
	stack<TreeNode*>& s2 = stwo;
	bool val1Exists = inorderTraversal(root, val1);
	bool val2Exists = inorderTraversal(root, val2);
	if(!val1Exists || !val2Exists){
		return -1;
	}
	bool bl = false;
	bool& found = bl;
	getPathToNode(s1, val1, root, found, NULL);
	found = false;
	getPathToNode(s2, val2, root, found, NULL);
	int ans=  -1;
	while(!s1.empty() && !s2.empty()){
		TreeNode *top1,*top2;
		top1 = s1.top();
		top2 = s2.top();
		if(top1 != top2)
			break;
		ans = top1->val;
		s1.pop();
		s2.pop();
	}
	return ans;
}

int main(){

	return 0;
}
