/*
Time : Tue Oct 10 2017 23:09:43 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/find-length-of-loop/1
Given a linked list of size N, your task is to complete the function countNodesinLoop() that checks 
whether a given Linked List contains loop or not and if loop is present then return the count of 
nodes in loop or else return 0.

For Example:
Size of the loop in the below linked list is 4.

Input:
The 
function takes a single argument as input, the reference pointer to the head of the linked list.
There 
will be T, test cases and for each test case the function will be called separately.

Output:
For 
each test case the function must return the size of the loop in the linked list or else 0.

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
2
10
25 
14 19 33 10 21 39 90 58 45
4
2
1 0
1
Output:
6
1

Note:The Input/Ouput format and Example given 
are used for system's internal purpose, and should be used by a user for Expected Output only. As 
it is a function problem, hence a user should not read any input from stdin/console. The task is 
to complete the function specified, and not to write the full code.

** For More Input/Output Examples 
Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the linked list is as
struct Node
{
	int data;
	struct Node* next;
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
typedef struct Node node;

int countNodesinLoop(struct Node *head)
{
    if(!head)return 0;
    node* slow=head, *fast=head->next;
    while(fast && fast!=slow){
        slow = slow->next;
        if(fast->next) fast = fast->next->next;
    }
    if(!fast || !fast->next)
        return 0;
    int c = 1;
    slow = fast->next;
    while(slow && slow!=fast){
        slow=slow->next;
        c++;
    }
    return c;
}

int main(){

	return 0;
}
