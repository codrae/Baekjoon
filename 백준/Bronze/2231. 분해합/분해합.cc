#include <iostream>
using namespace std;

int N,res,sum;
string s;

int main() {
    cin >> N;

    while(res < N){
        res++;
        s = to_string(res);
        sum = 0;

        for (int i = 0; i < s.length(); ++i) {
            sum += s[i] - '0';
        }

        if(res + sum == N) break;
    }

    if(res + sum != N) cout << 0;
    else cout << res;

    return 0;
}
