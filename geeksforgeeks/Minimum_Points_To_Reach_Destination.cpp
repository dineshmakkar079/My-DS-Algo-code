/*
Time : Fri Oct 20 2017 17:20:28 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0
Given a grid with each cell consisting of positive, negative or no points i.e, zero points. We can 
move across a cell only if we have positive points ( > 0 ). Whenever we pass through a cell, points 
in that cell are added to our overall points. We need to find minimum initial points to reach cell 
(m-1, n-1) from (0, 0) by following these certain set of rules :
 
1.From a cell (i, j) we can move 
to (i 1, j) or (i, j 1).
2.We cannot move from (i, j) if your overall points at (i, j) is <= 0.
3.We 
have to reach at (n-1, m-1) with minimum positive points i.e., > 0.
 
Example:
 
Input: points[m][n] 
= { {-2, -3,   3},  
                        {-5, -10,  1},  
                        {10,  30, 
-5}  
                      };
Output: 7
Explanation:  
7 is the minimum value to reach destination 
with  
positive throughout the path. Below is the path.
 
(0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 
2)
 
We start from (0, 0) with 7, we reach(0, 1)  
with 5, (0, 2) with 2, (1, 2) with 5, (2, 2)
with 
and finally we have 1 point (we needed  
greater than 0 points at the end).

Input:

The first line 
contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line 
contains two integer 'R' and 'C' denoting the number of rows and column of array.  
The second line 
contains the value of the array i.e the grid, in a single line separated by spaces in row major 
order.


Output:

Print the minimum initial points to reach the bottom right most cell in a separate 
line.


Constraints:

1 ≤ T ≤ 30
1 ≤ R,C ≤ 10
-30 ≤ A[R][C] ≤ 30


Example:

Input:
1
3 3
-2 -3 
3 -5 -10 1 10 30 -5
Output:
7

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
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
#define pb push_back;
#define sz(a) (a).size()

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vvi v(n,vi(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            cin >> v[i][j];
        }
        vvi mem(n,vi(m,0));
        mem[n-1][m-1] = v[n-1][m-1]>=0?1:abs(v[n-1][m-1])+1;
        for(int i=n-2;i>=0;i--){
            mem[i][m-1] = max(mem[i+1][m-1] - v[i][m-1],1);
        }
        for(int i=m-2;i>=0;i--){
            mem[n-1][i] = max(mem[n-1][i+1] - v[n-1][i],1);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int mpoe = min(mem[i+1][j], mem[i][j+1]);
                mem[i][j] = max(mpoe - v[i][j],1);
            }
        }
        cout << mem[0][0] << endl;
        for(int i=0;i<n;i++)mem[i].clear(); mem.clear();
    }
    return 0;
}