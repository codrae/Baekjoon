#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,cnt;
bool arr[30][30];
int dc[4] = {1,0,-1,0};
int dr[4] = {0,1,0,-1};
vector<int>res;

bool isBlock(int c, int r){
    return (c >= N || r >= N || c < 0 || r < 0 || !arr[c][r]);
}

void dfs(int c, int r){
    if(!isBlock(c,r)) {
        arr[c][r] = 0;
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int nc = c + dc[i];
            int nr = r + dr[i];
            dfs(nc, nr);
        }
    }
}

int main(){
    cin >> N;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        for (int j = 0; j < N; ++j) {
            if(s[j] == '1') arr[i][j] = true;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cnt = 0;
            dfs(i,j);
            if(cnt!= 0) res.push_back(cnt);

        }
    }

    sort(res.begin(),res.end());
    cout << res.size() << '\n';
    for (auto a:res) {
        cout << a << '\n';
    }


    return 0;
}