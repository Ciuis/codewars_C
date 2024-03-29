/*Create a function that will take any amount of money and break it down to the smallest number of bills as possible. Only integer amounts will be input, NO floats. This function should output a sequence, where each element in the array represents the amount of a certain bill type. The array will be set up in this manner:

array[0] ---> represents $1 bills

        array[1] ---> represents $5 bills

        array[2] ---> represents $10 bills

        array[3] ---> represents $20 bills

        array[4] ---> represents $50 bills

        array[5] ---> represents $100 bills

        In the case below, we broke up $365 into 1 $5 bill, 1 $10 bill, 1 $50 bill, and 3 $100 bills.

giveChange(365) // =>  [0,1,1,0,1,3]

In this next case, we broke $217 into 2 $1 bills, 1 $5 bill, 1 $10 bill, and 2 $100 bills.

giveChange(217) // => [2,1,1,0,0,2]*/

#include <stdio.h>
#include <string.h>

void give_change (unsigned amount, unsigned bills[6]);

int main() {
    unsigned amount = 437;
    unsigned bills[6];

    give_change(amount, bills);

    for (int i = 0; i < sizeof(bills) / sizeof(bills[0]); ++i) {
        printf("%d", bills[i]);
    }

}

void give_change (unsigned amount, unsigned bills[6]) {
    int val[] = {1, 5, 10, 20, 50, 100};
    // fill the bills array. Be careful, it is not zeroed !
    int idx = 5;

    if (amount == 0) {
        for (int i = 5; i >0; --i) {
            bills[i] = 0;
        }
    }

    bills[5] = amount / 100;
    amount %= 100;
    bills[4] = amount / 50;
    amount %= 50;
    bills[3] = amount / 20;
    amount %= 20;
    bills[2] = amount / 10;
    amount %= 10;
    bills[1] = amount / 5;
    amount %= 5;
    bills[0] = amount;



/*    while (amount > 3) {
        bills[idx] = amount / val[idx];
        amount -= val[idx] * bills[idx];
        printf("%d\n", amount);
        --idx;
    }*/
}