#include <iostream>
#include <cmath>
using namespace std;

int N,K;

int main() {
    cin >> N >> K;
    cout << tgamma(N+1)/(tgamma(N-K+1)* tgamma(K+1)) << endl;
    return 0;
}
