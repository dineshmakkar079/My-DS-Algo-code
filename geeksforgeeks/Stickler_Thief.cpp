/*
Time : Tue Aug 29 2017 13:26:43 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/stickler-theif/0
Stickler is a thief and wants to loot money from a society of n houses placed in a line. He is a 
weird person and follows a rule while looting the houses and according to the rule he will never 
loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief 
knows which house has what amount of money but is unable to find the maximum amount he can end up 
with. He asks for your help to find the maximum money he can get if he strictly follows the rule. 
Each house has a[i] amount of money present in it.

Input:
The first line of input contains an integer 
T denoting the number of test cases. Each test case contains an integer n which denotes the number 
of elements in the array a[]. Next line contains space separated n elements in the array a[].

Output:
Print 
an integer which denotes the maximum amount he can take home.

Constraints:
1<=T<=200
1<=n<=1000
1<=a[i]<=10000

Example:
Input:
2
6
5 
5 10 100 10 5
3
1 2 3

Output:
110
4

**For More Examples Use Expected Output**

*/


#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> v){
    int n = v.size();
    int prepre, pre;
    prepre = v[0]; if(n==1) return v[0];
    pre = v[1] > v[0] ? v[1] : v[0]; if(n==2) return pre;
    int curr;
    for(int i=2;i<n;i++){
        curr = max(prepre + v[i] ,pre);
        prepre = pre;
        pre = curr;
    }
    return curr;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        cout << solve(v) << endl;
	}
	return 0;
}