#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,x,y;
vector<pair<int,int>>v;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while(N--){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());

    for(auto p : v){
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}
