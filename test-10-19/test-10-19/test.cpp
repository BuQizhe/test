#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int get_priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

void infix_to_postfix(char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (is_digit(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;  // 弹出左括号
        }
        else if (is_operator(infix[i])) {
            while (top >= 0 && get_priority(stack[top]) >= get_priority(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else {
            // 非法字符
            printf("Error: Invalid character '%c'\n", infix[i]);
            exit(1);
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int evaluate_postfix(char* postfix) {
    int stack[MAX_SIZE];
    int top = -1;
    int i, a, b;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (is_digit(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        }
        else if (is_operator(postfix[i])) {
            b = stack[top--];
            a = stack[top--];
            switch (postfix[i]) {
            case '+':
                stack[++top] = a + b;
                break;
            case '-':
                stack[++top] = a - b;
                break;
            case '*':
                stack[++top] = a * b;
                break;
            case '/':
                stack[++top] = a / b;
                break;
            }
        }
        else {
            // 非法字符
            printf("Error: Invalid character '%c'\n", postfix[i]);
            exit(1);
        }
    }

    return stack[0];
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int result;

    printf("请输入中缀表达式：");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("后缀表达式为：%s\n", postfix);

    result = evaluate_postfix(postfix);
    printf("计算结果为：%d\n", result);

    return 0;
}


//
//相关问题：
//
//什么是中缀表达式？
//什么是后缀表达式？
//如何将中缀表达式转换为后缀表达式？
//如何使用栈实现对后缀表达式的求值？
//手动输入中缀表达式后，需要进行以下步骤将其转换为后缀表达式并计算出结果：
//
//定义一个栈用于存储运算符，一个队列用于存储后缀表达式。
//从左到右扫描中缀表达式的每一个元素。
//如果是数字，则直接将其加入队列。
//如果是运算符，则判断其与栈顶运算符的优先级。
//如果该运算符的优先级大于栈顶运算符，则将该运算符压入栈中。
//如果该运算符的优先级小于等于栈顶运算符，则将栈顶运算符弹出并加入队列中，直到栈为空或栈顶运算符优先级小于该运算符。
//如果是左括号“(”，则直接压入栈中。
//    如果是右括号“)”，则依次弹出栈顶运算符并加入队列中，直到遇到左括号为止。注意左括号只弹出不加入队列。
//    重复步骤2 - 6，直到扫描完整个中缀表达式。
//    将栈中剩余的运算符依次弹出并加入队列中。
//    从左到右扫描后缀表达式的每一个元素。
//    如果是数字，则压入栈中。
//    如果是运算符，则从栈中弹出两个数进行计算，并将结果压入栈中。
//    重复步骤9 - 11，直到扫描完整个后缀表达式。
//    最终栈中的唯一元素即为结果。
//    下面是一个示例程序的代码，可以实现将手动输入的中缀表达式转换为后缀表达式并计算出结果的功能：手动输入中缀表达式，编写程序，转换成后缀表达式机算出结果c语言
//
//
//    手动输入中缀表达式，编写程序将其转换为后缀表达式并计算结果的过程如下：
//
//    首先，需要了解中缀表达式和后缀表达式的定义和转换规则。中缀表达式是指运算符位于两个操作数之间的表达式，例如 3 + 4。而后缀表达式是指运算符位于操作数之后的表达式，例如 3 4 + 。
//    接下来，需要编写程序读入中缀表达式，并对其进行处理，将其转换为后缀表达式。这可以使用栈来实现，具体步骤如下： a.从左到右扫描中缀表达式，如果是数字，则直接输出到后缀表达式中。 b.如果是左括号，则将其压入栈中。 c.如果是右括号，则将栈中的元素依次弹出并输出到后缀表达式中，直到遇到左括号。左右括号不输出到后缀表达式中。 d.如果是运算符，则比较其与栈顶运算符的优先级。如果栈顶运算符优先级低于当前运算符，则将当前运算符压入栈中；否则将栈顶运算符弹出并输出到后缀表达式中，然后再比较下一个栈顶运算符的优先级，直到当前运算符优先级大于栈顶运算符的优先级为止。 e.如果扫描完毕，但是栈中还有元素，则依次弹出并输出到后缀表达式中。
//    得到后缀表达式后，需要对其进行求值。这可以使用栈来实现，具体步骤如下： a.从左到右扫描后缀表达式，如果是数字，则压入栈中。 b.如果是运算符，则弹出栈顶的两个元素进行运算，并将运算结果压入栈中。 c.扫描完毕后，栈中只剩下一个元素，即为计算结果。
//    这里提供一个简单的 C 语言程序示例：

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

    typedef struct Stack {
    int top;
    char items[MAX_STACK_SIZE];
} Stack;

typedef struct Queue {
    int front, rear;
    char items[MAX_QUEUE_SIZE];
} Queue;

void push(Stack* s, char c) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = c;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

char peek(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top];
}

void enqueue(Queue* q, char c) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        exit(1);
    }
    q->items[++q->rear] = c;
}

char dequeue(Queue* q) {
    if (q->front > q->rear) {
        printf("Queue Underflow\n");
        exit(1);
    }
    return q->items[q->front++];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    Stack s;
    Queue q;
    s.top = -1;
    q.front = 0;
    q.rear = -1;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
            while (isdigit(infix[i]))
                postfix[j++] = infix[i++];
            postfix[j++] = ' ';
        }
        else if (is_operator(infix[i])) {
            while (s.top != -1 && precedence(infix[i]) <= precedence(peek(&s)))
                postfix[j++] = pop(&s);
            push(&s, infix[i++]);
        }
        else if (infix[i] == '(') {
            push(&s, infix[i++]);
        }
        else if (infix[i] == ')') {
            while (peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s);
            i++;
        }
        else {
            i++;
        }
    }
    while (s.top != -1)
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

int evaluate_postfix(char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0, operand1, operand2, result;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int operand = 0;
            while (isdigit(postfix[i]))
                operand = operand * 10 + (postfix[i++] - '0');
            push(&s, operand);
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (postfix[i]) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            push(&s, result);
            i++;
        }
        else {
            i++;
        }
    }
    return pop(&s);
}

int main() {
    char infix[100], postfix[100];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}