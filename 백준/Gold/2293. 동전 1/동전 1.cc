#include <iostream>
using namespace std;

int N,K;
int coins[101];
int dp[10001];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for (int i = 0; i < N ; ++i) {
        for (int j = coins[i]; j <= K; ++j) {
            // j의 금액을 만드는 경우의 수  += j-coins[i]에 coins[i]를 이용하는 수
          dp[j] += dp[j-coins[i]];
        }
    }

    cout << dp[K];
    return 0;
}
