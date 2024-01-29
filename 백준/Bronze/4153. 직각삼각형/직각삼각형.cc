#include <iostream>
#include <cmath>
using namespace std;

int a,b,c,A,B,C;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin >> a >> b >> c;
        if(a==0&&b==0&&c==0) break;
        A = pow(a, 2);
        B = pow(b,2);
        C= pow(c,2);
        if(A+B == C ||A+C == B || A == B+C ) cout << "right\n";
        else cout << "wrong\n";
    }
    return 0;
}
