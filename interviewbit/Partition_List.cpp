/*
Time : Wed Jun 28 2017 21:51:10 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/partition-list/
Given a linked list and a value x, partition it such that all nodes less than x come before nodes
greater than or equal to x.

You should preserve the original relative order of the nodes in each
of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* Solution::partition(ListNode* A, int B) {
 	if(!A || !A->next)
 		return A;
 	ListNode *head = A, *smalle = A, *bigb = A, *bige = A;
 	ListNode* smallb = new ListNode(-1); smallb->next = A; A = smallb;
 	smalle = bigb = bige = smallb = A;
 	while(smalle && smalle->next && smalle->next->val < B )
 		smalle = smalle->next;
 	while(bige && bige->val < B)
 		bige = bige->next;
 	bigb = bige;
 	ListNode* temp = bige->next;
 	while(temp){
 		if(temp->val >= B){
 			temp = temp->next;
 			bige = bige->next;
 		}else{
 			smalle->next = temp;
 			ListNode* temp2 = temp->next;
 			temp->next = bigb;
 			temp = temp2;
 			smalle = smalle->next;
 			bige->next = temp;
 		}
 	}
 	ListNode* toRet = A->next;
 	delete A;
 	return toRet;
 }


#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
