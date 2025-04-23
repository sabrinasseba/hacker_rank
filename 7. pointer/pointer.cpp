#include <stdio.h>
#include <cmath>

void update(int *a,int *b) {
    int aa = *a;
    int be = *b;
    
    (*a) = aa + be; 
    (*b) = abs(aa - be);    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}