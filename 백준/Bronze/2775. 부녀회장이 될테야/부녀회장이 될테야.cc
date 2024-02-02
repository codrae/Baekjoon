#include <iostream>
using namespace std;

int T,k,n;
int dp[15][15];

int main() {

    cin >> T;

    for (int i = 1; i < 15; ++i) dp[0][i] = i;

    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    while(T--){
        cin >> k >> n;
        cout << dp[k][n] << '\n';
    }

    return 0;
}
