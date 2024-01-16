#include <iostream>
using namespace std;

string s;
int arr[36];
int n,res,idx;

int main() {
    // A - Z = 65 - 90 a -z = 97 - 122
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        n = int(s[i]);
        n > 90 ? arr[n-97]++ : arr[n-65]++;
    }
    for (int i = 0; i < 36 ; ++i) {
        if(arr[i] > res) {
            res = arr[i];
            idx = i;
        }
    }

    for (int i = 0; i < 36 ; ++i) {
        if(arr[i] == res && idx != i)
            idx = -2; // ? 의 int - 65
    }

    cout << char(idx+65);

    return 0;
}
