/// https://codeforces.com/problemset/problem/5/B
#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

const int maxLength = 1005;
const int maxLine = 1005;

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    char s[maxLine][maxLength];
    int numLine = 0;
    while (fgets(s[numLine], maxLength, stdin)) {
        char &lastChar = s[numLine][strlen(s[numLine]) - 1];
        if (lastChar == '\n') lastChar = 0;
        ++numLine;
    }
    int maxLineLength = 0;
    for (int i = 0; i < numLine; ++i)
        maxLineLength = max(maxLineLength, int(strlen(s[i])));

    int resLineLength = maxLineLength + 2;
    for (int i = 0; i < resLineLength; ++i) printf("*");
    printf("\n");
    int unevenCount = 0;
    for (int i = 0; i < numLine; ++i) {
        int numSpace = (resLineLength - strlen(s[i]) - 2);
        printf("*");

        if (numSpace & 1) {
            int numLeft = numSpace / 2 + (unevenCount++ & 1);
            int numRight = numSpace - numLeft;
            for (int i = 0; i < numLeft; ++i) printf(" ");
            printf("%s", s[i]);
            for (int i = 0; i < numRight; ++i) printf(" ");
        } else {
            int numLeft = numSpace / 2;
            int numRight = numSpace - numLeft;
            for (int i = 0; i < numLeft; ++i) printf(" ");
            printf("%s", s[i]);
            for (int i = 0; i < numRight; ++i) printf(" ");
        }
        printf("*\n");
    }
    for (int i = 0; i < resLineLength; ++i) printf("*");
}