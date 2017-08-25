#include <bits/stdc++.h>

using namespace std;

bool canplace(std::vector<string>& curr,int row,int col,char c){
    for (int i = 0; i < 9; ++i){
        bool one = (c==curr[i][col]) ;//&& i!=row;
        bool two = (c==curr[row][i]) ;//&& i!=col;
        bool three = (c==curr[(row/3)*3 + i/3][(col/3)*3 + i%3]) ;//&& (row!=((row/3)*3 + i/3)) && col!= ((col/3)*3 + i%3);
        if(one || two || three)
            return false;
    }return true;
}

void prints(vector<string>& curr){
    int n = curr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << curr[i][j] ;
        }
        cout << endl;
    }
}

void input(vector<string>& v){
    v[0] = "53..7...."; // 534678912
    v[1] = "6..195..."; // 672195348
    v[2] = ".98....6."; // 198342567
    v[3] = "8...6...3"; // 859761423
    v[4] = "4..8.3..1"; // 426853791
    v[5] = "7...2...6"; // 713924856
    v[6] = ".6....28."; // 961537284
    v[7] = "...419..5"; // 287419635
    v[8] = "....8..79"; // 345286179
}

void solve(vector<string>& curr,int starti,int startj,vector<string>& ans,int count){
    if(count == 81){
        ans = curr;
        return;
    }
    for(int i=0;i<starti&&i<9;i++){
        for(int j=0;j<9;j++){
            if(curr[i][j]=='.')
                return;
        }
    }
    for(int j=0;j<startj&&j<9;j++){
        if(curr[starti][j]=='.') return;
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(curr[i][j]=='.'){
                bool placeone = false;
                for(char c='1';c<='9';c++){
                    if(canplace(curr,i,j,c)){
                        placeone = true;
                        curr[i][j] = c;
                        solve(curr,i,j,ans,count+1);
                        curr[i][j] = '.';
                    }
                }
                if(!placeone) return;
            }
        }
    }
}

int main(){
    std::vector<string> in(9);
    std::vector<string> two(9);
    std::vector<string>& vs = in;
    input(vs);
    int f = 0; int& fixed = f;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(vs[i][j]!='.')
                fixed++;
        }
    }
    vector<string>& ans = two;
    solve(vs,0,0,ans,fixed);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}