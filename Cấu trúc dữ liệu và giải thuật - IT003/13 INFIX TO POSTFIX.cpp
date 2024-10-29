#include <iostream>
using namespace std;
#define MAXN 100

struct NODE {
    char info;
    NODE* pNext;
};

NODE* CreateNode(char x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

struct stack {
    NODE* top;
};

bool empty(const stack& s) {
    return (s.top == NULL);
}

void CreateEmptyStack(stack& s) {
    s.top = NULL;
}

void push(stack& s, char x) {
    NODE* p = CreateNode(x);
    if (s.top == NULL) s.top = p;
    else {
        p->pNext = s.top;
        s.top = p;
    }
}

void pop(stack& s) {
    if (s.top == NULL) return;
    NODE* p = s.top;
    s.top = s.top->pNext;
    delete p;
}

char& top(stack s) {
    return s.top->info;
}

bool isOperator(char x) {
    return ((x == '-') || (x == '+') || (x == '*') || (x == '/') || (x == '^'));
}

bool isBracket(char x) {
    return ((x == '(') || (x == ')'));
}

void Input_infix(char infix[], int& n) {
    char k;
    cin >> k;
    n = 0;
    while (k != '#') {
        infix[n++] = k;
        cin >> k;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infix_to_postfix(char infix[], int ni, char postfix[], int& np) {
    stack s;
    np = 0;
    CreateEmptyStack(s);

    for (int i = 0; i < ni; i++) {
        char c = infix[i];

        // If the character is a digit, add it to the postfix expression
        if (isdigit(c)) {
            postfix[np++] = c;
        }
        // If the character is an opening bracket, push it to the stack
        else if (c == '(') {
            push(s, c);
        }
        // If the character is a closing bracket, pop from stack until '('
        else if (c == ')') {
            while (!empty(s) && top(s) != '(') {
                postfix[np++] = top(s);
                pop(s);
            }
            pop(s); // Remove '(' from stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!empty(s) && precedence(top(s)) >= precedence(c)) {
                postfix[np++] = top(s);
                pop(s);
            }
            push(s, c);
        }
    }

    // Pop all remaining operators from the stack
    while (!empty(s)) {
        postfix[np++] = top(s);
        pop(s);
    }
    postfix[np] = '\0'; // Null-terminate the postfix expression
}

void Output(char postfix[], int np) {
    for (int i = 0; i < np; i++) {
        cout << postfix[i]<<" ";
    }
}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);
    infix_to_postfix(infix, ni, postfix, np);
    Output(postfix, np);

    return 0;
}
