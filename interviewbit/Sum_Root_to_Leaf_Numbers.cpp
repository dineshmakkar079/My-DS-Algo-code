/*
Time : Sun Jul 09 2017 08:28:11 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An 
example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of 
all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents 
the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) 
% 1003 = 25 % 1003 = 25.

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

int bigmod10(int count){
	long long mult = pow(10,10);
	mult %= 1003;
	int ans = 1;
	for(int i=0;i<count;i++)
		ans = (ans * mult)%1003;
	return ans;
}

int bigmod(vector<int> num){
	long long localnum = 0, ans = 0, count = 0;
	int l = num.size();
	for(int i=0;i<l;i+=10){
		localnum = 0;
		for(int j=i;j<i+10 && j <l; j++){
			localnum += num[j] * pow(10,j%10);
		}
		localnum %= 1003;
		int temp = (localnum * bigmod10(count)%1003)%1003;
		ans = (ans + temp)%1003;
		count++;
	}
	return ans;
}

int Solution::sumNumbers(TreeNode* root) {
    map<TreeNode*, TreeNode*> ma;
    map<TreeNode* , TreeNode*>& m = ma;
    m[root] = NULL;
    vector<TreeNode*> leaf = inorderTraversal(root,m);
    long long ans = 0,localSum = 0, mult = 1;
    int l = leaf.size();
    for(int i=0;i<l;i++){
        TreeNode* t = leaf[i];
        vector<int> num;
        while(t!=root){
        	num.push_back(t->val;)
            t = m[t];
        }
        num.push_back(root->val);
        ans = (ans + bigmod(num))%1003;
    }
    return ans;
}

int main(){

	return 0;
}
