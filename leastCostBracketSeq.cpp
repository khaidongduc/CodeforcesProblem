/// https://codeforces.com/problemset/problem/3/D
#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int maxN = 5e4;

struct Cost {
    int p, v;
    Cost(int p, int v) {
        this->p = p;
        this->v = v;
    }
    bool operator<(const Cost a) const { return v < a.v; }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    string str;
    cin >> str;
    int count = 0, len = str.length();

    priority_queue<Cost> q;

    long long res = 0;
    for (int i = 0; i < len; i++) {
        count += str[i] == '(';
        count -= str[i] == ')' || str[i] == '?';

        if (str[i] == '?') {
            int a, b;
            cin >> a >> b;
            q.push(Cost(i, b - a));
            res += b;
            str[i] = ')';
        }

        if (count < 0 && q.empty()) {
            res = -1;
            break;
        }

        if (count < 0) {
            Cost top = q.top();
            q.pop();
            res = res - top.v;
            str[top.p] = '(';
            count += 2;
        }
    }
    if (count > 0) res = -1;
    cout << res << "\n";
    if (res != -1) cout << str;
}
