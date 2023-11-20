#include<iostream>
using namespace std;

char arr[1002][1002];
int ripeX[1000001];
int ripeY[1000001];
int N,M,res,cnt,yesterday,today;
char trash;
int dx[4]= {0,-1,0,1};
int dy[4]= {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i = 1; i <=N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> arr[i][j];

            if(arr[i][j] == 49) {
                ripeX[cnt] = i;
                ripeY[cnt] = j;
                cnt += 1;
            }
            else if(arr[i][j] == 45) cin >> trash;
        }
    }
    for (int i = 0; i <= N+1; ++i) {
        arr[i][0] = arr[i][M+1] = 45;
    }
    for (int i = 0; i <= M+1; ++i) {
        arr[0][i] = arr[N+1][i] = 45;
    }

    while(1){
        yesterday = today;
        today = cnt;
        for (int i = yesterday; i < today; ++i) {  // 이전에 주위를 검사한 익은 토마토들은 다시 주변을 볼 필요가 없음!!
            //4방향중 0이 존재한다면
            for (int j = 0; j < 4; ++j) {
                if(arr[ripeX[i]+dx[j]][ripeY[i]+dy[j]] == 48){
                    arr[ripeX[i]+dx[j]][ripeY[i]+dy[j]] = 49;
                    ripeX[cnt] = ripeX[i]+dx[j];
                    ripeY[cnt] = ripeY[i]+dy[j];
                    cnt += 1;
                }
            }
        }
        res += 1;
        if(today == cnt) break;  // 새로 익은 토마토가 더이상 존재하지 않을때
    }
    for (int i = 1; i <=N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if(arr[i][j] == 48) res = 0;  // 아직도 익지 못한 토마토가 있다면
        }
    }
    cout << res-1;
}