/// https://codeforces.com/problemset/problem/1/A

#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n, m, a;
    cin >> n >> m >> a;
    long long res = 1LL * ceil(1.0 * n / a) * ceil(1.0 * m / a);
    cout << res;
}