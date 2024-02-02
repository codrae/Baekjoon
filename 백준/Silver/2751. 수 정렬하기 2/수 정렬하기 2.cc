#include <iostream>
#include<set>
using namespace std;

int N,x;
set<int>s;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    while(N--){
        cin >> x;
        s.insert(x);
    }

    for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
        cout << *i << '\n';
    }

     // for(auto x : s) cout << x << '\n';

    return 0;
}
