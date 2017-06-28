/*
Time : Wed Jun 28 2017 12:54:48 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/merge-two-sorted-lists/
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing
together the nodes of the first two lists, and should also be sorted.

For example, given following
linked lists :

  5 -> 8 -> 20
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 ->
15 -> 20

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
 	if(!A || !B)
 		return (!A)?B:A;
 	ListNode *tempA = A, *headA = A;
 	ListNode *tempB = B, *headB = B, *common = new ListNode(0);
 	ListNode* t = common;
 	while(tempA && tempB){
 		if(tempA->val <= tempB->val){
 			t->next = tempA;
 			tempA = tempA->next;
 			t = t->next;
 		}else{
 			t->next = tempB;
 			tempB = tempB->next;
 			t = t->next;
 		}
 	}
 	if(tempA && !tempB){
 		t->next = tempA;
 	}else if(!tempA && tempB){
 		t->next = tempB;
 	}
 	return common->next;
 }

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
