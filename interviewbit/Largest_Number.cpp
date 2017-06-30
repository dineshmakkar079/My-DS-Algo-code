/*
Time : Thu Jun 29 2017 22:29:56 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/largest-number/
Given a list of non negative integers, arrange them such that they form the largest number.

For
example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be
very large, so you need to return a string instead of an integer.

*/

bool isMoreThan(int lhs,int rhs){
	string l = ""+to_string(lhs);
	string r = ""+to_string(rhs);
	if(l+r < r+l)
		return false;
	return true;
}

bool isMoreThan(int lhs,int rhs){
	string l = ""+to_string(lhs);
	string r = ""+to_string(rhs);
	if(l+r < r+l)
		return false;
	return true;
}

string Solution::largestNumber(const vector<int> &A) {
	vector<int> vec(A.size());
	long long sum= 0;
	for(int i=0;i<A.size();i++){
		vec[i] = A[i];
		sum+=A[i];
	}
	if(sum==0)return "0";
	std::sort(vec.begin(),vec.end(), isMoreThan);
	string toRet = "";
	for(int i=0;i<A.size();i++)
		toRet += ""+to_string(vec[i]);
	return toRet;
}
