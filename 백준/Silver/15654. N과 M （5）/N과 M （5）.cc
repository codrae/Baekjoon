#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,x;
vector<int>v;
vector<int>res;
bool visit[10];  // 중복제거 역할

void func(int k, int st){
    if(k == M){
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; ++i) {
        if(!visit[i]) {
            res.push_back(v[i]);
            visit[i] = true;
            func(k + 1, st + 1);
            visit[i] = false;
            res.pop_back();
        }
    }

}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    func(0,0);

    return 0;
}
