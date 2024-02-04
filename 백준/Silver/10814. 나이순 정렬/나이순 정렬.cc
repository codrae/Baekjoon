#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,age;
string name;
vector<string>v[201];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> age >> name;
        v[age].push_back(name);
    }

    for (int i = 1; i < 201; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << i << " " << v[i][j] << '\n';
        }
    }

    return 0;
}
//qsort, stable_sort