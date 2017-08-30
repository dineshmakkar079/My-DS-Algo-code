/*
Time : Wed Aug 30 2017 14:31:58 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/longest-common-substring/0
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input 
: X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is 
of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" 
and is of
length 4.

Input : X = "zxabcdezy", y = "yzabcdezx"
Output : 6
The longest common substring 
is "abcdez" and is of
length 6.
 

Input:
First line of the input contains no of test cases  T,the 
T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size 
of string X and Y respectively
The next two lines contains the 2 string X and Y.


Output:
For each 
test case print the length of longest  common substring of the two strings .


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100


Example:
Input:
2
6 
6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

 

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

int lcs(string s1,string s2){
    int l1 = s1.length(), l2 = s2.length();
    if(l1==0||l2==0) return 0;
    vector<vector<int> > m(l1);
    vector<vector<int> >& mem = m;
    for(int i=0;i<l1;i++){
        vector<int> v(l2);
        for(int j=0;j<l2;j++)
            v[j] = -1;
        mem[i] = v;
    }
    int ans = INT_MIN;
    for(int i=0;i<l1;i++){
        mem[i][0] = (s1[i]==s2[0])?1:0;
        ans = max(ans, mem[i][0]);
    }
    for(int i=0;i<l2;i++){
        mem[0][i] = (s1[0]==s2[i])?1:0;
        ans = max(ans, mem[0][i]);
    }
    for(int i=1;i<l1;i++){
        for(int j=1;j<l2;j++){
            mem[i][j] = s1[i] == s2[j] ? 1 + mem[i-1][j-1] : 0;
            ans = max(ans, mem[i][j]);
        }
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int m,n;
	    cin >> m >> n;
	    string s1,s2;
	    cin >> s1 >> s2;
	    cout << lcs(s1,s2) << endl;
	}
	return 0;
}