#include <iostream>
using namespace std;

string S;
int cnt;

int main() {
    getline(cin, S);

    for (int i = 0; i < S.length(); ++i) {
        if(S[i] == ' ')cnt++;
    }
    if(S[0] == ' ') cnt--;
    if(S[S.length()-1] == ' ') cnt--;
    cout << cnt+1;

    return 0;
}
