#include<iostream>
using namespace std;

int N,M,res,cnt;
char board[51][51];
string ans[8];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50 ; ++j) {
            board[i][j] = 'X';
        }
    }

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 8; ++i) {
        if(i % 2 == 0) ans[i] = "BWBWBWBW";
        else ans[i] = "WBWBWBWB";
    }

    res = 2501;

    for (int i = 0; i < N-7; ++i) {
        for (int j = 0; j < M-7; ++j) {
          // 가능한 출발점들에서 다시 칠해야하는 개수 count
          // 시작점이 B인경우와 W인 경우 ??? 8*8 = 64와의차 최솟값
          cnt = 0;
            for (int k = 0; k < 8; ++k) {
                for (int l = 0; l < 8; ++l) {
                    if(board[i+k][j+l] != ans[k][l]) cnt++;
                }
            }
            cnt = min(cnt, 64-cnt);
            if(res > cnt) res = cnt;
        }
    }

    cout << res;


}