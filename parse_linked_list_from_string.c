/*Parse a linked list from a string
        Related Kata

        Although this Kata is not part of an official Series, you may want to complete this Kata before attempting this one as these two Kata are deeply related.
Preloaded

        Preloaded for you is a class, struct or derived data type Node ( depending on the language ) used to construct linked lists in this Kata:

typedef struct node {
    int data;
    struct node *next;
} Node;

NOTE: In C, the Node struct is placed on top of your main solution because otherwise the compiler complains about not recognizing the struct (even if it is defined in the Preloaded section). Attempts to modify it (e.g. to cheat the tests in some way) will likely result in a test crash so it is not recommended for you to modify that section ;)
Prerequisites

        This Kata assumes that you are already familiar with the idea of a linked list. If you do not know what that is, you may want to read up on this article on Wikipedia. Specifically, the linked lists this Kata is referring to are singly linked lists, where the value of a specific node is stored in its data / $data/Data property, the reference to the next node is stored in its next / $next / Next property and the terminator for a list is null / NULL / nil / nullptr / null() / [].

Additionally, this Kata assumes that you have basic knowledge of Object-Oriented Programming ( or a similar concept ) in the programming language you are undertaking. If you have not come across Object-Oriented Programming in your selected language, you may want to try out an online course or read up on some code examples of OOP in your selected language up to ( but not necessarily including ) Classical Inheritance.

Specifically, if you are attempting this Kata in PHP and haven't come across OOP, you may want to try out the first 4 Kata in this Series.
Task

        Create a function parse which accepts exactly one argument string / $string / s / strrep ( or similar, depending on the language ) which is a string representation of a linked list. Your function must return the corresponding linked list, constructed from instances of the Node class/struct/type. The string representation of a list has the following format: the value of the node, followed by a whitespace, an arrow and another whitespace (" -> "), followed by the rest of the linked list. Each string representation of a linked list will end in "null" / "NULL" / "nil" / "nullptr" / "null()" depending on the language you are undertaking this Kata in. For example, given the following string representation of a linked list:

"1 -> 2 -> 3 -> NULL"

... your function should return:

// Code example not applicable to C - the Node struct does not have a constructor function

Note that due to the way the constructor for Node is defined, if a second argument is not provided, the next / $next / Next field is automatically set to null / NULL / nil / nullptr ( or equivalent in your language ). That means your function could also return the following ( if it helps you better visualise what is actually going on ):*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// "Preloaded Code" (do NOT modify!)
typedef struct node {
    int data;
    struct node *next;
} Node;

Node* add(char data);
Node *parse(char *string);

int main() {
    char* text = "1->2->3->4";
    Node* n = parse(text);

    while (n->next != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
}

Node *parse(char *string) {
    if (strcmp(string, "NULL") == 0)
        return NULL;
    Node *result = malloc(sizeof(Node));
    sscanf(string, "%d", &(result->data));
    result->next = parse(string + (result->data == 0 ? 0 : (int)log10(result->data)) + 5);
    return result;
}

/*
Node *parse(char *s) {
    if (!strcmp(s, "NULL")) return NULL;
    Node *n = malloc(sizeof(Node));
    sscanf(s, "%d", &n->data);
    n->next = parse(strchr(s, ' ') + strlen(" -> "));
    return n;
}*/
