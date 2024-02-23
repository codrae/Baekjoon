#include <string>
#include <vector>
#include <string>
#include <map>

using namespace std;

int sc[51];
int graph[51][51];
int will[51];
map<string,int>mp;

int nameToIdx(string name){
    return mp.find(name)->second;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(int i = 0; i < friends.size(); i ++){
        mp.insert({friends[i],i});
    }
    int A,B,sep;

    for(int i = 0; i < gifts.size(); i++){
        sep = gifts[i].find(' ');
        A = nameToIdx(gifts[i].substr(0,sep));
        B = nameToIdx(gifts[i].substr(sep+1));
        graph[A][B]++;
        sc[A]++;
        sc[B]--;
    }
    
    for(int A = 0; A < friends.size()-1; A++){
        for (int B = A+1; B < friends.size(); B++){
            if(graph[A][B] == 0 && graph[B][A] == 0){
                if(sc[A] > sc[B]) will[A]++;
                    else if(sc[A] < sc[B]) will[B]++;
            }
            else{
                if( graph[A][B] > graph[B][A] ) will[A]++;
                else if(graph[B][A] > graph[A][B]) will[B]++;
                else{
                    if(sc[A] > sc[B]) will[A]++;
                    else if(sc[A] < sc[B]) will[B]++;
                }
            }
        }
    }
    
    for(int i = 0; i < friends.size(); i++){
        if(answer < will[i]) answer = will[i];
    }
    
    return answer;
}