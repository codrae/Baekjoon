#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int K,N,x,res,n;
vector<int>ls;

void updaten(long m){
    n = 0;
    for (long unsigned int i = 0; i < ls.size(); ++i) {
        n += ls[i]/m;
    }
}

void binary_search(long st, long dt){
    if(st > dt) return;
    long m = (st+dt)/2;
    updaten(m);

    if(n >= N){
        if(res < m) res = m;
        binary_search(m+1,dt);
    }
    else{
        binary_search(st,m-1);
    }

}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        cin >> x;
        ls.push_back(x);
    }
    binary_search(1,INT_MAX);

    cout << res;
    return 0;
}
