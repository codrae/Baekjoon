#include <iostream>
#include <vector>
using namespace std;

string s;
bool check;
int res,idx,st;
vector<int>v;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin,s);

    st = 100;

    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '+' || s[i] == '-'){
            v.push_back(stoi(s.substr(idx,i-idx)));
            idx = i+1;
            if(s[i] == '-' && !check){
                check = true;
                st = v.size();
            }
        }
    }
    v.push_back(stoi(s.substr(idx)));

    for (int i = 0; i < v.size(); ++i) {
        if(i < st) res += v[i];
        else res -= v[i];
    }

    cout << res;
    return 0;
}
