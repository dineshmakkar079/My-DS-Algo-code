/*
Time : Fri Oct 20 2017 17:19:05 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/word-break-ii/
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each 
word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict 
= ["cat", "cats", "and", "sand", "dog"].
A solution is

[
  "cat sand dog", 
  "cats and dog"
]
Make 
sure the strings are sorted in your result.

*/

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define vs vr<string>
#define ss set<string>

void print(ss& dict,string& s,string curr,int index,int end,vr<string>& ans){
    if(index >= end){
        curr = curr.substr(0,curr.length()-1);
        ans.push_back(curr);
        return;
    }
    for(int i=index;i<end;i++){
        string t = s.substr(index, i-index+1);
        ss::iterator it = dict.find(t);
        if(it!=dict.end()){
            print(dict,s,curr + t + " ",i+1,end,ans);
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    ss dict(B.begin(),B.end());
    vector<string> ans;
    print(dict,A,"",0,A.length(),ans);
    return ans;
}

int main(){

	return 0;
}
