/*
Time : Tue Aug 22 2017 23:58:31 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/merge-k-sorted-lists/
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

*/

#include <bits/stdc++.h>

using namespace std;

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first>n2.first;
    }
};
 
ListNode* Solution::mergeKLists(vector<ListNode*> &v) {
    int n = v.size();
	int count = 0;
	for(int i=0;i<n;i++){ 
		ListNode* temp = v[i];
		while(temp){count++; temp = temp->next;}
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >, CompareDist > q;
	std::vector<ListNode*> index(n);
	for(int i=0;i<n;i++){
		pair<int,int> p(v[i]->val, i);
		q.push(p);
		index[i] = v[i];
	}
	int currcount = 0;
	ListNode* ans = new ListNode(-1);
	ListNode* temp = ans;
	while(currcount < count){
		if(!q.empty()){
			pair<int,int> top = q.top(); q.pop();
			temp->next = new ListNode(top.first); temp = temp->next;
			if(index[top.second]->next){
				index[top.second] = index[top.second]->next;
				pair<int,int> p(index[top.second]->val, top.second);
				q.push(p);
			}
			currcount++;
		}
	}
	return ans->next;
}

int main(){

	return 0;
}
