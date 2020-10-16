/// https://codeforces.com/problemset/problem/4/A
#include <iostream>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    int weight;
    cin >> weight;
    if(weight & 1 || weight == 2) {
        cout << "NO";
    } else cout << "YES";
}