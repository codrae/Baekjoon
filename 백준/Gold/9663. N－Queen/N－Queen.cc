#include <iostream>
using namespace std;

int N,res;
bool u[15],ld[30],rd[30];

bool check(int k, int i){
    for (int j = 0; j < k; ++j) {
        if(u[i] || ld[k-i+N-1] || rd[k+i] ) return false;
    }
    return true;
}

void func(int k){
    if(k == N){
        res++;
        return;
    }
    for (int i = 0; i < N; ++i) {
        if(check(k,i)){
            u[i] = ld[k-i+N-1] = rd[k+i] = 1;
            func(k+1);
            u[i] = ld[k-i+N-1] = rd[k+i] = 0;
        }
    }
}

int main() {
    cin >> N;
    func(0);
    cout << res;
    return 0;
}
