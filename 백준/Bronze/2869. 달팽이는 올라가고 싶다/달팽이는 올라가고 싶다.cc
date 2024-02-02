#include <iostream>
using namespace std;

int V,A,B,cur,res;

int main() {
    cin >> A >> B >> V;

    res += (V-A) / (A-B);
    cur = res *(A-B);

    while(cur < V){
        cur += A;
        res++;
        if(cur>=V) break;
        cur -= B;
    }

    cout << res;

    return 0;
}
