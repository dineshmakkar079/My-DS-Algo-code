/*
Time : Sun Oct 15 2017 00:39:50 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1/?ref=self
Given a Binary Tree and 2 nodes value n1 and n2  , your task is to find the lowest common ancestor 
of the two nodes . You are required to complete the function LCA . You should not read any input 
from stdin/console. There are multiple test cases. For each test case, this method will be called 
individually.

Input:
The task is to complete the method LCA which takes 3 arguments, root of the Tree 
and two nodes value  n1 and n2 . The struct node has a data part which stores the data, pointer 
to left child and pointer to right child.
There are multiple test cases. For each test case, this 
method will be called individually.

Output:
The function should return the node which is the least 
common ancestor of the two nodes n1 and n2 .

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 
<=Data of a node<= 1000

Example:

Input
1
2
1 2 L 1 3 R
2 3 

Output 
1

In above example there is 
one  test case which represent a tree with 3 nodes and 2 edges where root is 1, left child of 1 
is 2 and right child of 1 is 3.  




Note:The Input/Ouput format and Example given are used for 
system's internal purpose, and should be used by a user for Expected Output only. As it is a function 
problem, hence a user should not read any input from stdin/console. The task is to complete the 
function specified, and not to write the full code.

** For More Input/Output Examples Use 'Expected 
Output' option **

*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
typedef map<Node*,Node*> mpn;

void build(Node* root,mpn& m,Node*& one,Node*& two,Node* parent,int n1,int n2){
    if(root){
        m[root] = parent;
        if(root->data==n1 && !one)one=root;
        if(root->data==n2 && !two)two=root;
        build(root->left,m,one,two,root,n1,n2);
        build(root->right,m,one,two,root,n1,n2);
    }
}

Node * LCA(Node* root ,int n1 ,int n2 )
{
    mpn mp; mpn& m = mp;
    m[root]=NULL;
    Node* o=NULL,*t=NULL; Node*& one=o; Node*& two=t;
    build(root->left,m,one,two,root,n1,n2);
    build(root->right,m,one,two,root,n1,n2);
    stack<Node*> s1,s2;
    while(one){
        s1.push(one); one = m[one];
    }
    while(two){
        s2.push(two); two=m[two];
    }
    Node* ans=root;
    while(!s1.empty() && !s2.empty() && s1.top()==s2.top()){
        if(!s1.empty()){ans = s1.top(); s1.pop();}
        if(!s2.empty()){ans = s2.top(); s2.pop();}
    }
    return ans;
}