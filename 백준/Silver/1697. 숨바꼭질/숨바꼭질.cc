#include <iostream>
#include <algorithm>
using namespace std;

int c(int p, int d) {
    // 동생이 더 뒤,혹은 같이 있는 경우
    if (p <= d)
        return d - p;
    // 남은 모든 경우에 대해서 수빈이는 동생보다 앞에 있다.
    // p == 1 ? 수빈이는(N) == 0
    else if (p == 1) return 1;
    // p가 홀수인 경우 !! +-1 거리중 최솟값 (재귀)
    // 도착지가 홀수인 경우 *2로는 도착 불가능. 결국 한번은 +-1 중 하나 수행하여야 함.
    else if (p % 2) return 1 + min(c(p - 1, d), c(p + 1, d));
    // p가 짝수인경우 !! 직접 이동하는 경우와 *2 중 최솟값 비교
    else return min(p - d, 1 + c(p / 2, d));
}

int main() {

    int N, K;

    cin >> N >> K;
    cout << c(K,N);
}

/*
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

 */