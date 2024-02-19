#include <iostream>
using namespace std;

int N,a,b,c,d,firstDay,lastDay,res;
int daysOfMonth[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
int gf[366];
bool check;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while(N--){
        cin >> a >> b >> c >> d;
        if(daysOfMonth[c-1]+d >= 335) check = true; // 끝까지 피는 꽃 존재여부 확인
        if(gf[daysOfMonth[a-1]+b] < daysOfMonth[c-1]+d)
            gf[daysOfMonth[a-1]+b] = daysOfMonth[c-1]+d;
    }

//    sort(flowers.begin(),flowers.end());   시간복잡도 터짐? 맞네 pair nlogn
    if(!check){
        cout << 0;
        return 0;
    }
    firstDay = 0;
    lastDay = 60;
    int next = 0;
    int prev;


    while(lastDay < 335 ){ // 12월1일
        prev = firstDay;
        for (int i = firstDay+1; i <= lastDay; ++i) {
            if(gf[i] > next){
                next = gf[i];
                firstDay = i;
            }
        }
        if(firstDay == prev) {
            res = 0;  // 중간에 끊기는 경우
            break;
        }

        lastDay = next;
        res++;
    }
    cout << res;
    return 0;
}
