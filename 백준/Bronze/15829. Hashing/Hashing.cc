#include <iostream>
#include <cmath>
using namespace std;

unsigned long long L,H,x;
string s;
#define r 31
#define M 1234567891

int main() {
    cin >> L;
    cin >> s;
    for (int i = 0; i < L ; ++i) {
        x = s[i] - 96;
        for (int j = 0; j < i; ++j) {
            x *= r;
            x %= M;
        }
        H += x;
        H %= M;
    }

    cout << H << endl;

    return 0;
}

//https://velog.io/@gidskql6671/%EB%82%98%EB%A8%B8%EC%A7%80Modulo-%EC%97%B0%EC%82%B0-%EB%B6%84%EB%B0%B0%EB%B2%95%EC%B9%99