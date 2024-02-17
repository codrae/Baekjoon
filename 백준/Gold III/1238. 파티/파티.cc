#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF (~0U >> 2)


int N,M,X,A,B,T,res;
int dist[1001][1001];
vector<pair<int,int>>edge[20002];

void dijkstra(int start){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,start});
    dist[start][start] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        if(dist[start][cur] < curDist) continue;
        for (int i = 0; i < edge[cur].size(); ++i) {
            int next = edge[cur][i].second;
            int nextDist = edge[cur][i].first;
            if(dist[start][next] > curDist + nextDist){
                dist[start][next] = curDist + nextDist;
                pq.push({curDist+nextDist,next});
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(dist[0],dist[1001],INF);

    cin >> N >> M >> X;

    while(M--){
        cin >> A >> B >> T;
        edge[A].push_back({T,B});
    }

    for (int i = 1; i <= N; ++i) {
        dijkstra(i);
    }

    // 다익스트라 O(ElogV) * V < 플로이드 O(V^3)

    for (int i = 1; i <= N; ++i) {
        res = max(res,dist[i][X] + dist[X][i]);
    }

    cout << res;

    return 0;
}
