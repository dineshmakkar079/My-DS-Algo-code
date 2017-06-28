/*
Time : Wed Jun 28 2017 19:59:05 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/add-two-numbers-as-lists/
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked
list.

Input: (2 -> 4 -> 3)   (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342   465 = 807
Make sure there
are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though
the value is still 807.

*/


//  Definition for singly-linked list.


 #include <bits/stdc++.h>

 using namespace std;

 struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
	ListNode *tempA = A, *tempB = B, *temp = NULL;
	ListNode* toRet = new ListNode(-1);
	temp = toRet;
	int carry = 0,sum = 0;
	while(tempA || tempB){
		int num1 = tempA ? tempA->val : 0;
		int num2 = tempB ? tempB->val : 0;
		sum = num1 + num2 + carry;
		int dig = sum%10;
		carry = sum / 10;
		cout << "dig = " << dig << " carry = " << carry << endl;
		temp->next = new ListNode(dig);
		temp = temp->next;
		if(tempA) tempA = tempA->next;
		if(tempB) tempB = tempB->next;
	}
	while(carry){
		int dig = carry%10;
		temp->next = new ListNode(dig);
		carry = carry / 10;
	}
	ListNode* toDel = toRet;
	toRet = toRet->next;
	delete toDel;
	return toRet;
}

int main(){
	ListNode* A = new ListNode(9);
	A->next = new ListNode(9);
	A->next->next = new ListNode(9);
	ListNode* B = new ListNode(1);
	ListNode* ans = addTwoNumbers(A,B);
	while(ans){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}
