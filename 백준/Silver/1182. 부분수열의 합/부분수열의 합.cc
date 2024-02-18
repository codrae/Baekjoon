#include <iostream>
using namespace std;

int N,S,res,sum;
int arr[21];
bool visit[21];

void func(int k, int st){
    if(k == N){
        return;
    }
    for (int i = st; i < N; ++i) {
//        if(!visit[i]){
//            visit[i] = true;
            sum += arr[i];
            if (sum == S) res++;
            func(k + 1, i + 1);
            sum -= arr[i];
            //visit[i] = false;
        }
    }




int main() {
    cin >> N >> S;
    for (int i = 0; i <N; ++i) {
        cin >> arr[i];
    }
    func(0,0);
    cout << res;
    return 0;
}
