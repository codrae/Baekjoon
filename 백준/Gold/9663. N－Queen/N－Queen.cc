#include<iostream>
using namespace std;

int N,res;
int queen[15];

bool check(int x, int y){
    for (int i = 0; i < x; ++i) {
                if(i-queen[i] == x-y || i+queen[i] == x+y || y == queen[i]) {
                    return false;
        }
    }
    return true;
}


void solve(int k) {
    if (k == N) {
        res += 1;
        return;
    }
    for (int i = 0; i <N; ++i) {
        if(check(k,i)){
            queen[k] = i;
            // 아래부분에 대해서만 체크
            solve(k+1);
        }
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    solve(0);
    cout << res;

    return 0;
}