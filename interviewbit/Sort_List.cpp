    /*
Time : Thu Jun 29 2017 15:17:47 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/sort-list/
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
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

ListNode* Solution::sortList(ListNode* A) {
	if(!A || !A->next)
		return A;
	ListNode* slow = A, *fast = A;
	while(fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* secondHead =  slow->next;
	slow->next = NULL;
	ListNode* firstHead = sortList(A);
	secondHead = sortList(secondHead);
	return mergeTwoLists(firstHead, secondHead);
}


#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
