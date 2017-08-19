/*
Time : Wed Aug 16 2017 22:38:55 GMT+0530 (IST)
URL : https://www.interviewbit.com/problems/4-sum/
Given an array S of n integers, are there elements a, b, c, and d in S such that a   b   c   d = 
target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements 
in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set 
must not contain duplicate quadruplets.
Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 
0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that 
the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] 
OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

*/

#include <bits/stdc++.h>

using namespace std;

bool sortvec(vector<int> l, vector<int> r){
    if(l[0]<r[0])
        return true;
    else if(l[0]==r[0] && l[1]<r[1])
        return true;
    else if(l[0]==r[0] && l[1]==r[1] && l[2]<r[2])
        return true;
    else if(l[0]==r[0] && l[1]==r[1] && l[2]==r[2]&& l[3]<r[3])
        return true;
    else
        return false;
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    map<int, vector<pair<int,int> > > m;
    map<int, vector<pair<int,int> > >::iterator it;
    vector< vector<int> > ans;
    // Build pair wise sum map
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            it = m.find(A[i]+A[j]);
            pair<int,int> p(i,j);
            if(it == m.end()){
                vector< pair<int,int> > v;
                v.push_back(p);
                m[A[i]+A[j]] = v;
            }else{
                (it->second).push_back(p);
            }
        }
    }
    // Check if sum of pair in map and current pair if equal to target or not.
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            it = m.find(B-(A[i]+A[j]));
            pair<int,int> p(i,j);
            if(it!=m.end()){
                vector< pair<int,int> > v = it->second;
                int l = v.size();
                for(int k=0;k<l;k++){
                    pair<int,int> temp = v[k];
                    int o = temp.first, t = temp.second;
                    if(o!=i && t!=j && o!=j && t!=i){ // if one element is repeated with in same qudruple
                        vector<int> pu(4);
                        pu[0] = A[i]; pu[1] = A[j]; pu[2] = A[o]; pu[3] = A[t];
                        sort(pu.begin(), pu.end());
                        ans.push_back(pu);
                    }
                }
            }
        }
    }
    int z = ans.size();
    sort(ans.begin(),ans.end(), sortvec);
    vector< vector<int> > finalans;
    for(int i=0;i<z;i++){
        vector<int> pu(4);
        pu[0] = ans[i][0];pu[1] = ans[i][1];pu[2] = ans[i][2];pu[3] = ans[i][3];
        finalans.push_back(pu);
        while(i<z&&pu[0]==ans[i][0]&&pu[1]==ans[i][1]&&pu[2]==ans[i][2]&&pu[3]==ans[i][3])
            i++;
    }
    return finalans;
}

int main(){

	return 0;
}
