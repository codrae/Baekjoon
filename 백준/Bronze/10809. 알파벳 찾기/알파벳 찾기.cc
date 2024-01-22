#include <iostream>
using namespace std;

string S;
bool check[101];
int res[101];

int main() {
    cin >> S;

    for (int i = 0; i <S.length(); ++i) {
        if(!check[S[i]-97]){
            res[S[i]-97] = i;
            check[S[i]-97] = true;
        }
    }

    for (int i = 0; i <26; ++i) {
        if(check[i]) cout<<res[i] << ' ';
        else cout << -1 <<' ';
    }
    return 0;
}
