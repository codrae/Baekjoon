#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,x,y;
vector<pair<int,int>>v;

int main() {
    cin >> N;
    while(N--){
        cin >> x >> y;
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());

    for(auto a: v){
        cout << a.second << " " << a.first << '\n';
    }
    return 0;
}
