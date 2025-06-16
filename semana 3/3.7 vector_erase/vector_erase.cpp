#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    int size;
    cin >> size;
    
    for (int i=0; i<size; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    int q;
    cin >> q;
    v.erase(v.begin()+(q-1));
    
    int q1, q2;
    cin >> q1 >> q2;
    v.erase(v.begin()+(q1-1),v.begin()+(q2-1));
    
    cout << v.size()<< endl;
    
    for (auto i : v){
        cout << i << " ";
    }
    
    return 0;
}