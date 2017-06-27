/*
Time : Tue Jun 27 2017 23:14:11 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
Given a sorted linked list, delete all duplicates such that each element appear only once.

For
example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
     if(!A || !A->next)
 		return A;
 	ListNode* head = A;
 	ListNode* temp = A ;
 	while(temp->next){
 		if(temp->val == temp->next->val){
 			ListNode* temp2 = temp->next;
 			temp->next = temp2->next;
 			delete temp2;
 		}else{
 		    temp = temp->next;
 		}
 	}
 	return head;
 }
