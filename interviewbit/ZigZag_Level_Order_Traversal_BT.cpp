/*
Time : Fri Jul 07 2017 16:11:12 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left 
to right, then right to left for the next level and alternate between).

Example : 
Given binary 
tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
        [15, 7]
]

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

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
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
			if(level%2==1){
				int l = v.size();
				for(int i=0;i<l;i++){
					s.push(v[i]);
				}
				v.clear();
				while(!s.empty()){
				    int t = s.top();
					v.push_back(t);
					s.pop();
				}
			}
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
