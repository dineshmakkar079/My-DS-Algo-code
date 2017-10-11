/*
Time : Tue Oct 10 2017 13:56:41 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input:

First 
line consists of T test cases. First line of every test case consists of N, denoting number of elements 
in BST. Second line of every test case consists 3*N elements 2 integers and a character.

Note: 
It is guaranteed than the given input will form BST ,except for 2 nodes that will be wrong.

Output:
Return 
the fixed BST.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
1
4
10 5 L 10 8 R  5 2 L 5 20 
R 
Output:
1

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function
Node is as follows:
struct node
{
    int data;
    struct node *left, *right;
};
*/
typedef struct node node;

void inord(node* root,vector<int>& in){
    if(root){
        inord(root->left,in);
        in.push_back(root->data);
        inord(root->right,in);
    }
}

void inordnew(node* root,vector<int>& in,int& count){
    if(root){
        inordnew(root->left,in,count);
        root->data = in[count++];
        inordnew(root->right,in,count);
    }
}

struct node *correctBST( struct node* root )
{
    if(!root || (!root->left && !root->right))return root;
    vector<int> v; vector<int>& in = v;
    inord(root,in);
    sort(in.begin(),in.end());
    int c=0; int& count=c;
    inordnew(root,in,count);
    return root;
}

int main(){

	return 0;
}
