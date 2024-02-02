#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s,rev;

int main() {
    cin >> n;
    while(n != 0){
        s = rev = to_string(n);
        reverse(rev.begin(),rev.end());
        s == rev ? cout << "yes\n" : cout <<  "no\n";
        cin >> n;
    }

    return 0;
}
