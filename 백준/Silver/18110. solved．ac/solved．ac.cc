#include <iostream>
#include <cmath>
using namespace std;

double res,n;
int x,cut,di;
double arr[31];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if(n == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
        arr[x] += 1;
    }

    cut = round(n * 15 / 100);


    while (cut--) {
        for (int i = 1; i < 31; ++i) {
            if (arr[i] != 0) {
                arr[i]--;
                break;
            }
        }
    }

    cut = round(n * 15 / 100);
    n -= cut;
    di = n - cut;

    while (cut--) {
        for (int i = 30; i > 0; --i) {
            if (arr[i] != 0) {
                arr[i]--;
                break;
            }
        }
    }


    for (int i = 1; i < 31; ++i) {
        res += arr[i] * i;
    }
    res /= di;
    cout << round(res);
}
