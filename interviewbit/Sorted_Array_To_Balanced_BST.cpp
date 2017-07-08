/*
Time : Fri Jul 07 2017 11:56:53 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.

 
Balanced tree : a height-balanced binary tree is defined as a binary tree in which the 
depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height 
balanced BST  : 

      2
    /   \
   1     3

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
TreeNode* sortedArrayToBSTHelper(const std::vector<int> &v, int start, int end){
    if(start > end)
        return NULL;
	if(start == end)
		return new TreeNode(v[start]);
	int mid = (start + end)/2;
	TreeNode* middle = new TreeNode(v[mid]);
	middle->left = sortedArrayToBSTHelper(v,start,mid-1);
	middle->right = sortedArrayToBSTHelper(v,mid+1,end);
	return middle;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
	return sortedArrayToBSTHelper(A,0,A.size()-1);
}

int main(){

	return 0;
}