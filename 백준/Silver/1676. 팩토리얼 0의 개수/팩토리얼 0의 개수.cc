#include <iostream>
using namespace std;

int N,cntT,cntF,tmp;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    N++;
    while(--N){

        tmp = N;
        while(tmp%2==0){
            tmp /= 2;
            cntT++;
        }
        while(tmp%5==0){
            tmp /= 5;
            cntF++;
        }

    }

    cout << min(cntT,cntF);

    return 0;
}
