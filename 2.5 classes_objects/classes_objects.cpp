#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student{
    private:
    int scores[5];
    public:
    void input(){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        scores[0] = a;
        scores[1] = b;
        scores[2] = c;
        scores[3] = d;
        scores[4] = e; 
    }
    int calculateTotalScore(){
        int sum = scores[0] + scores[1] + scores[2] + scores[3] + scores[4];
        return sum;    
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}