#include <iostream>
#include <vector>
using namespace std;

int N,M,res,n;
vector<int>v;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    v = vector<int>(N);

    for (int i = 0; i < N; ++i) {
        //vector index에 cin 불가
        cin >> n;
        v[i] = n;
    }

    for (int i = 0; i < N-2; ++i) {
        for (int j = i+1; j < N-1; ++j) {
            for (int k = j+1; k < N; ++k) {
                if(v[i]+v[j]+v[k] <= M && v[i] + v[j] + v[k] > res)
                    res = v[i]+v[j]+v[k];
            }
        }
    }

    cout << res;

    return 0;
}
