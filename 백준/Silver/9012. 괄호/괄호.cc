#include <iostream>
using namespace std;

int T,vps;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while(T--){
        cin >> s;
        vps = 0;
        for (int i = 0; i <s.length(); ++i) {
            if(s[i] == '(') vps++;
            else vps--;

            if(vps < 0) break;
        }

        if (vps == 0) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
