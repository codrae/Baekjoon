#include <iostream>

using namespace std;

int N, x, res, c;
bool check[10002];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 2; i < 1001; ++i) {
        x = i;
        c = x;
        while (c < 1001) {
            c += x;
            check[c] = true;
        }
    }
    check[1] = true;

    while (N--) {
        cin >> x;
        if (!check[x]) res++;
    }

    cout << res;

    return 0;
}
