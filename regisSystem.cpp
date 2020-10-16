/// https://codeforces.com/problemset/problem/4/C
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    int n; cin >> n;
    map <string, int> nameMap;
    for(int i = 0 ; i < n ; ++ i){
        string name; cin >> name;
        int &val = nameMap[name];
        if(val == 0) cout << "OK\n";
        else{
            cout << name + to_string(val) << "\n";
        }
        ++ val;
    }
}