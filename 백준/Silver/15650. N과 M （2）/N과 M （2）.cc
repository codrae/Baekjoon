#include <iostream>
using namespace std;

int N,M;
int arr[10];
bool visit[10];


void func(int k){
    if(k == M){
        for (int i = 0; i < M; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i) {

        if(!visit[i]){
            if(k > 0 && arr[k-1] > i) continue;
            visit[i] = true;
            arr[k] = i;
            func(k+1);
            visit[i] = false;

            }
        }
    }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    func(0);

    return 0;
}
