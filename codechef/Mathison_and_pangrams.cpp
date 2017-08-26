/*
Time : Sat Aug 26 2017 19:40:18 GMT+0530 (IST)
URL : https://www.codechef.com/LTIME51/problems/MATPAN
Read problems statements in mandarin chinese, russian and vietnamese as well.
Mathison recently 
inherited an ancient papyrus that contained some text. Unfortunately, the text was not a PANGRAM. 
Now, Mathison has a particular liking for holoalphabetic strings and the text bothers him. The good 
news is that Mathison can buy letters from the local store in order to turn his text into a pangram.
However, 
each letter has a price and Mathison is not very rich. Can you help Mathison find the cheapest way 
to obtain a pangram?
Input
The first line of the input file will contain one integer, T, representing 
the number of tests.
Each test will be formed from two lines. The first one contains 26 space-separated 
integers, representing the prices of all letters. The second will contain Mathison's initial text 
(a string of N lowercase letters).
Output
The output file will contain T lines, one for each test. 
Each line will contain the answer for the corresponding test.
Constraints and notes
1 ≤ T ≤ 10
1 
≤ N ≤ 50,000
All prices are natural numbers between 1 and 1,000,000 (i.e. 106).
A pangram is a string 
that contains every letter of the Latin alphabet at least once.
All purchased letters are added 
to the end of the string.

Subtaks
Subtask #1 (30 points):
N = 1

 
Subtask #2 (70 points):
Original 
constraints

 
Example
Input:
2
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
abcdefghijklmopqrstuvwz
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
thequickbrownfoxjumpsoverthelazydog

Output:
63
0

Explanation
First 
test
There are three letters missing from the original string: n (price 14), x (price 24), and y 
(price 25).
Therefore the answer is 14   24   25 = 63.

Second test
No letter is missing so there 
is no point in buying something. The answer is 0.

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	vector<int> cost(26);
	vector<bool> present(26);
	while(t--){
		for (int i = 0; i < 26; i++)
		{
			cin >> cost[i];
			present[i]= false;
		}
		string in;
		cin >> in;
		int l = in.length();
		int ans = 0;
		for (int i = 0; i < l; i++)
		{
			present[(int)in[i] - (int)'a'] = true;
		}
		for (int i = 0; i < 26; i++)
		{
			ans += present[i] ? 0 : cost[i];
		}
		cout << ans << endl;
	}
	return 0;
}
