#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N,M,x,cnt;
vector<int>v;
vector<pair<int,int>>p;

bool cmp(pair<int,int>a, pair<int,int>b){
    return a.second < b.second;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    cin >> M;

    for (int i = 0; i < M; ++i) {
        cin >> x;
        p.push_back(make_pair(x,i));
    }

    sort(p.begin(),p.begin()+M);

    for (int i = 0; i < M; ++i) {

        while(p[i].first > v[cnt]){
            if(cnt == v.size()-1) break;
            cnt++;
        }

        if(p[i].first == v[cnt]) p[i].first = 1;
        else    p[i].first = 0;
    }

    sort(p.begin(),p.end(),cmp);

    for (int i = 0; i < M; ++i) {
        cout << p[i].first << '\n';
    }

    return 0;
}
