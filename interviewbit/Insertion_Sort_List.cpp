/*
Time : Thu Jun 29 2017 14:51:21 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/insertion-sort-list/
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion
Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* inserty(ListNode* head, ListNode* toIns){
 	if(!head)
 		return toIns;
 	ListNode* temp = head;
 	if(head->val >= toIns->val){
 		toIns->next = head;
 		head = toIns;
 		return head;
 	}
 	while(temp->next && temp->next->val < toIns->val){
 		temp = temp->next;
 	}
 	toIns->next = temp->next;
 	temp->next = toIns;
 	return head;
 }

ListNode* Solution::insertionSortList(ListNode* A) {
 	if(!A || !A->next)
 		return A;
 	ListNode* head = A,*temp = head;
 	while(temp->next){
 		ListNode* toIns = temp->next;
 		if(temp->val <= toIns->val){
 			temp = temp->next;
 			continue;
 		}
 		temp->next = temp->next->next;
 		head = inserty(head, toIns);
 	}
 	return head;
 }


#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
