#include <iostream>
using namespace std;

int N,M,res,sum,subM;
int arr[510][510];

pair<int,int>c1[7] = {make_pair(0,1), make_pair(0,-1)
,make_pair(1,1), make_pair(1,-1)
,make_pair(2,1), make_pair(2,-1)
        ,make_pair(3,0)};

//c2 : c1 first,second swap

void find_max(int x, int y){
    // case 1  --- + 1
    sum = arr[x][y] + arr[x+1][y] + arr[x+2][y];
    subM = 0;
    for (int i = 0; i < 7; ++i) {
        subM = max(subM,arr[x+c1[i].first][y+c1[i].second]);
    }
    res = max(res,sum+subM);
    // case 2  | + 1
    sum = arr[x][y] + arr[x][y+1] + arr[x][y+2];
    subM = 0;
    for (int i = 0; i < 7; ++i) {
        subM = max(subM,arr[x+c1[i].second][y+c1[i].first]);
    }
    res = max(res,sum+subM);
    // case 3 -- + 2
    sum = arr[x][y] + arr[x+1][y];
    subM = 0;
    subM = max(subM,arr[x][y+1]+arr[x+1][y-1]);
    subM = max(subM,arr[x][y-1]+max(arr[x+1][y+1],arr[x+1][y-1]));
    subM = max(subM,arr[x+1][y-1]+arr[x+2][y-1]);
    subM = max(subM,arr[x+1][y+1]+arr[x+2][y+1]);
    res = max(res,sum+subM);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
             // 검사
            find_max(i,j);
            }
        }

    cout << res;

    return 0;
}
