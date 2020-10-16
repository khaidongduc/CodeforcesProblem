/// https://codeforces.com/problemset/problem/1/B

#include <iostream>
#include <string>

using namespace std;

bool isNumeration(string str){
    if(str[0] != 'R') return false;
    if(str[1] < '0' || str[1] > '9') return false;
    for(int i = 2, str_len = str.length() ; i < str_len ; ++ i){
        if(str[i] < '0' || str[i] > '9'){
            if(str[i] == 'C') return true;
            return false;
        }
    }
    return false;
}

string convert_to_numeration(string str){
    int X = 0, Y = 0;
    int i = 0, str_len = str.length();
    for(; i < str_len && 'A' <= str[i] && str[i] <= 'Z'; ++ i){
        Y = Y * 26 + str[i] - 'A' + 1;
    }
    for(; i < str_len && '0' <= str[i] && str[i] <= '9'; ++ i){
        X = X * 10 + str[i] - '0';
    }
    return 'R' + to_string(X) + 'C' + to_string(Y);
}

string convert_to_spreadsheet(string str){
    int X = 0, Y = 0;
    int i = 1, str_len = str.length();
    for(; i < str_len; ++ i){
        if(str[i] == 'C') break;
        X = X * 10 + str[i] - '0';
    }
    ++i;
    for(; i < str_len; ++ i){
        Y = Y * 10 + str[i] - '0';
    }
    string resY = "";
    while(Y > 0){
        char c = 'A' + (Y - 1) % 26;
        resY = c + resY;
        Y = (Y - 1) / 26;
    }
    return resY + to_string(X);
}

int main(){
    //freopen("main.inp", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++ i){
        string str, res;
        cin >> str;
        bool type = isNumeration(str);
        if(type) res = convert_to_spreadsheet(str);
        else res = convert_to_numeration(str);
        cout << res << "\n";
    }
}