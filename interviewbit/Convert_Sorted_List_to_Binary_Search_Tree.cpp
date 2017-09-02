/*
Time : Sat Sep 02 2017 12:47:03 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/
Given a singly linked list where elements are sorted in ascending order, convert it to a height 
balanced BST.

 A height balanced BST : a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given 
A : 1 -> 2 -> 3
A height balanced BST  :

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

TreeNode* sortedArrayToBST(vector<int> &A) {
    if(A.size()==0)
        return NULL;
	return sortedArrayToBSTHelper(A,0,A.size()-1);
}
 
TreeNode* Solution::sortedListToBST(ListNode* root) {
    std::vector<int> v;
    ListNode* temp = root;
    while(temp){
    	v.push_back(temp->val);
    	temp = temp->next;
    }
    vector<int>& vec = v;
    return sortedArrayToBST(vec);
}

int main(){

	return 0;
}
