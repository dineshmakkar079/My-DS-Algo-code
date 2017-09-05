/*
Time : Tue Sep 05 2017 14:40:09 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0
Given 3 strings X, Y and Z, the task is to find the longest common sub-sequence in all three given 
sequences.

 

Input:

The first line of input contains an integer T denoting the number of test 
cases. Then T test cases follow. The first line of each test case contains integers n, m and k denoting 
the length of strings X, Y and Z respectively.

The second line of each test case contains the three 
strings X, Y and Z. The string consists of only lower case english alphabets.

Output:

Print the 
length of the longest common sub- sequence of the three strings for each test case in a new line.


Constraints:

1<= 
T <=100

1<= N, M, K <=100


Example:

Input:

1

5 8 13

geeks geeksfor geeksforgeeks

Output:

5

**For 
More Examples Use Expected Output**

*/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int lcs(string s1,string s2,string s3){
    int l1 = s1.length(), l2 = s2.length(), l3=s3.length();
    if(!l1||!l2||!l3) return 0;
    int mem[l1+1][l2+1][l3+1];
    for(int i=0;i<l1+1;i++){ 
        for(int j=0;j<l2+1;j++){ 
            for(int k=0;k<l3+1;k++){
                if(!i||!k||!j){
                    mem[i][j][k] = 0;
                    continue;
                }
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
                    mem[i][j][k] = 1 + mem[i-1][j-1][k-1];
                else
                    mem[i][j][k] = max( mem[i-1][j][k] , max(mem[i][j-1][k], mem[i][j][k-1]));
            }
        }   
    }
    return mem[l1][l2][l3];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s1,s2,s3;
	    int l1,l2,l3; cin >> l1 >> l2 >> l3; cin >> s1 >> s2 >> s3;
	    cout << lcs(s1,s2,s3) << endl;
	}
	return 0;
}