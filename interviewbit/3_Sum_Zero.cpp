/*
Time : Thu Jul 06 2017 13:23:32 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/3-sum-zero/
Given an array S of n integers, are there elements a, b, c in S such that a   b   c = 0? 
Find all 
unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) 
must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. 
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2)

*/

#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> l,vector<int> r){
	if(l[0]<r[0]){
		return true;
	}else if(l[0]==r[0]){
		if(l[1]<r[1])
			return true;
		else{
			return l[2]<r[2];
		}
	}
	return false;
}

vector<vector<int> > threeSum(vector<int> A) {
	sort(A.begin(), A.end());
	vector< vector<int> > toRet;
	int l = A.size();
	for(int i=0;i<l;i++){
		int start = 0,end = l-1;
		int sum = A[i] + A[start==i?++start:start] + A[end==i?--end:end];
		while(start <=  end && end >=0 && start <= l-1){
			if(sum == 0){
				vector<int> v(3);
				v[0] = A[i];v[1] = A[start]; v[2] = A[end];
				sort(v.begin(),v.end());
				toRet.push_back(v);
				start++;
			}
			else if(sum < 0)
				++start==i?++start:start;
			else
				--end==i?--end:end;
			sum = A[i] + A[start] + A[end];
		}
	}
	if(toRet.size() == 0)
		return toRet;
	sort(toRet.begin(), toRet.end(), comp);
	stack<vector<int> > final;
	vector<vector<int> > finalret;
	final.push(toRet[0]);
	for(int i=1;i<toRet.size();i++){
		vector<int> v = final.top();
		if(!(v[0]==toRet[i][0] && v[1]==toRet[i][1] && v[2]==toRet[i][2]))
			final.push(toRet[i]);
	}
	while(!final.empty()){
		vector<int> ans = final.top();
		for(int j=0;j<3;j++){
			cout << ans[j] << " ";
		}
		cout << endl;
		finalret.push_back(final.top());final.pop();
	}
	sort(finalret.begin(),finalret.end(),comp);
	return finalret;
}

int main(){
	int size;
	cin >> size;
	std::vector<int> v(size);
	for(int i=0;i<size;i++){
		cin >> v[i];
	}
	std::vector<vector<int> > ans = threeSum(v);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<3;j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
