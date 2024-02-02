#include <iostream>
using namespace std;

int N,c;
string s;

int main() {
    cin >> N;
    s = "666";

    while(N--){
        c++;
        while(to_string(c).find(s) == string::npos) c++;
    }

    cout << c;

    return 0;
}
