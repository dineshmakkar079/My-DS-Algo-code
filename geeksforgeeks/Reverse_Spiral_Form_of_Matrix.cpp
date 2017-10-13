/*
Time : Fri Oct 13 2017 00:27:58 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/reverse-spiral-form-of-matrix/0/?ref=self
Given a matrix as 2D array, print the matrix in reverse spiral form.

Input:
The first line of input 
contains an integer T denoting the number of test cases. Then T test cases follow. Each test case 
contains two integers m and n denoting the size of the matrix(m X n). The next line contains m*n 
space separated integers in row-wise form.

Output:
Print the matrix in reverse spiral form.

Constraints:
1<=T<=10^5
1<=m,n<=10^5
1<=a[m,n]<=10^5

Example:
Input:
1
3 
6
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18

Output:
11 10 9 8 7 13 14 15 16 17 18 12 6 5 4 3 
2 1

** For More Input/Output Examples Use 'Expected Output' option **

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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int m,n;
	    cin >> m>>n;
	    vvi v(m,vi(n));
	    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                cin>> v[i][j];
        }
        int count=1;
        int left = 0, right = n-1, top = 0, down = m-1;
        int final = m*n;
        stack<int> s;
        while(count<=final){
            for(int i=left;i<=right && count<=final;i++){
                s.push(v[top][i]);
                count++;
            }
            top++;
            for(int i=top;i<=down && count<=final;i++){
                s.push(v[i][right]);
                count++;
            }
            right--;
            for(int i=right;i>=left && count<=final;i--){
                s.push(v[down][i]);
                count++;
            }
            down--;
            for(int i=down;i>=top && count<=final;i--){
                s.push(v[i][left]);
                count++;
            }
            left++;
        }
        while(!s.empty()){
            cout << s.top() << " "; s.pop();
        }cout << endl;
	}
	return 0;
}