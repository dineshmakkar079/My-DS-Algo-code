/*
Time : Tue Oct 10 2017 23:54:55 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1
Given Pointer/Reference to the head of a doubly linked list, task is to Sort the given doubly linked 
list using Merge Sort.

You need to complete the function splitList() and merge(), which will be 
called by the function mergeSort().

struct node *mergeSort(struct node *head)
{
    if (!head || 
!head->next)
        return head;
    struct node *second = splitList(head);
    head = mergeSort(head);
   
 second = mergeSort(second);
    return merge(head, second);
}
The spliList() function takes a single input, 
the pointer reference to the head of the doubly linked list. The function return pointers reference 
to the head of the second list. The function splits the linked list in to two halves just like in 
standard merge sort. As the name suggests function merge will merge two doubly linked lists, as 
in standard merge sort.

Input:
There are be multiple test cases, for each test case function mergeSort() 
will be called separately. The only input to the function is the pointer/reference to the head of 
the doubly linked list.

Output:
For each test, print the sorted doubly linked list in both order 
i.e. in non-decreasing and non-increasing order.

Constraints:
1<=T<=100
1<=N<=105

Example:
Input:
2
8
7 
3 5 2 6 4 1 8
5
9 15 0 -1 0
Ouput:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
-1 0 0 9 15
15 9 0 0 -1

Note:The 
Input/Output format and Example given are used for system's internal purpose, and should be used 
by a user for Expected Output only. As it is a function problem, hence a user should not read any 
input from stdin/console. The task is to complete the function specified, and not to write the full 
code.

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the list is as
struct node
{
	int data;
	struct node *next, *prev;
};
*/
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
typedef struct node node;

struct node *splitList(struct node *head)
{
    if(!head || !head->next) return NULL;
    node* slow = head, *fast = head;
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        if(fast->next) fast = fast->next->next;
    }
    if(slow->next) slow->next->prev = NULL;
    node* ret = slow->next;
    slow->next = NULL;
    return ret;
}
// Function to merge two DLLs
struct node *merge(struct node *first, struct node *second)
{
    node* temp1 = first, *temp2 = second;
    if(!temp1 || !temp2) return temp1?temp1:temp2;
    
    node* ret = temp1->data < temp2->data ? temp1: temp2;
    node* start = new node;
    node* temp = start;
    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            temp->next = temp1;
            temp1->prev = temp;
            temp1 = temp1->next;
            temp = temp->next;
        }else{
            temp->next = temp2;
            temp2->prev = temp;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    if(temp1){
        temp->next = temp1;
        temp1->prev = temp;
    }else if(temp2){
        temp->next = temp2;
        temp2->prev = temp;
    }
    ret->prev = NULL;
    return ret;
}

int main(){

	return 0;
}
