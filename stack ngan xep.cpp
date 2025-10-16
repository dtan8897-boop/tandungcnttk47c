#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
typedef struct {
    char data[MAX];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
}
bool isEmpty(Stack *s) {
    return s->top == -1;
}
bool isFull(Stack *s) {
    return s->top == MAX - 1;
}
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
bool checkBalance(char *expression) {
    Stack s;
    init(&s);
    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s)) return false;
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, c)) return false;
        }
    }
    return isEmpty(&s);
}
int main() {
    char expression[100];
    gets(expression);

    if (checkBalance(expression))
        printf("Hop le\n");
    else
        printf("Khong hop le\n");
    return 0;
}

