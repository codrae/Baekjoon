#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool visit[101][101];

int is,js,sum;
vector<string>mapsTmp;

bool isSea(int y, int x){
    return (y < 0 || x < 0 || x >= js || y >= is || mapsTmp[y][x] == 'X');
}

void dfs(int y, int x){
                if(!isSea(y,x) && !visit[y][x]){
                    visit[y][x] = true;
                    sum += mapsTmp[y][x] -'0';
                    for(int k = 0; k < 4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    dfs(ny,nx);
                }
    
            }
}

vector<int> solution(vector<string> maps) {
    mapsTmp = maps;
    vector<int> answer;
    is = maps.size();
    js = maps[0].size();
    
    for(int i = 0; i < is; i++){
        for(int j = 0; j < js; j++){
                sum = 0;
                dfs(i,j);
                if(sum!=0){ 
                answer.push_back(sum);
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}