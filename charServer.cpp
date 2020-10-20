/// https://codeforces.com/problemset/problem/5/A

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxLength = 110;

int main() {
    char s[maxLength];
    int totalByteSend = 0;
    int numPeople = 0;
    while (fgets(s, 110, stdin)) {
        if (s[0] == '+') ++ numPeople;
        else if (s[0] == '-') -- numPeople;
        else {
            int messageLength = 0;
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == ':') {
                    messageLength = strlen(s) - i - 1;
                    break;
                }
            }
            totalByteSend += numPeople * messageLength;
        }
    }
    printf("%d\n", totalByteSend);
}