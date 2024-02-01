#include <iostream>
#include <queue>
using namespace std;

int N,K;
int visited[100002];
queue<int>q;

void bfs(){

    while(!q.empty()){
        if(q.front() == K) return;
        if(q.front() > 0 && visited[q.front()-1] == 0){
            q.push(q.front()-1);
            visited[q.front()-1] = visited[q.front()]+1;
        }
        if(q.front() < 100000 && visited[q.front()+1] == 0){
            q.push(q.front()+1);
            visited[q.front()+1] = visited[q.front()]+1;
        }
        if(q.front() <= 50000 && visited[q.front()*2] == 0){
            q.push(q.front()*2);
            visited[q.front()*2] = visited[q.front()]+1;
        }
        q.pop();
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    q.push(N);
    visited[N] = 0;

    bfs();

    cout << visited[K];

    return 0;
}
