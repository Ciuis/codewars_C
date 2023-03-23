/*The police have placed radars that will detect those vehicles that exceed the speed limit on that road. If the driver's speed is 10km/h to 19km/h above the speed limit, the fine will be 100 dollars, if it is exceeded by 20km/h to 29km/h the fine will be 250 dollars and if it is exceeded by more than 30km/h the fine will be 500 dollars.

You will be provided with the speed limits of those roads with radar as a collection of speedlimits [90,100,110,120,....] and the speed of the driver will be the same on all roads and can never be negative and the amount of the fine will be accumulated example 95km/h.

Example (Speed=100, Signals=[110,100,80]-> 250)*/

#include <stddef.h>
#include <stdio.h>

unsigned speed_limit(unsigned speed, size_t length, const unsigned signals[length]);

int main(void) {
    unsigned speed = 60;
    size_t length = 5;
    unsigned signals[] = {95, 120, 110, 100, 70};

    printf("%d", speed_limit(speed, length, signals));
}

unsigned speed_limit(unsigned speed, size_t length, const unsigned signals[length]) {
    int penalty = 0;
    for (size_t i = 0; i < length; ++i) {
        if ((int)speed - (int)signals[i] < 10) {
            ;
        } else if ((int)speed - (int)signals[i] < 20) {
            penalty += 100;
        } else if ((int)speed - (int)signals[i] < 30) {
            penalty += 250;
        } else if ((int)speed - (int)signals[i] >= 30){
            penalty += 500;
        }
    }
    return penalty;
}