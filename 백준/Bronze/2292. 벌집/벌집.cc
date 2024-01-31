#include <iostream>
using namespace std;

int N,res;

int main() {
    cin >> N;

    // 1, 7, 19, 37, 61 (1, 6, 12, 18, 24)
    res = 1;
    N--;
    while(N > 0){
        N -= (res * 6);
        res ++;
    }

    cout << res;

    return 0;
}
