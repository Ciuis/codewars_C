/*
It's bonus time in the big city! The fatcats are rubbing their paws in anticipation... but who is going to make the most money?

Build a function that takes in two arguments (salary, bonus). Salary will be an integer, and bonus a boolean.

If bonus is true, the salary should be multiplied by 10. If bonus is false, the fatcat did not make enough money and must receive only his stated salary.

Return the total figure the individual will receive as a string prefixed with "£" (= "\u00A3", JS, Go, Java, Scala, and Julia), "$" (C#, C++, Ruby, Clojure, Elixir, PHP, Python, Haskell, and Lua) or "¥" (Rust).
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned long long ull;

char *bonus_time(ull salary, bool bonus) {
    char* money = (char*)calloc(100, 1);
    sprintf(money, "%s%llu", "$", bonus == true ? salary * 10 : salary);
    return money;
}