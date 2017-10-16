/*
Time : Sun Oct 15 2017 01:07:01 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/?ref=self
Given a binary tree and two node values your task is to find the minimum distance between them.

Input:
The 
task is to complete the fuction findDist which takes 3 argument, the  root of the  Binary Tree and 
two node values a and b .
There are multiple test cases. For each test case, this method will be 
called individually.

Output:
The function should return min distance between two node values .

Constraints:
1 
<=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input
1
2
1 2 L 1 3 R
2 3 

Output
2

In 
above example there is one  test case which represent a tree with 3 nodes and 2 edges where root 
is 1, left child of 1 is 2 and right child of 1 is 3.  



Note:The Input/Ouput format and Example 
given are used for system's internal purpose, and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. The task 
is to complete the function specified, and not to write the full code.

** For More Input/Output 
Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>

using namespace std;

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
/* Should return minimum distance between a and b 
   in a tree with given root*/
   
typedef map<Node*,Node*> mpn;

void build(Node* root,mpn& m,Node*& one,Node*& two,Node* parent,int n1,int n2){
    if(root){
        m[root] = parent;
        if(root->data==n1)one=root;
        if(root->data==n2)two=root;
        build(root->left,m,one,two,root,n1,n2);
        build(root->right,m,one,two,root,n1,n2);
    }
}

Node *LCA(Node* root ,int n1 ,int n2,mpn& m,Node*& one, Node*& two)
{
    if(root->data==n1)one=root;
    if(root->data==n2)two=root;
    build(root->left,m,one,two,root,n1,n2);
    build(root->right,m,one,two,root,n1,n2);
    stack<Node*> s1,s2;
    Node* o=one,*t=two;
    while(o){
        s1.push(o); o = m[o];
    }
    while(t){
        s2.push(t); t=m[t];
    }
    Node* ans=root;
    while(!s1.empty() && !s2.empty() && s1.top()==s2.top()){
        if(!s1.empty()){ans = s1.top(); s1.pop();}
        if(!s2.empty()){ans = s2.top(); s2.pop();}
    }
    return ans;
}   

int findDist(Node* root, int a, int b)
{
    mpn mp; mpn& m = mp;
    m[root]=NULL;
    Node* o=NULL,*t=NULL; Node*& one=o; Node*& two=t;
    Node* lc = LCA(root,a,b,m,one,two);
    int distlc = 0, da=0,db=0;
    while(lc){
        distlc++; lc=m[lc];
    }
    while(one){
        da++; one=m[one];
    }
    while(two){
        db++; two=m[two];
    }
    return (da + db - 2* distlc);
}

int main(){

	return 0;
}
