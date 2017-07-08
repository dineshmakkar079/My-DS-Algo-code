/*
Time : Sat Jul 08 2017 19:14:04 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

    
  6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
 
   [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth 
will come first.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    int vert = 0;
    queue<pair<TreeNode*,int> > q;
    vector<pair<TreeNode*,int> > v;
    pair<TreeNode*,int> t;t.first = root; t.second = 0;
    pair<TreeNode*,int> null; null.first = NULL; null.second = -1;
    q.push(t);
    q.push(null);
    int level = 0;
    while(!q.empty()){
        pair<TreeNode*,int> front = q.front(); q.pop();
        if(!front.first){
            if(q.empty()) break;
            q.push(null);
        }else{
            v.push_back(front);
            vert = front.second;
            if(front.first->left) {
                pair<TreeNode*,int> p; p.first = front.first->left; p.second = vert-1;
                q.push(p); 
            }
            if(front.first->right) {
                pair<TreeNode*,int> p; p.first = front.first->right; p.second = vert+1;
                q.push(p); 
            }
        }
    }
    int mi = v[0].second,ma = v[0].second;
    int l = v.size();
    for(int i=0;i<l;i++){
        mi = min(mi, v[i].second);
        ma = max(ma, v[i].second);
    }
    vector< vector<int> > ret(ma-mi+1);
    for(int i=0;i<l;i++){
        (ret[v[i].second - mi]).push_back(v[i].first->val);
    }
    return ret;
}

int main(){

	return 0;
}
