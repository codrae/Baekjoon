#include <iostream>
#include <algorithm>
using namespace std;

int N,res;
int A[50],B[50],C[50];
bool visit[51];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    sort(A,A+N);

    int cnt = 0;
    int minIdx = 0;
    int minValue;
    while(cnt < N){
        minValue = 101;
        for (int i = 0; i < N; ++i) {
            if(B[i] <= minValue && !visit[i]){
                minValue = B[i];
                minIdx = i;
            }
        }
        C[cnt] = minIdx;
        visit[minIdx] = true;
        cnt++;
    }

    for (int i = 0; i < N; ++i) {
        res += A[i]*B[C[N-i-1]];
    }
    cout << res;
    return 0;
}
