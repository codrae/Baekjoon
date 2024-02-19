#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L,C;
char c;
string consonant,gather,tmp;
vector<string>a,b,res;

void comC(int st){
    if(tmp.size()>=1){
        a.push_back(tmp);
    }
    for (int i = st; i < consonant.size(); ++i) {
        if(tmp.find(consonant[i]) != string::npos) continue;
        tmp += consonant[i];
        comC(st+1);
        tmp.pop_back();
    }
}

void comG(int st){
    if(tmp.size()>=2){
        b.push_back(tmp);
    }
    for (int i = st; i < gather.size(); ++i) {
        if(tmp.find(gather[i]) != string::npos) continue;
        tmp += gather[i];
        comG(st+1);
        tmp.pop_back();
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s = "aeiou";
    cin >> L >> C;
    for (int i = 0; i < C; ++i) {
        cin >> c;
        if(s.find(c)==string::npos){
            gather += c;
        }
        else consonant += c;
    }

    comC(0);
    comG(0);

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if(a[i].size() + b[j].size() == L){
                res.push_back(a[i]+b[j]);
            }
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        sort(res[i].begin(),res[i].end());
    }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << '\n';
    }


    return 0;
}
