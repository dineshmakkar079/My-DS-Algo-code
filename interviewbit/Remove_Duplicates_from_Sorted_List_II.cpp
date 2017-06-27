/*
Time : Wed Jun 28 2017 00:19:19 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct
numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3,
return 2->3.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* h){
	while(h){
		cout << h->val << " ";
		h = h->next;
	}
	cout << endl;
}

void deletel(ListNode* h){
	if(!h)
		return;
	if(!h->next){
		delete h; return;
	}
	while(h->next){
		ListNode* temp = h->next;
		h->next = h->next->next;
		delete temp;
	}
	delete h;
}

ListNode* deleteDuplicates(ListNode* A);

int main(){
	ListNode* head = new ListNode(0);
	ListNode* temp = head;
	temp->next = new ListNode(1);
	temp->next->next = new ListNode(2);
	temp->next->next->next = new ListNode(5);
	temp->next->next->next->next = new ListNode(2);
	temp->next->next->next->next->next = new ListNode(3);
	temp->next->next->next->next->next->next = new ListNode(4);

	ListNode* af = deleteDuplicates(head);
	print(af);
	deletel(af);
	return 0;
}

ListNode* deleteDuplicates(ListNode* A) {
	if(!A || !A->next)
	   return A;
   ListNode* head = A;
   ListNode* temp = A ;
   while(temp && temp->next){
	   bool isRepeat = false;
	   while(temp && temp->next && temp->val == temp->next->val){
		   isRepeat = true;
		   ListNode* temp2 = temp->next;
		   temp->next = temp2->next;
		   delete temp2;
	   }
	   if(isRepeat && temp){
		   temp->val = -1;
		   temp = temp->next;
	   }else if(!isRepeat && temp){
		   temp = temp->next;
	   }
   }
   temp = head;
   while(temp->next){
	   if(temp->next->val < 0){
		   ListNode* temp2 = temp->next;
		   temp->next = temp->next->next;
		   delete temp2;
	   }else{
		   temp = temp->next;
	   }
   }
   if(head->val < 0){
	   ListNode* toDel = head;
	   head = head->next;
	   delete toDel;
   }
   return head;
}
