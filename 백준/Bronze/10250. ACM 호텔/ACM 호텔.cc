#include <iostream>
using namespace std;

int T,H,W,N,Y,X;

int main() {
    cin >> T;
    while(T--){
        cin >> H >> W >> N;
        Y = N%H;
        if(Y == 0) Y = H;
        cout << Y;
        X = (N/H) +1;
        if(N%H == 0) X--;
        if(X < 10) cout << 0;
        cout << X;
        cout << endl;
    }
    return 0;
}
