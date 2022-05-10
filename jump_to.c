#include <stdio.h>

unsigned jump_to(unsigned x, unsigned y);

int main() {
    jump_to(1, 17);
}

unsigned jump_to(unsigned x, unsigned y) {
    unsigned n = 0;
    while(y > x){
        if(y % 2 == 0 && y / 2 >= x)
            y /= 2;
        else
            y -= 1;
        n++;
    }
    printf("%d", n);
    return n;
}