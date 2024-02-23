#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;
long long dp[5005];

int solution(int n) {
    int answer = 0;
    if(n%2 != 0) return 0;
    dp[2] = 3;
    dp[4] = 11;
    for(int i = 6; i <= n; i+=2){
        dp[i] = ((4*dp[i-2]%MOD) - (dp[i-4]%MOD) + MOD)%MOD;
    }
    
    return int(dp[n]);
    
}