#include <iostream>
#include <algorithm>
using namespace std;

#define INF (~0U >> 2)

int l,n,m,r,res,a,b;
int dist[101][101];
int item[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> item[i];
    }

    fill(dist[0],dist[101],INF);

    while(r--){
        cin >> a >> b >> l;
        if(dist[a][b] > l)
        dist[a][b] = dist[b][a] = l;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if(dist[j][i] == INF || dist[i][k] == INF) continue;
                if(dist[j][i] + dist[i][k] < dist[j][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            if(dist[i][j] <= m || i == j)
                sum += item[j];
        }
        res = max(res,sum);
    }

    cout << res;

    return 0;
}
