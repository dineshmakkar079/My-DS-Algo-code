/*
Time : Sun Sep 10 2017 20:56:03 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
Trie is an efficient information retrieval data structure. Use this data structure to store Strings 
and search strings. Your task is to use TRIE data structure and search the given string A. If found 
print 1 else 0.

Input:
The first line of input contains a single integer T denoting the number 
of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each 
test case consist of a integer N, denoting the number of element in a Trie to be stored.
Second 
line of each test case consists of N space separated strings denoting the elements to be stored 
in the trie.
Third line of each test case consists of a String A to be searched in the stored elements.

Output:
Print 
the respective output in the respective line.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
1
8
the 
a there answer any by bye their
the
Output:
1

** For More Input/Output Examples Use 'Expected Output' 
option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ip pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vl vector<long long>
#define vvl vector<vl>
#define vr vector
#define init(a, n, v) for (int schz=0;schz<n;schz++) a[schz]=v;

#define ct(a) cout << a << "\n";
#define ct2(a,b) cout << a << " " << b << "\n";
#define ct3(a,b,c) cout << a << " " << b << " " << c << "\n";

using namespace std;

struct trienode{
    struct trienode *children[26];
    bool isEndOfWord;
};
typedef struct trienode tnode;

void insert(tnode* root,string s){
    int l = s.length();
    tnode* temp = root,*temp2=NULL;
    for(int i=0;i<l;i++){
        if(temp->children[s[i]-'a']==NULL){
            temp2 = new tnode;
            for(int j=0;j<26;j++)temp2->children[j] = NULL;
            temp2->isEndOfWord = false;
            temp->children[s[i]-'a'] = temp2;
            temp = temp2;
        }else{
            temp = temp->children[s[i]-'a'];
        }
        if(i==l-1)
            temp->isEndOfWord = true;
    }
}

bool search(tnode* root,string s){
    int l=s.length();
    tnode* temp = root;
    for(int i=0;i<l;i++){
        if(temp->children[s[i]-'a']==NULL)return false;
        temp = temp->children[s[i]-'a'];
    }
    return temp&&temp->isEndOfWord;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    tnode* root = new tnode;
	    for(int i=0;i<26;i++)root->children[i]=NULL;
	    root->isEndOfWord=false;
	    string s;
	    for(int i=0;i<n;i++){
	        cin >> s;
	        insert(root,s);
        }
        cin >> s;
        cout << search(root,s) << endl;
	}
	return 0;
}