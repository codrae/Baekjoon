#include<iostream>
#include<vector>
using namespace std;

int N,M,cnt,res,c,r;
bool pm;
vector<pair<int,int>>cctv;
vector<pair<int,int>>case3;
int office[10][10];

void update(){
    cnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(office[i][j] == 0) cnt++;
            if(cnt >= res) return;
        }
    }
    res = cnt;
    return;
}

void seeN(int x, int y){ // 북
    while(y>0){
        y--;
        if(office[y][x]==14) break;
        else if(office[y][x] < 9) {
            pm ? office[y][x]++ : office[y][x]--;
        }
    }
}

void seeE(int x, int y){ // 동
    while(x < M-1){
        x++;
        if(office[y][x]==14) break;
        else if(office[y][x] < 9) {
            pm ? office[y][x]++ : office[y][x]--;
        }
    }
}

void seeW(int x, int y){ // 서
    while(x>0){
        x--;
        if(office[y][x]==14) break;
        else if(office[y][x] < 9) {
            pm ? office[y][x]++ : office[y][x]--;
        }
    }
}

void seeS(int x, int y){ // 남
    while(y < N-1){
        y++;
        if(office[y][x]==14) break;
        else if(office[y][x] < 9) {
            pm ? office[y][x]++ : office[y][x]--;
        }
    }
}

void check(int di,int column, int row){
        switch (di%4) {
            case 0 :
                seeE(row,column); //동
                break;
            case 1 :
                seeW(row,column); //서
                break;
            case 2 :
                seeS(row,column); //남
                break;
            case 3 :
                seeN(row,column); //북
                break;
        }
    }

void func(int k, int st){
    if(k == cctv.size()){
        update();
        return;
    }
    int i = st; // 모든 cctv에 대해
        c = cctv[i].first; r = cctv[i].second;
        if(office[c][r] == 13){ // 한방향 처리
            pm = true;
            for (int j = 0; j < 4; ++j) {
                check(j,c,r);
            }
            func(k+1,st+1);
            pm = false;
            c = cctv[i].first; r = cctv[i].second;
            for (int j = 0; j < 4; ++j) {
                check(j,c,r);
            }
        }
        else if(office[c][r] == 10){ // 두방향 처리
            for (int j = 0; j < 3; j+=2) {
                pm = true;
                check(j,c,r);
                check(j+1,c,r);
                func(k+1,st+1);
                pm = false;  c = cctv[i].first; r = cctv[i].second;
                check(j,c,r);
                check(j+1,c,r);
            }
        }
        else{ // 4방향 처리
            //3번case 예외처리 , for문에서 동시수행 불가능
            if(office[c][r] == 11){
                for (int j = 0; j <case3.size(); ++j) {
                    pm = true;
                    check(case3[j].first,c,r);
                    check(case3[j].second,c,r);
                    func(k+1,st+1);
                    pm=false;
                    c = cctv[i].first; r = cctv[i].second;
                    check(case3[j].first,c,r);
                    check(case3[j].second,c,r);
                }
            }
            else{for (int j = 0; j < 4; ++j) {
                    pm = true;
                    check(j, c, r);
                    if (office[c][r] > 11) {
                        check(j + 1, c, r);
                        check(j + 2, c, r);
                    }
                    func(k + 1, st + 1);
                    pm = false;
                    c = cctv[i].first; r = cctv[i].second;
                    check(j, c, r);
                    if (office[c][r] > 11) {
                        check(j + 1, c, r);
                        check(j + 2, c, r);
                    }
                }
            }
        }
    }


int main(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> office[i][j];
            if(office[i][j] > 0 && office[i][j] < 6) {
                cctv.push_back(make_pair(i, j));
                office[i][j] += 8;
            }
            if(office[i][j] == 6) office[i][j] += 8;
        }
    }
    case3.push_back(make_pair(0,2));
    case3.push_back(make_pair(0,3));
    case3.push_back(make_pair(1,2));
    case3.push_back(make_pair(1,3));

    res = 99;
    func(0,0);

    cout << res;
}

