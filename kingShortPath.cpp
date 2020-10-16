/// https://codeforces.com/problemset/problem/3/A

#include <deque>
#include <iostream>
#include <string>

using namespace std;

const int boardSize = 8, inf = 1e9;

void inputCoord(int &x, int &y) {
    string str;
    cin >> str;
    x = str[0] - 'a', y = str[1] - '1';
}

int **dis, **pdx, **pdy;
bool **flag;

int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, -1, 1};
string dirName[] = {"D", "U", "L", "R","RU", "LD", "RD", "LU"};

bool check(int i){
    return 0 <= i && i < boardSize;
}

int bfs(int xS, int yS, int xT, int yT) {
    dis[xS][yS] = 0;
    flag[xS][yS] = true;
    pdx[xS][yS] = pdy[xS][yS] = -1;
    deque<pair<int, int>> q;
    q.push_back(make_pair(xS, yS));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop_front();
        if (x == xT && y == yT) return dis[x][y];
        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i], v = y + dy[i];
            if (!check(u) || !check(v)) continue;
            if (!flag[u][v]) {
                flag[u][v] = true;
                q.push_back(make_pair(u, v));
                dis[u][v] = dis[x][y] + 1;
                pdx[u][v] = x;
                pdy[u][v] = y;
            }
        }
    }
    return inf;
}

string getDir(int x, int y, int u, int v) {
    int dirX = u - x;
    int dirY = v - y;
    for(int i = 0 ; i < 8 ; ++ i){
        if(dirX == dx[i] && dirY == dy[i]) return dirName[i];
    }
    return "";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif

    int xS, yS, xT, yT;
    inputCoord(xS, yS);
    inputCoord(xT, yT);

    dis = new int *[boardSize];
    pdx = new int *[boardSize];
    pdy = new int *[boardSize];

    flag = new bool *[boardSize];
    for (int i = 0; i < boardSize; ++i) {
        dis[i] = new int[boardSize];
        flag[i] = new bool[boardSize];
        pdx[i] = new int[boardSize];
        pdy[i] = new int[boardSize];
        for (int j = 0; j < boardSize; ++j) {
            dis[i][j] = pdx[i][j] = pdy[i][j] = 0;
            flag[i][j] = false;
        }
    }
    int res = bfs(xS, yS, xT, yT);
    cout << res << "\n";
    string *path = new string[res];
    int count = 0;
    while (xT != xS || yT != yS) {
        int x = pdx[xT][yT], y = pdy[xT][yT];
        string dir = getDir(x, y, xT, yT);
        path[count++] = dir;
        xT = x, yT = y;
    }
    for (int i = res - 1; i >= 0; --i) cout << path[i] << "\n";
}