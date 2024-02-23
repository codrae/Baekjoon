#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[20002];
vector<int>vertex[20002];
queue<int>q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0; i < edge.size(); i ++){
        vertex[edge[i][0]].push_back(edge[i][1]);
        vertex[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        for(int i = 0; i < vertex[q.front()].size(); i++){
            if(visited[vertex[q.front()][i]] == 0){
                q.push(vertex[q.front()][i]);
                visited[vertex[q.front()][i]] = visited[q.front()] + 1; 
            }
        }
        q.pop();
    }
    int max = *max_element(visited,visited+n+1);
    for(int i = 1; i <= n; i++){
        if(visited[i] == max) answer++;
    }
    
    
    return answer;
}