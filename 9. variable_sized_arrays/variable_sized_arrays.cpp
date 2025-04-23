#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> p(n);
    
    for (int i=0; i<n; i++){
        int k;
        cin >> k;
        
        vector<int>linha(k);
        
        for (int j=0; j<k; j++){
            cin >> linha[j];
        }
        
    p[i] = linha;
    
    }
    
    for (int k=0; k<q; k++){
        int i, j;
        cin >> i >> j;
        cout << p[i][j] << endl;
    }
    
    return 0;
}