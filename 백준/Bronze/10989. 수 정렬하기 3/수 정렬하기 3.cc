#include <iostream>
using namespace std;

int N,x;
int arr[10001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while(N--){
        cin >> x;
        arr[x]++;
    }

    for (int i = 1; i < 10001; ++i) {
        while(arr[i]--){
            cout << i << '\n';
        }
    }

    return 0;
}
