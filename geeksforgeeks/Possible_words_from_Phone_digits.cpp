/*
Time : Sun Oct 08 2017 11:45:04 GMT+0530 (IST)
URL : http://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits/0
Given a keypad as shown in diagram, and a n digit number, list all words which are possible by pressing 
these numbers.



Input:

The first line of input contains an integer T denoting the number of test 
cases.
The first line of each test case is N,N is the number of digits.
The second line of each 
test case contains D[i], N number of digits. 

Output:

Print all possible words from phone digits 
with single space.

Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 5
2 ≤ D[i] ≤ 9

Example:

Input
1
3
2 3 4

Output
adg 
adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg 
cfh cfi
 

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
	    vi v(n);
	    for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<vector<char> > m(8);
        for(int i=0;i<8;i++){
            vector<char> vt(4); m[i]=vt;
        }
        m[0][0]='a'; m[0][1]='b'; m[0][2] = 'c';
        m[1][0]='d'; m[1][1]='e'; m[1][2] = 'f';
        m[2][0]='g'; m[2][1]='h'; m[2][2] = 'i';
        m[3][0]='j'; m[3][1]='k'; m[3][2] = 'l';
        m[4][0]='m'; m[4][1]='n'; m[4][2] = 'o';
        m[5][0]='p'; m[5][1]='q'; m[5][2] = 'r'; m[5][3] = 's';
        m[6][0]='t'; m[6][1]='u'; m[6][2] = 'v';
        m[7][0]='w'; m[7][1]='x'; m[7][2] = 'y'; m[7][3] = 'z';
        vector<string> ans;
        ans.push_back("");
        for(int i=0;i<n;i++){
            int len = v[i]==7||v[i]==9?4:3;
            int pre = ans.size();
            for(int j=0;j<len;j++){
                for(int k=0;k<pre;k++){
                    ans.push_back(ans[k] + m[v[i]-2][j]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i].length()==n)
                cout << ans[i] << " ";
        }
        cout << endl;
	}
	return 0;
}