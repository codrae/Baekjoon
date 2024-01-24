#include <iostream>
#include <stack>
using namespace std;



int main() {

    int n,x;
    int arr[100002];
    stack<int>a;
    stack<bool>op,res;
    bool check = false;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    x = 1;
    a.push(x);
    op.push(1);
    x++;

    for (int i = 1; i <= n; ++i) {
        if(a.empty()){
            a.push(x);
            op.push(true);
            x++;
        }

        if(arr[i] > a.top()){
            while(a.top() != arr[i]){
                a.push(x);
                op.push(true);
                x++;
            }
        }
        else if(arr[i] < a.top()){
            check = true;
            cout << "NO";
            return 0;
        }

        // arr[i]와 a.top()이 같아짐
        if(!a.empty()) {
            a.pop();
            op.push(false);
        }
    }

    if(check) cout << "NO";
    else{
        while(!op.empty()) {
            res.push(op.top());
            op.pop();
        }
        while(!res.empty()){
            if(res.top()) cout << "+\n";
            else cout << "-\n";
            res.pop();
        }
    }


    return 0;
}
