#include <iostream>
#include <queue>

using namespace std;

int T,A,B,L,R;
queue<int>q;
string visited[10001];

void bfs(){
    while(!q.empty()){
        if(q.front() == B) return;
        if(visited[(q.front()*2)%10000] == ""){

            q.push((q.front()*2)%10000);
            visited[(q.front()*2)%10000] = visited[q.front()] + "D";
        }
        if(q.front() == 0 && visited[9999] == ""){
            visited[9999] = visited[0] + "S";
            q.push(9999);
        }
        if(q.front() > 0 && visited[q.front()-1] == ""){
            visited[q.front()-1] = visited[q.front()]+"S";
            q.push(q.front()-1);
        }
        L = (q.front()*10)%10000 + q.front()/1000;
        R = q.front()/10 +(q.front()%10)*1000;
        if(visited[L] == ""){
            q.push(L);
            visited[L] = visited[q.front()]+"L";
        }
        if(visited[R] == ""){
            q.push(R);
            visited[R] = visited[q.front()]+"R";
        }
        q.pop();
    }

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--){
        cin >> A >> B;

        //init
        q = queue<int>();
        q.push(A);
        fill_n(visited,10001,"");
        visited[A] = "A";

        bfs();
        cout << visited[B].substr(1,visited[B].length()-1) << '\n';
    }

    return 0;
}

