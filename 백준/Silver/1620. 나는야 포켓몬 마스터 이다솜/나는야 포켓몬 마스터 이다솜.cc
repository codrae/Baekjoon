#include <iostream>
#include <map>
using namespace std;

int N,M;
map<string,int>si;
map<int,string>is;
string s;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >>s;
        si.insert(make_pair(s,i));
        is.insert(make_pair(i,s));
    }

    while(M--){
        cin >> s;
        if(s[0] > 64) cout << si[s] << '\n';
        else cout << is[stoi(s)] << '\n';
    }
    return 0;
}
