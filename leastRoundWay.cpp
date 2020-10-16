/// https://codeforces.com/problemset/problem/2/B
#include <stdio.h>
#include <iostream>
 
using namespace std;
 
const int inf = 1e8, maxN = 1005;
 
int getNum(int num, int val){
    int res = 0;
    while(val % num == 0 && val > 0) ++ res, val /= num;
    return res;
}
 
int n, num2[maxN][maxN], num5[maxN][maxN], val[maxN][maxN];
bool check(int i){
    return 1 <= i && i <= n;
}
 
 
int f2[maxN][maxN], f5[maxN][maxN];
bool mem2[maxN][maxN], mem5[maxN][maxN];
 
int calc2(int i, int j){
    if(!check(i) || !check(j)) return inf;
    if(mem2[i][j]) return f2[i][j];
    mem2[i][j] = true;
    if(i == 1 && j == 1) return f2[i][j] = num2[i][j];
    return f2[i][j] = min(calc2(i - 1, j), calc2(i, j - 1)) + num2[i][j];
}
 
int calc5(int i, int j){
    if(!check(i) || !check(j)) return inf;
    if(mem5[i][j]) return f5[i][j];
    mem5[i][j] = true;
    if(i == 1 && j == 1) return f5[i][j] = num5[i][j];
    return f5[i][j] = min(calc5(i - 1, j), calc5(i, j - 1)) + num5[i][j];
}
 
 
void backtrack2(int i, int j){
    if(i == 1 && j == 1) return;
    if(calc2(i, j) == calc2(i - 1, j) + num2[i][j]){
        backtrack2(i - 1, j);
        putchar('D');
        return;
    }
    if(calc2(i, j) == calc2(i, j - 1) + num2[i][j]){
        backtrack2(i, j - 1);
        putchar('R');
        return;
    }
}
 
void backtrack5(int i, int j){
    if(i == 1 && j == 1) return;
    if(calc5(i, j) == calc5(i - 1, j) + num5[i][j]){
        backtrack5(i - 1, j);
        putchar('D');
        return;
    }
    if(calc5(i, j) == calc5(i, j - 1) + num5[i][j]){
        backtrack5(i, j - 1);
        putchar('R');
        return;
    }
}
 
int main(){
    //freopen("main.inp", "r", stdin);
    scanf("%d", &n);
    bool hasZero = false;
    pair<int, int> zeroPos;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            scanf("%d", &val[i][j]);
            if(val[i][j] == 0) {
                hasZero = true;
                zeroPos = make_pair(i, j);
            }
            num2[i][j] = getNum(2, val[i][j]);
            num5[i][j] = getNum(5, val[i][j]);
        }
    }
 
 
    int res = min(calc2(n, n), calc5(n, n));
    if(hasZero && res > 1) {
        res = 1;
        printf("%d\n", res);
        for(int i = 1 ; i <= zeroPos.first - 1 ; ++ i) putchar('D');
        for(int i = 1 ; i <= zeroPos.second - 1 ; ++ i) putchar('R');

        for(int i = zeroPos.first + 1 ; i <= n ; ++ i) putchar('D');
        for(int i = zeroPos.second + 1; i <= n ; ++ i) putchar('R');
        return 0;        
    }
    printf("%d\n", res);
    if(res == calc2(n, n)) backtrack2(n, n);
    else backtrack5(n, n);
}