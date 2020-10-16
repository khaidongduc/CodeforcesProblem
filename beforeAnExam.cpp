/// https://codeforces.com/problemset/problem/4/B

#include <iostream>

using namespace std;

int d, sumTime;
int *minTime, *maxTime;

bool **mem;
int **f;
int calc(int day, int sumTime){
    if(sumTime < 0) return -1;
    if(day == -1 && sumTime > 0) return -1;
    if(day == -1 && sumTime == 0) return 0;

    if(mem[day][sumTime]) return f[day][sumTime];
    mem[day][sumTime] = true;

    for(int hour = minTime[day] ; hour <= maxTime[day] ; ++ hour){
        if(calc(day - 1, sumTime - hour) != -1) return f[day][sumTime] = hour;
    }
    return f[day][sumTime] = -1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    int d, sumTime;
    cin >> d >> sumTime;
    minTime = new int[d];
    maxTime = new int[d];
    for(int i = 0 ; i < d ; ++ i){
        cin >> minTime[i] >> maxTime[i];
    }

    mem = new bool* [d];
    f = new int* [d];
    for(int i = 0 ; i < d ; ++ i){
        mem[i] = new bool[sumTime + 1];
        f[i] = new int[sumTime + 1];
        for(int j = 0 ; j <= sumTime ; ++ j){
            mem[i][j] = false;
            f[i][j] = 0;
        }        
    }

    if(calc(d - 1, sumTime) != -1) {
        cout << "YES" << "\n";
        int dayCount = d - 1, sumT = sumTime;
        int* schedule = new int[d]; 
        while(dayCount != -1){
            int timeStudy = calc(dayCount, sumT);
            schedule[dayCount] = timeStudy;
            -- dayCount;
            sumT -= timeStudy;
        }
        for(int i = 0 ; i < d ; ++ i) cout << schedule[i] << " ";
    } 
    else cout << "NO";
}