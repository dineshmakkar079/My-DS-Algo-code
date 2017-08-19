/*
Time : Wed Aug 16 2017 22:39:34 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/anagrams/
Given an array of strings, return all groups of strings that are anagrams. Represent a group by 
a list of integers representing the index in the original list. Look at the sample case for clarification.

 
Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', 
formed from 'rasp' 
 Note: All inputs will be in lower-case. 
Example :

Input : cat dog god tca
Output 
: [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 
dog and god are 
another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element 
has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering 
of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before 
A[j] if i < j.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string, vector<int> > m;
    map<string, vector<int> > :: iterator it;
    int n = A.size();
    for(int i=0;i<n;i++){
        string s = A[i];
        sort(s.begin(),s.end());
        it = m.find(s);
        if(it == m.end()){
            vector<int> v;
            v.push_back(i+1);
            m[s] = v;
            // cout << "s = " << s << " v = " << i+1;
        }else{
            (it->second).push_back(i+1);
            // cout << " v = " << i+1;
        }
    }
    vector< vector<int> > ret;
    for(int i=0;i<n;i++){
        string s = A[i];
        sort(s.begin(),s.end());
        it = m.find(s);
        if(it == m.end()){
            continue;
        }else{
            ret.push_back(it->second);
            m.erase(it);
        }
    }
    return ret;
}

int main(){

	return 0;
}
