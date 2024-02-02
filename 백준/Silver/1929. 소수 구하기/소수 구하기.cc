#include <iostream>
using namespace std;

bool prime[1000001];
int N,M,tmp;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    prime[1] = true;
    for (int i = 2; i < 1000000; ++i) {
        tmp = 2*i;
        while(tmp <= 1000000){
            prime[tmp] = true;
            tmp+=i;
        }
    }

    for (int i = M; i <= N; ++i) {
        if(!prime[i]) cout << i << '\n';
    }


    return 0;
}
