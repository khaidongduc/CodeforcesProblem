#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

char str[1000005];
int dp[1000005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif

    stack<int> st;
    scanf("%s", str);
    int ans = 0, maxLength = 0, i, length = strlen(str);
    for (i = 0; i < length; ++i) {
        if (str[i] == '(')
            st.push(i);
        else {
            if (!st.empty()) {
                int t = st.top();
                st.pop();
                dp[i] = dp[t - 1] + i - t + 1;
                if (dp[i] > maxLength) {
                    maxLength = dp[i];
                    ans = 1;
                } else if (dp[i] == maxLength)
                    ++ans;
            }
        }
    }
    if (!maxLength) ans = 1;
    printf("%d %d\n", maxLength, ans);
}