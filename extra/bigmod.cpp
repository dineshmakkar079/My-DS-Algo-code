#include <bits/stdc++.h>

using namespace std;

int bigmod10(int count){
	long long mult = pow(10,10);
	mult %= 1003;
	int ans = 1;
	for(int i=0;i<count;i++)
		ans = (ans * mult)%1003;
	return ans;
}

int bigmod(vector<int> num){
	long long localnum = 0, ans = 0, count = 0;
	int l = num.size();
	for(int i=0;i<l;i+=10){
		localnum = 0;
		for(int j=i;j<i+10 && j <l; j++){
			localnum += num[j] * pow(10,j%10);
		}
		localnum %= 1003;
		int temp = (localnum * bigmod10(count)%1003)%1003;
		ans = (ans + temp)%1003;
		count++;
	}
	return ans;
}

int main(){
	vector<int> v;
	string str = "6306806999180988698719";
	for(int i=0;i<str.length();i++){
		v.push_back((int)(str[i]) - 48);
	}
	cout << bigmod(v) << endl;
	return 0;
}