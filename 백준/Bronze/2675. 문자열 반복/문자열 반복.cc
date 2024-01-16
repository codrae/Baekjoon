#include <iostream>
using namespace std;

string S;
int T,R;

int main() {
    cin >> T;
    while(T--){
        cin >> R >> S;
        for (int i = 0; i < S.length(); ++i) {
            for (int j = 0; j < R; ++j) {
                cout << S[i];
            }
        }
        cout << endl;
    }



    return 0;
}
