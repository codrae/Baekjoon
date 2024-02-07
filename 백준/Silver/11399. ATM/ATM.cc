#include <iostream>
#include <algorithm>
using namespace std;

unsigned int arr[1001];
int N,res;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr,arr+N);

    for (int i = 0; i < N; ++i) {
        res += arr[i]*(N-i);
    }

    cout << res;

    return 0;
}
