/*
Among the ruins of an ancient city a group of archaeologists found a mysterious function with lots of HOLES in it called getNum(n) (or get_num(n) in ruby, python, or r). They tried to call it with some arguments. And finally they got this journal:

getNum(300) #-> returns 2
getNum(90783) #-> returns 4
getNum(123321) #-> returns 0
getNum(89282350306) #-> returns 8
getNum(3479283469) #-> returns 5
The archaeologists were totally stuck with this challenge. They were all in desperation but then.... came YOU the SUPER-AWESOME programmer. Will you be able to understand the mystery of this function and rewrite it?*/

#include <stdio.h>

int pattern[] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1};;

int get_num(long long a);

int main(void) {
    long long a = 89282350306;
    printf("%d\n", get_num(a));
}

int get_num(long long a) {
    int count = 0;
    char str[20];
    sprintf(str, "%lld", a);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0';
            count += pattern[digit];
        }
    }

    return count;
}

/*
 * static int HOLES[] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1};

int get_num(long a)
{
  return a ? HOLES[a % 10] + get_num(a / 10) : 0;
}
 */