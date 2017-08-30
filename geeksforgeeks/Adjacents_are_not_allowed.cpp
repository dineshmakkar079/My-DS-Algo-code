/*
Time : Wed Aug 30 2017 13:56:41 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/adjacents-are-not-allowed/0
You have a rectangular grid of dimension 2 x N . you need to find out the maximum sum such that 
no two chosen numbers are adjacent, vertically, diagonally or horizontally, .

Input:

The first 
line of input contains an integer T denoting the number of test cases.
The first line of each test 
case is N,number of columns in a grid.

Next two lines describes the 2*N grid.

Output:

Print the 
output for each test case in a seprate line.

Constraints:

1 <=T<= 100
1 <=N<= 100
0 <=arr[i]<= 
70

Example:

Input:

1
3
1 4 5
2 0 0

Output:

7

**For More Examples Use Expected Output**

*/

#include <bits/stdc++.h>

using namespace std;

int maxsum(vector<vector<int> >& v){
    int n = v[0].size();
    if(n==1) return max(v[0][0], v[1][0]);
    if(n==2) return max(max(v[0][0],v[1][0]), max(v[0][1],v[1][1]));
    int prepreone = v[0][0], prepretwo = v[1][0];
    int preone = v[0][1], pretwo = v[1][1];
    int ans = INT_MIN, tempone, temptwo;
    for(int i=2;i<n;i++){
        int maxi = max(prepreone, prepretwo);
        tempone = v[0][i] + maxi;
        temptwo = v[1][i] + maxi;
        ans = max( ans, max(tempone, temptwo));
        prepreone = max(preone,prepreone);
        prepretwo = max(pretwo,prepretwo);
        preone = max(tempone, preone);
        pretwo = max(temptwo,pretwo);
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<vector<int> > vec(2);
	    vector<vector<int> >& v = vec;
	    for(int i=0;i<2;i++){
            vector<int> t(n);
            for(int j=0;j<n;j++)
                cin >> t[j];
            v[i] = t;
        }
        cout << maxsum(v) << endl;
	}
	return 0;
}