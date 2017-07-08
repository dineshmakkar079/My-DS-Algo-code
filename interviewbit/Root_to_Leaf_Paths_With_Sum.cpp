/*
Time : Sat Jul 08 2017 23:48:27 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given 
sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
 
           4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5  
 1
return

[
   [5,4,11,2],
   [5,8,4,5]
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

vector<TreeNode*> inorderTraversal(TreeNode* A,map<TreeNode* , TreeNode*>& m) {
    stack<TreeNode*> s;
    vector<TreeNode*> v;
    TreeNode* temp = A, *root = A;
    while(temp){
        if(temp->left) m[temp->left] = temp;
        if(temp->right) m[temp->right] = temp;
        s.push(temp);
        temp = temp->left;
    }
    while(!s.empty()){
        TreeNode* top = s.top();
        if(top->left) m[top->left] = top;
        if(top->right) m[top->right] = top;
        if(!top->left && !top->right)
            v.push_back(top);
        s.pop();
        TreeNode* t = top->right;
        while(t){
            s.push(t);
            t = t->left;
        }
    }
    return v;
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    map<TreeNode*, TreeNode*> ma;
    map<TreeNode* , TreeNode*>& m = ma;
    m[root] = NULL;
    vector<TreeNode*> leaf = inorderTraversal(root,m);
    vector< vector<int> > ret;
    int l = leaf.size();
    stack<int> s;
    for(int i=0;i<l;i++){
        TreeNode* t = leaf[i];
        int localSum = root->val;
        while(t!=root){
            s.push(t->val);
            localSum += t->val;
            t = m[t];
        }
        if(localSum == sum){
            vector<int> add;
            add.push_back(root->val);
            while(!s.empty()){ add.push_back(s.top()); s.pop(); }
            ret.push_back(add);
        }
        while(!s.empty()){
            s.pop();
        }
    }
    return ret;
}

int main(){

	return 0;
}
