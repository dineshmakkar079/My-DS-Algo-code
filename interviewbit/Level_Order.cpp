/*
Time : Sat Sep 02 2017 12:40:51 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/level-order/
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, 
level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its 
level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question 
where you are asked to do a level order traversal of the tree when depth of the tree is much greater 
than number of nodes on a level.

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
vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
	stack<int> s;
	vector<int> v;
	vector< vector<int> > ret;
	q.push(root);
	q.push(NULL);
	int level = 0;
	while(!q.empty()){
		TreeNode* front = q.front(); q.pop();
		if(!front){
			level++;
			ret.push_back(v);
			v.clear();
		    if(q.empty()){
		        return ret;
		    }
		    q.push(NULL);
		}else{
			v.push_back(front->val);
			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
	}
	return ret;
}

int main(){

	return 0;
}
