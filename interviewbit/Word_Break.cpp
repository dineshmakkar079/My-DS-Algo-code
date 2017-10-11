/*
Time : Mon Oct 09 2017 01:04:33 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/word-break/
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated 
sequence of one or more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = 
["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" 
can be segmented as "my interview trainer".

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

#include <bits/stdc++.h>

using namespace std;

short canrep(string& s,unordered_set<string>& dict, vector<short>& mem,int index){
    if(index >= s.size())
        return 1;
    if(mem[index]!=-1)return mem[index];
    string sub="";
    int l = s.size();
    bool result = false;
    for(int i=index;i<l;i++){
        sub.push_back(s[i]);
        if(dict.find(sub)!=dict.end() && !result){
            result |= canrep(s,dict,mem,i+1);
        }
    }
    return mem[index]=result;
}

int Solution::wordBreak(string s, vector<string> &dct) {
    if(s.size()==0)return 1;
    unordered_set<string> dic(dct.begin(),dct.end());
    unordered_set<string>& dict = dic;
    string& in = s;
    int l = s.length();
    vector<short> mem(l,-1);
    return canrep(in,dict,mem,0);
}

int main(){

	return 0;
}
