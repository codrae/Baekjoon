#include <iostream>
using namespace std;

int N,M;
int arr[10];

void func(int k){
    if(k == M){
        for (int i = 0; i < M; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if(k > 0 && arr[k-1] > i) continue;
        arr[k] = i;
        func(k+1);
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
