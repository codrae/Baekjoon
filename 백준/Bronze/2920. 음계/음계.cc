#include <iostream>
using namespace std;

int main() {
    string as = "1 2 3 4 5 6 7 8";
    string de = "8 7 6 5 4 3 2 1";
    string s;
    getline(cin,s);

    if(s == as) cout << "ascending";
    else if (s == de) cout << "descending";
    else cout << "mixed";
    return 0;
}
