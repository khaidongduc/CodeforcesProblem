/// https://codeforces.com/problemset/problem/3/B
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    #endif
    
    int numVehicle, lorrySize, *type, *capacity;
    cin >> numVehicle >> lorrySize;
    type = new int[numVehicle];
    capacity = new int[numVehicle];
    
    int numKayaks, numCatamarans;
    numKayaks = numCatamarans = 0;
    for(int i = 0 ; i < numVehicle ; ++ i) {
        cin >> type[i] >> capacity[i];
        if(type[i] == 1) ++ numKayaks;
        else ++ numCatamarans;
    }

    typedef pair<int, int> II;
    II *kayaks, *catamarans;
    kayaks = new II[numKayaks + 2];
    catamarans = new II[numCatamarans + 2];
    numKayaks = numCatamarans = 0;
    for(int i = 0 ; i < numVehicle ; ++ i){
        if(type[i] == 1) kayaks[numKayaks++] = II(capacity[i], i);
        else catamarans[numCatamarans++] = II(capacity[i], i);    
    }

    sort(kayaks, kayaks + numKayaks, greater<II>());
    sort(catamarans, catamarans + numCatamarans, greater<II>());

    int maxCapacity = 0;
    int countKayaks = 0, countCatamarans = 0;
    vector<int> choosenVehicles;

    if(lorrySize & 1){
        // if lorry size if odd, we add the first kayak in so we can 
        // send 2 kayaks in at once later
        maxCapacity += kayaks[countKayaks].first;
        if(countKayaks < numKayaks) choosenVehicles.push_back(kayaks[countKayaks++].second);
        -- lorrySize;
    }

    while(lorrySize > 0){
        // we either send 2 kayaks into the lorry or 1 catamaran 
        if(countKayaks >= numKayaks && countCatamarans >= numCatamarans)
            break;
        int kayakCapacity = kayaks[countKayaks].first + kayaks[countKayaks + 1].first;
        int kayakSize = 2;
        if(countKayaks + 1 >= numKayaks) kayakSize = 1;

        int catamaranCapacity = catamarans[countCatamarans].first;
        int catamaranSize = 2;
        if(kayakCapacity > catamaranCapacity){
            maxCapacity += kayakCapacity;
            lorrySize -= kayakSize;
            choosenVehicles.push_back(kayaks[countKayaks].second);
            if(countKayaks + 1 < numKayaks) choosenVehicles.push_back(kayaks[countKayaks + 1].second);
            countKayaks += 2;
        } else {
            maxCapacity += catamaranCapacity;
            lorrySize -= catamaranSize;
            choosenVehicles.push_back(catamarans[countCatamarans].second);
            countCatamarans += 1;
        }
    }
    cout << maxCapacity << "\n";
    for(int vehicle : choosenVehicles) cout << vehicle + 1 << " ";
}   