#include<iostream>
#include <map>
using namespace std;

int N,M,x;
map<int,int>mp;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    while(N--){
        cin >> x;
        if(!mp.count(x)) mp[x] = 1;
        else mp[x]++;
    }

    cin >> M;
    while(M--){
        cin >> x;
        cout << mp[x] << " ";
    }
    return 0;
}
