/*
Time : Wed Aug 23 2017 22:28:51 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/compare-version-numbers/#
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 
< version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty 
and contain only digits and the . character.
The . character does not represent a decimal point 
and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way 
to version three", it is the fifth second-level revision of the second first-level revision.

Here 
is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/

#include <bits/stdc++.h>

using namespace std;

string zero(int n){
    string ans ="";
    while(n>0){
        ans += "0";n--;
    }
    return ans;
}

int Solution::compareVersion(string A, string B) {
    vector<string> a,b;
    string t="";
    int al = A.length(), bl = B.length();
    for(int i=0;i<al;i++){
        if(A[i]=='.')
            continue;
        while(i<al&&A[i]!='.')
            t+=A[i++];
        a.push_back(t);
        t="";
    }
    for(int i=0;i<bl;i++){
        if(B[i]=='.')
            continue;
        while(i<bl&&B[i]!='.')
            t+=B[i++];
        b.push_back(t);
        t="";
    }
    al = a.size(), bl = b.size();
    if(al < bl){
        for(int i=0;i<bl-al;i++)
            a.push_back("0");
    }else{
        for(int i=0;i<al-bl;i++)
            b.push_back("0");
    }
    al = a.size();
    for(int i=0; i<al  ;i++){
        string a1 = a[i], b1 = b[i];
        int l1 = a1.length(), l2 = b1.length(), diff = abs(l1-l2);
        if(l1 == l2){
            if(a1 < b1)
                return -1;
            else if(a1 > b1)
                return 1;
        }else if(l1 < l2){
            string a2 = zero(diff)+a1;
            if(a2 < b1)
                return -1;
            else if(a2 > b1)
                return 1;
        }else{
            string b2 = zero(diff)+b1;
            if(a1 < b2)
                return -1;
            else if(a1 > b2)
                return 1;
        }
    }
    return 0;
}

int main(){

	return 0;
}
