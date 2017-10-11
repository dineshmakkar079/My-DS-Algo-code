/*
Time : Mon Oct 09 2017 15:58:06 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/clone-graph/
Clone an undirected graph. Each node in the graph contains a label and 
a list of its neighbors.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

void cloneutil(map<UndirectedGraphNode*, UndirectedGraphNode*>& m, UndirectedGraphNode* n){
    map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it;
    it = m.find(n);
    if(it==m.end()){
        m[n] = new UndirectedGraphNode(n->label);
        for(int i=0;i < (n->neighbors).size(); i++){
            if(m.find((n->neighbors)[i]) == m.end());
                cloneutil(m,(n->neighbors)[i]);
        }
    }
}

void cloneedges(map<UndirectedGraphNode*, UndirectedGraphNode*>& m,UndirectedGraphNode* n,map<UndirectedGraphNode*,bool>& iscloned){
    if(iscloned.find(n)==iscloned.end()){
        for(int i=0;i < (n->neighbors).size(); i++){
            (m[n]->neighbors).push_back(m[(n->neighbors)[i]]);
        }
        iscloned[n] = true;
        for(int i=0;i < (n->neighbors).size(); i++){
            if(iscloned.find((n->neighbors)[i]) == iscloned.end());
                cloneedges(m,(n->neighbors)[i], iscloned);
        }
    }
}
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    UndirectedGraphNode* start = node;
    map<UndirectedGraphNode*, UndirectedGraphNode*> mem;
    map<UndirectedGraphNode*, UndirectedGraphNode*>& m = mem;
    map<UndirectedGraphNode*,bool> isclo;
    map<UndirectedGraphNode*,bool>& iscloned = isclo;
    cloneutil(m, start);
    cloneedges(m, start, iscloned);
    return m[node];
}

int main(){

	return 0;
}
