#include<iostream>
#include<stack>
using namespace std;

string s;
stack<int>st;
bool check;

int main(){
    while(s !="."){
        while(!st.empty())st.pop();

        getline(cin,s);
        if(s==".") break;
        check = true;

        for (int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') st.push('(');
            else if(s[i] == '[') st.push('[');
            else if(s[i] == ')'){
                if(st.empty()) {
                    check = false; break;
                }
                else if(st.top() == '('){
                    st.pop();
                }
                else st.push(s[i]);
            }
            else if(s[i] == ']'){
                if(st.empty()) {
                    check = false; break;
                }
                else if(st.top() == '['){
                    st.pop();
                }
                else st.push(s[i]);
            }
        }

        if(!st.empty()) check = false;

        if(check)cout << "yes\n";
        else cout << "no\n";

    }

}