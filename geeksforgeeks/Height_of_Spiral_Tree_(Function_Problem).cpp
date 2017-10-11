/*
Time : Sat Oct 07 2017 20:24:52 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/height-of-spiral-tree/1
Given a special binary tree of size N, whose leaf nodes are connected to form a circular doubly 
linked list, your task is to complete the function findTreeHeight(), that should return the height 
of the tree.
For Example:

	  1 
	/   \ 
      2      3 
    /  \ 
   4    5
  /   
 6 
In the above 
binary tree, 6, 5 and 3 are leaf nodes and they form a circular doubly linked list. Here, the left 
pointer of leaf node will act as a previous pointer of circular doubly linked list and its right 
pointer will act as next pointer of circular doubly linked list.

Input:
The function a single argument 
as input, the reference pointer to the root of the binary tree.
There will be T test cases and for 
each test case the function will be called separately.

Output:
For each test the function should 
return the height of the spiral binary tree.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
1 
2 L 1 3 R 2 4 L
5
1 2 L 1 3 R 2 4 L 2 5 R 4 6 L
Output:
3
4

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


/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// function should return the height of the binary tree
void findRepeat(set<Node*>& s,Node* root,Node* &leaf){
    if(!root)return;
    if(!root->left && !root->right) leaf = NULL;
    if(s.find(root)!=s.end()){
        if(!leaf){
            leaf = root;
        }
        return;
    }else{
        s.insert(root);
        findRepeat(s,root->left,leaf);
        findRepeat(s,root->right,leaf);
    }
}

int findTreeHeight(Node* root)
{
    if(!root) return 0;
    // Set se to track if any node repeats. As soon as a repeated node is found
    // mark it as any one of the leaf as only leaf will repeat during traversal.
    set<Node*> se;
    Node* le = NULL;
    Node* &leaf = le;
    set<Node*>& s = se;
    findRepeat(s,root,leaf);
    // if only one leaf is present it will not have any other element in circular 
    // doubly link list.
    // Only one leaf will occur in the case when each node has only one child.
    if(!leaf){
        int lt = 0;
        for(Node* n : s )lt++;
        return lt;
    }
    // Set lfs is to maintain all leaves. 
    // All leaves can be found by traversing in the circular link list from leaf 
    // found by function findRepeat;
    set<Node*> lfs;
    lfs.insert(leaf);
    while(1){
        if(lfs.find(leaf->right)!=lfs.end()) break;
        lfs.insert(leaf->right);
        leaf = leaf->right;
    }
    // if lfs contains root remove it from the set of leaves.
    if(lfs.find(root)!=lfs.end())lfs.erase(lfs.find(root));
    // Do level order traversal with condition that if any node is in the set of 
    // leaves its left and right child won't be pushed to the queue.
    queue<Node*> q;
    // levelSep -> Level Separator node
    Node* levelSep = new Node; levelSep->key = INT_MIN; levelSep->left = levelSep->right = NULL;
    set<Node*>::iterator it;
    int level = 1;
    q.push(root);
    q.push(levelSep);
    while(!q.empty()){
        Node* f = q.front();
        q.pop();
        if(q.empty() && f->key == INT_MIN) break;
        
        if(!q.empty() && f->key == INT_MIN){
            q.push(levelSep);
            level++;
        }else if(!q.empty()){
            if(lfs.find(f)==lfs.end()){
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }
    }
    s.clear();
    lfs.clear();
    return level;
}

int main(){

	return 0;
}
