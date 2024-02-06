#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;
int N,x;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    while(N--){
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}
