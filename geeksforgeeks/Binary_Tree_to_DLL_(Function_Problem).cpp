/*
Time : Tue Oct 10 2017 12:20:55 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers 
in nodes are to be used as previous and next pointers respectively in converted DLL. The order of 
nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal 
(left most node in BT) must be head node of the DLL.



Input:
The task is to complete the method 
which takes two arguments, root of Binary Tree and reference to head of DLL.

The struct Node has 
a data part which stores the data, pointer to left child and pointer to right child.
There are multiple 
test cases. For each test case, this method will be called individually.

Output:
The function should 
change reference of head to head of linked list. 

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 
100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:

3 
1 2 
2 1 3 
40 20 60 10 30 
30 10 60 20 40 
There are two test casess.  First case represents a 
tree with 3 nodes and 2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3.   
Second test case represents a tree with 4 edges and 5 nodes. 
The output of complete program is 
forward and backword traversals of modified linked list.

** For More Input/Output Examples Use 
'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Structure for tree and linked list
struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */
// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list

Node* util(Node* root){
    if(!root)return root;
    if(!root->left && !root->right)return root;
    Node* l = util(root->left);
    Node* r = util(root->right);
    Node* temp = l;
    root->right = r;
    if(r) r->left = root;
    if(!l) return root;
    while(l->right){
        l = l->right;
    }
    l->right = root;
    root->left = l;
    return temp; 
}

void BToDLL(Node *root, Node **head_ref)
{
    if(!root){
        *head_ref = NULL;
        return;
    }
    *head_ref = util(root);
}

int main(){

	return 0;
}
