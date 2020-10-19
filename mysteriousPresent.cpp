#include <algorithm>
#include <iostream>

using namespace std;

struct Envelope {
    int width, height, id;
    Envelope() { Envelope(0, 0, 0); }
    Envelope(int width, int height, int id) {
        this->width = width;
        this->height = height;
        this->id = id;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
#endif
    int numEnvelope, cardWidth, cardHeight;
    cin >> numEnvelope >> cardWidth >> cardHeight;
    Envelope *envelopes = new Envelope[numEnvelope];
    for (int i = 0; i < numEnvelope; ++i) {
        cin >> envelopes[i].width >> envelopes[i].height;
        envelopes[i].id = i;
    }
    sort(envelopes, envelopes + numEnvelope, [](Envelope a, Envelope b) {
        return (a.width < b.width) ||
               (a.width == b.width && a.height < b.height);
    });
    int *f = new int[numEnvelope];
    int *prev = new int[numEnvelope];
    for(int i = 0; i < numEnvelope ; ++ i) f[i] = 0, prev[i] = -1;
    int ans = 0;
    for (int i = 0; i < numEnvelope; ++i) {
        if (cardWidth < envelopes[i].width &&
            cardHeight < envelopes[i].height) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (cardWidth < envelopes[j].width &&
                    cardHeight < envelopes[j].height &&
                    envelopes[i].width > envelopes[j].width &&
                    envelopes[i].height > envelopes[j].height) {
                    if(f[i] < f[j] + 1) f[i] = f[j] + 1, prev[i] = j;
                }
            }
        }
        if(f[ans] < f[i]) ans = i;
    }
    int res = f[ans];
    cout << res << "\n";
    int count = res;
    int *choosen = new int[count];
    while(count){
        choosen[--count] = envelopes[ans].id + 1;
        ans = prev[ans];
    }
    for(int i = 0 ; i < res ; ++ i) cout << choosen[i] << " ";
}