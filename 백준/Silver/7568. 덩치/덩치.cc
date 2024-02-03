#include<iostream>
#include<vector>
using namespace std;

int N,x,y,cnt;
vector<pair<int,int>>v;

int main(){
    cin >> N;
    while(N--){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    for (int i = 0; i < v.size(); ++i) {
        cnt = 1;
        for (int j = 0; j < v.size(); ++j) {
            if(v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
        }
        cout << cnt << " ";
    }

}