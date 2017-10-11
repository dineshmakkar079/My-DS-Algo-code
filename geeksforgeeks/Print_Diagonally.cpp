/*
Time : Tue Oct 10 2017 13:07:48 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/print-diagonally/0
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

For 
Example:
If the matrix is    

1 2 3
4 5 6
7 8 9
The output should Return the following :

[ 
  
[1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
i.e print the elements of array diagonally.

Note: 
The input array given is in single line and you have to output the answer in one line only.

 

Input:

The 
first line contains an integer T, depicting total number of test cases. 
Then following T lines 
contains an integer N depicting the size of square matrix and next line followed by the value of 
array.


Output:

Print the elements of matrix diagonally in separate line.


Constraints:

1 ≤ 
T ≤ 30
1 ≤ N ≤ 20
0 ≤ A[i][j] ≤ 9


Example:

Input:
2
2
1 2 3 4
3
1 2 3 4 5 6 7 8 9
Output:
1 2 
3 4
1 2 4 3 5 7 6 8 9
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
	    int n;
	    cin >> n;
	    vvi v(n);
	    for(int i=0;i<n;i++){
            vi v1(n);
            v[i]=v1;
            for(int j=0;j<n;j++)
                cin >> v[i][j];
        }
        for(int j=0;j<n;j++){
            for(int k=j;k>=0;k--){
                cout << v[j-k][k] << " ";
            }
        }
        for(int i=1;i<n;i++){
            for(int k=i;k<n;k++){
                cout << v[k][n-k+i-1] << " ";
            }
        }
        cout << endl;
	}
	return 0;
}