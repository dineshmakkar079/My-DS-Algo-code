/*
Time : Wed Aug 23 2017 00:16:50 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/palindrome-partitioning/
Given a string s, partition s such that every string of the partition is a palindrome.

Return all 
possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
 
   ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) 
< len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) 
== len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes 
before ["aa", "b"] because len("a") < len("aa")

*/

#include <bits/stdc++.h>

using namespace std;

bool ispalind(string s, int start, int end){
    while(start<=end){
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

vector<vector<string> > partHelper(string str, int start, int end){
    if(start > end){
        vector< vector<string> > ans;return ans;
    }
    if(start==end){
        vector< vector<string> > ans(1); vector<string> v(1); v[0] = str[start];
        ans[0] = v; return ans;
    }
    vector<vector<string> > ans;
    for(int i=start;i<=end;i++){
        if(ispalind(str,start,i)){
            vector< vector<string> > right = partHelper(str,i+1,end);
            int r = right.size();
            string s = str.substr(start,i-start+1);
            for(int j=0;j<r;j++){
                vector<string> v; v.push_back(s);
                for(int k=0;k<right[j].size();k++)
                    v.push_back(right[j][k]);
                ans.push_back(v);
            }
            if(r==0){
                vector<string> v(1); v[0] = s;
                ans.push_back(v);
            }
            right.clear();
        }
    }
    return ans;
}

vector<vector<string> > Solution::partition(string s) {
    int l = s.length();
    int start=0,end=l-1;
    vector< vector<string> > vec;
    vector< vector<string> >& ans = vec;
    ans = partHelper(s,start,end);
    return ans;
}

int main(){

	return 0;
}
