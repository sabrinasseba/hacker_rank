#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {    
    vector<int>v;
    int size;
    cin >> size;
    
    for (int i=0; i<size; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (auto i : v){
        cout << i << " ";
    }
      
    return 0;
}