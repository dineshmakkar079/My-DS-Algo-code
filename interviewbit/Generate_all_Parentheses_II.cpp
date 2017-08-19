/*
Time : Sat Aug 19 2017 18:19:58 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/generate-all-parentheses-ii/
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses 
of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", 
"()()()"
Make sure the returned list of strings are sorted.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    if(A==0) return ans;
    ans.push_back("()");
    if(A==1)
    return ans;
    set<string> se;
    set<string>::iterator it;
    for(int i=1;i<A;i++){
        for(int j=0;j<ans.size();j++)
            se.insert(ans[j]);
        ans.clear();
        it = se.begin();
        while(it!=se.end()){
            ans.push_back(*it);it++;
        }
        int s = ans.size();
        for(int j=0;j<s;j++){
            string str = ans[j];
            for(int k=0;k<str.length();k++){
                if(str[k]=='('){
                	// Insert string "()" in every possible place in older permutations.
                	// Using set to avoid duplicates.
                    string newstr = str.substr(0,k+1) + "()" + str.substr(k+1,str.length()-k-1);
                    ans.push_back(newstr);
                }
            }
            ans[j] = "()" + ans[j];
        }
        se.clear();
    }
    for(int j=0;j<ans.size();j++){
        if(ans[j].length() == 2*A)
            se.insert(ans[j]);
    }
    ans.clear();
    it = se.begin();
    while(it!=se.end()){
        ans.push_back(*it);it++;
    }
    return ans;
}

int main(){

	return 0;
}
