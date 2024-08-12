#include <iostream>
using namespace std;

string a,b,c;
int res;
string s;

int main() {
    cin >> a >> b >> c;
    if(a == "FizzBuzz") res = 3;
    else if (a == "Fizz"){
        if(b == "Buzz") res = stoi(c)+1;
        else res = stoi(b)+2;
    }
    else if (a=="Buzz"){
        if(b=="Fizz") res = stoi(c)+1;
        else res = stoi(b)+2;
    }
    else res = stoi(a)+3;

    if(res %3 == 0 && res % 5 ==0) cout << "FizzBuzz";
    else if(res %3 == 0) cout << "Fizz";
    else if(res %5 == 0) cout << "Buzz";
    else cout << res;

    return 0;
}
