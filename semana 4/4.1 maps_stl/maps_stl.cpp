#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    
    map<string, int>m;
    
    int q;
    cin >> q;
    //q = m.size();
    
    for(int i=1; i<=q; i++){
        int key_type;
        string nome;
        cin >> key_type >> nome;
        
        if (key_type == 1){
            int nota;
            cin >> nota;
            
            m[nome] += nota;
        }
        
        else if (key_type == 2){
            m.erase(nome);
        }
        
        else if (key_type == 3){
            if (m.find(nome) != m.end()){
                cout << m[nome] << endl;
            }
            else {
                cout << 0 << endl;
            }   
        }
    }
    return 0;
}



