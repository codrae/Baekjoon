#include <iostream>
#include <cmath>
using namespace std;

int L,H;
string s;
#define r 31
#define M 1234567891

int main() {
    cin >> L;
    cin >> s;
    for (int i = 0; i < L ; ++i) {
        H += ((s[i] - 96)*int(pow(r,i)));
    }

    cout << H%M;

    return 0;
}
