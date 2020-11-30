#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> a(3, 5);
    for(int elem : a) cout << elem << "\n";

}