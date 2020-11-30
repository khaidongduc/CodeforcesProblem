#include <iostream>

using namespace std;

bool checkTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

bool checkDegenerate(int a, int b, int c) {
    return (a + b >= c) && (a + c >= b) && (b + c >= a);
}

string getRes(int *a) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                if (checkTriangle(a[i], a[j], a[k])) return "TRIANGLE";
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                if (checkDegenerate(a[i], a[j], a[k])) return "SEGMENT";
            }
        }
    }
    return "IMPOSSIBLE";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    int *a = new int[4];
    for (int i = 0; i < 4; ++i) cin >> a[i];
    cout << getRes(a);
}