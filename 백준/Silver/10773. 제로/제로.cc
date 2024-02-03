#include <iostream>
#include <stack>
using namespace std;

int K,x;
stack<int>st;

int main() {
    cin >> K;
    while(K--){
        cin >> x;
        if(x == 0) st.pop();
        else st.push(x);
    }

    while(!st.empty()){
        K+=st.top();
        st.pop();
    }

    cout << K+1;

    return 0;
}
