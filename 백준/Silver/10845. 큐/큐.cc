#include <iostream>
#include <queue>
using namespace std;

int N,x,st,dc;
string cmd;
int arr[100000];


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    while(N--){
        cin >> cmd;
        if(cmd == "push"){
            cin >> x;
            arr[dc] = x;
            dc++;
        }
        else if(cmd == "pop"){
            if(dc-st == 0) cout << -1 << '\n';
            else {
                cout << arr[st] << '\n';
                st++;
            }
        }
        else if(cmd == "size"){
            cout << dc-st << '\n';
        }
        else if(cmd == "empty" ){
            if(dc-st)  cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if(cmd == "front")
        {
            if(dc-st) cout << arr[st] << '\n';
            else cout << -1 << '\n';
        }
        else {
            if(dc-st) cout << arr[dc-1] << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}
