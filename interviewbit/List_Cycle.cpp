/*
Time : Thu Jun 29 2017 19:16:34 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/list-cycle/
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try
solving it using constant additional space.

Example :

Input :

                   ______
            	  |     |
                  \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding
to node 3.

*/

ListNode* Solution::detectCycle(ListNode* A) {
	if(!A || !A->next)
		return NULL;
	if( A->next == A)
		return A;
	ListNode* slow = A;
	ListNode* fast = A->next;
	while(slow && fast && fast->next && slow != fast){
		slow = slow->next;
		fast = fast->next->next;
	}
	if(!fast || !fast->next)return NULL;
	ListNode* cycled = fast;
	fast = fast->next;
	int length = 1;
	while(fast != cycled){
		length++;
		fast = fast->next;
	}
	slow = A;
	fast = A;
	while(length--){
		fast = fast->next;
	}
	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

	return 0;
}
