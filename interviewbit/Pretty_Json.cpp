/*
Time : Wed Aug 30 2017 20:29:21 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/pretty-json/
Pretty print a json object using proper indentation.

Every inner brace should increase one indentation 
to the following lines.
Every close brace should decrease one indentation to the same line and the 
following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output 
: 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
       
     I:"J"
        } 
    }     
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output 
: 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
         
   1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume 
for this problem that space characters can be done away with.

Your solution should return a list 
of strings, where each entry corresponds to a single line. The strings should not have “\n” character 
in them.

*/

#include <bits/stdc++.h>

using namespace std;

string gettab(int n,std::vector<string>& mem){
	if(n==0) return "";
	if(mem[n].length()!=0) return mem[n];
	string s = gettab(n-1,mem) + "\t";
	mem[n] = s;
	return s;
}

vector<string> justify(string s){
	int l = s.length();
	int currindent = 0;
	string ans = "";
	int maxindent = 0;
	vector<string> ansvec;
	for(int i=0;i<l;i++) if(s[i]=='{' || s[i]=='[') maxindent++;
	std::vector<string> m(maxindent+1);
	std::vector<string>& mem = m;
	for(int i=0;i<maxindent+1;i++) mem[i] = "";
	for(int i=0;i<l;i++){
		if(s[i]=='{' || s[i]=='['){
			ans += s[i]=='{' ? "{" : "[";
			currindent++;
			ans += "\n" + gettab(currindent,mem);
		}else if(s[i]==',' || s[i]==':'){
			ans += s[i]==','?",":":";
			if(s[i]==':' &&  s[i+1]!='{' && s[i+1]!='['){
				continue; 
			}
			ans+="\n" + gettab(currindent,mem);
		}else if(s[i]=='}' || s[i]==']'){
			currindent--;
			ans += "\n" + gettab(currindent,mem);
			ans += s[i]=='}' ? "}" : "]";
		}else{
			ans += s[i];
		}
	}
	int l2 = ans.length();
	for(int i=0;i<l2;i++){
	    string t = "";
	    while(ans[i]!='\n' && i<l2) t+=ans[i++];
	    ansvec.push_back(t);
	}
	return ansvec;
}

vector<string> Solution::prettyJSON(string s) {
    return justify(s);
}

int main(){

	return 0;
}
