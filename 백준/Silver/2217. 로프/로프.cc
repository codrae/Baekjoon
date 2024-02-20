#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,less<int>>pq;
int N,k,maxWeight;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while(N--){
        cin >> k;
        pq.push(k);
    }
    k = 0;
    while(!pq.empty()){
        k++;
        if(maxWeight < pq.top()*k){
            maxWeight = pq.top()*k;
        }
        pq.pop();
    }
    cout << maxWeight;

    return 0;
}
