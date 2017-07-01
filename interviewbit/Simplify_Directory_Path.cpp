/*
Time : Sat Jul 01 2017 20:09:24 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/simplify-directory-path/
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.

*/
#include <bits/stdc++.h>

using namespace std;

string Solution::simplifyPath(string a) {
    int l = a.length();
	if(l==1)return "/";
	stack<string> dir;
	dir.push("/");
	for(int i=1;i<l;i++){
		string dirname = "";
		while(i<l && a[i]=='/')
		    i++;
		while(i<l && a[i]!='/'){
			dirname += a[i];
			i++;
		}
		if(dirname == ".."){
		    if(!dir.empty())dir.pop();
		}else if(dirname != "." && dirname!=""){
			dir.push(dirname+"/");
		}
	}
	if(dir.empty())return "/";
	string ans = "";
	while(!dir.empty()){
		ans = dir.top()  + ans;
		if(!dir.empty())dir.pop();
	}
	string ret = "";
	for(int i=0;i<ans.length()-1;i++){
	    ret += ans[i] ;
	}
	ret = ret[0] == '/' ? ret : "/" + ret;
	if(ret=="")return "/";
	return ret;
}

int main(){
	string path = "/../";
	cout << simplifyPath(path) << " w";
	return 0;
}
