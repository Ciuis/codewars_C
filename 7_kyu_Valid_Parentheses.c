/*Write a function that takes a string of parentheses, and determines if the order of the parentheses is valid. The function should return true if the string is valid, and false if it's invalid.
Examples

"()"              =>  true
")(()))"          =>  false
"("               =>  false
"(())((()())())"  =>  true

        Constraints

0 <= length of input <= 100

All inputs will be strings, consisting only of characters ( and ).
Empty strings are considered balanced (and therefore valid), and will be tested.
For languages with mutable strings, the inputs should not be mutated.


Protip: If you are trying to figure out why a string of parentheses is invalid, paste the parentheses into the code editor, and let the code highlighting show you!

 bool valid_parentheses(const char* s)
{
  int n = 0;

  for (; *s && n >= 0; s++)
    n += (*s == '(') - (*s == ')');

  return n == 0;
}

valid_parentheses(char*s,t){for(t=1;*s*t;t-=*s++%2*2-1);return!--t;}

 */

#include <stdbool.h>
#include <stdlib.h.>

struct Stack_t {
    char data;
    struct Stack_t* next;
};

void push(struct Stack_t** top_ref, int new_d) {
    struct Stack_t* new_stack = (struct Stack_t*)malloc(sizeof(struct Stack_t));
    if (new_stack == NULL) {
        exit(0);
    }
    new_stack->data = new_d;
    new_stack->next = (*top_ref);
    (*top_ref) = new_stack;
}

int pop(struct Stack_t** top_ref)  {
    char res;
    struct Stack_t* top;

    if (*top_ref == NULL) {
        exit(0);
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

bool match(char c_a, char c_b) {
    if (c_a == '(' && c_b == ')') return true;
    else return false;
}

bool valid_parentheses(const char* str) {
    int i = 0;

    struct Stack_t* stack = NULL;

    while (str[i]) {
        if (str[i] == '(') push(&stack, str[i]);
        if (str[i] == ')') {
            if (stack == NULL) return false;

            else if (!match(pop(&stack), str[i])) return false;
        }
        ++i;
    }
    if (stack == NULL) return true;
    else return false;

}