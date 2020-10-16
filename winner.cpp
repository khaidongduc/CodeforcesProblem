/// https://codeforces.com/problemset/problem/2/A

#include <iostream>
#include <map>

using namespace std;

const int inf = 1e8;

int main(){
    //freopen("main.inp", "r", stdin);
    int n, *scores; cin >> n;
    string *names;
    names = new string[n];
    scores = new int[n];

    map<string, int> scoreboard;
    for(int i = 0 ; i < n ; ++ i){
        cin >> names[i] >> scores[i];
        scoreboard[names[i]] += scores[i];
    }
    int maxScore = -inf;
    for(auto it = scoreboard.begin(); it != scoreboard.end() ; ++ it){
        string name = it->first;
        int score = it->second;
        if(score > maxScore){
            maxScore = score;
        }
    }
    map <string, int> anotherScoreboard;
    string winner = "";
    for(int i = 0 ; i < n ; ++ i){
        string name = names[i];
        int score = scores[i];
        if(scoreboard[name] == maxScore){
            anotherScoreboard[name] += score;
            if(anotherScoreboard[name] >= maxScore){
                winner = name;
                break;
            }
        }
    }
    cout << winner;
}