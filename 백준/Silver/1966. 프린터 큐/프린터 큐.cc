#include <iostream>
#include <queue>

using namespace std;

queue<int>docs;
int tc,N,M,doc,turn,res;
int cnt[10];

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    while(tc--){
        cin >> N >> M;
        docs = queue<int>(); // 초기화
        res = 0;
        for (int i = 0; i <10; ++i) {
            cnt[i] = 0;
        }

        while(N--){
            cin >> doc;
            docs.push(doc);
            cnt[doc]++;
        }

        //turn init
        for (int i = 9; i > 0 ; --i) {
            if(cnt[i]!=0) {
                turn = i; break;
            }
        }

        while(!docs.empty()){

            if(docs.front() == turn){ // 출력을 하는 경우
                cnt[docs.front()]--;
                if(cnt[docs.front()] == 0) {
                    while(cnt[turn] == 0){
                        turn --;
                    }
                }
                docs.pop();
                M--;
                res++;

                if(M == -1) break;
            }
            else{ // 뒤로 보내는 경우
                M--;
                docs.push(docs.front());
                docs.pop();
                if(M == -1) M = docs.size()-1; // 해당문서가 뒤로 가는경우
            }
        }

    cout << res << '\n';
    }



    return 0;
}
