/*
Time : Fri Oct 20 2017 20:00:59 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/word-ladder-i/
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence 
from start to end, such that:

You must change exactly one character in every transformation
Each 
intermediate word must exist in the dictionary
Example :

Given:

start = "hit"
end = "cog"
dict 
= ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" 
-> "cog",
return its length 5.

Note that we account for the length of the transformation path instead 
of the number of transformation itself.

 Note:
Return 0 if there is no such transformation sequence.
All 
words have the same length.
All words contain only lowercase alphabetic characters.

*/

#include <bits/stdc++.h>

using namespace std;

int Solution::ladderLength(string start, string end, vector<string> &dictv){
    set<string> dict(dictv.begin(),dictv.end());
    struct item{
        string s;
        int len;
    };
    queue<item> q;
    q.push({start,1});
    if(start==end)return 1;
    while(!q.empty()){
        item f = q.front(); q.pop();
        for(int i=0;i<f.s.length();i++){
            char c = f.s[i];
            for(int j=0;j<26;j++){
                f.s[i] = 'a'+j;
                if(dict.find(f.s)!=dict.end()){
                    if(f.s == end)return f.len+1;
                    q.push({f.s,f.len+1});
                    dict.erase(f.s);
                }
            }
            f.s[i] = c;
        }
    }
    return 0;
}

int main(){

	return 0;
}
