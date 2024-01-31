#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string s;
vector<string>v[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while(N--) {
        cin >> s;
        v[s.length()-1].push_back(s);
    }

    for (int i = 0; i < 50 ; ++i) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
    }
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << '\n';
        }
    }

    return 0;
}
