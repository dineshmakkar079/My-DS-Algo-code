/*
Time : Sun Jul 09 2017 14:42:32 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/2-sum-binary-tree/
Given a binary search tree T, where each node contains a positive integer, and an integer K, you 
have to find whether or not there exist two different nodes A and B such that A.value   B.value 
= K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes 
- Your solution 
should run in linear time and not take memory more than O(height of T).
- Assume all values in BST 
are distinct.

Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 
2: 

T:        10
         / \
        9   20

K = 40

Return: 0

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::t2Sum(TreeNode* root, int sum){
	stack<TreeNode*> s1,s2;
	TreeNode* temp = root;
	while(temp){
		s1.push(temp);
		temp = temp->left;
	}
	temp =  root;
	while(temp){
		s2.push(temp);
		temp = temp->right;
	}
	while(!s1.empty() && !s2.empty()){
		TreeNode* top1 = s1.top();
		TreeNode* top2 = s2.top();
		if(top1->val + top2->val == sum && top1 != top2)
			return true;
		if(top1->val + top2->val < sum){
			s1.pop();
			TreeNode* t1 = top1->right;
			while(t1){
				s1.push(t1);
				t1 = t1->left;
			}
		}else{
			s2.pop();
			TreeNode* t2 = top2->left;
			while(t2){
				s2.push(t2);
				t2 = t2->right;
			}
		}
	}
	return false;
}

int main(){

	return 0;
}
