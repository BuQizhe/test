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
            top--;  // ����������
        }
        else if (is_operator(infix[i])) {
            while (top >= 0 && get_priority(stack[top]) >= get_priority(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else {
            // �Ƿ��ַ�
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
            // �Ƿ��ַ�
            printf("Error: Invalid character '%c'\n", postfix[i]);
            exit(1);
        }
    }

    return stack[0];
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int result;

    printf("��������׺���ʽ��");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("��׺���ʽΪ��%s\n", postfix);

    result = evaluate_postfix(postfix);
    printf("������Ϊ��%d\n", result);

    return 0;
}


//
//������⣺
//
//ʲô����׺���ʽ��
//ʲô�Ǻ�׺���ʽ��
//��ν���׺���ʽת��Ϊ��׺���ʽ��
//���ʹ��ջʵ�ֶԺ�׺���ʽ����ֵ��
//�ֶ�������׺���ʽ����Ҫ�������²��轫��ת��Ϊ��׺���ʽ������������
//
//����һ��ջ���ڴ洢�������һ���������ڴ洢��׺���ʽ��
//������ɨ����׺���ʽ��ÿһ��Ԫ�ء�
//��������֣���ֱ�ӽ��������С�
//���������������ж�����ջ������������ȼ���
//���������������ȼ�����ջ����������򽫸������ѹ��ջ�С�
//���������������ȼ�С�ڵ���ջ�����������ջ���������������������У�ֱ��ջΪ�ջ�ջ����������ȼ�С�ڸ��������
//����������š�(������ֱ��ѹ��ջ�С�
//    ����������š�)���������ε���ջ�����������������У�ֱ������������Ϊֹ��ע��������ֻ������������С�
//    �ظ�����2 - 6��ֱ��ɨ����������׺���ʽ��
//    ��ջ��ʣ�����������ε�������������С�
//    ������ɨ���׺���ʽ��ÿһ��Ԫ�ء�
//    ��������֣���ѹ��ջ�С�
//    ���������������ջ�е������������м��㣬�������ѹ��ջ�С�
//    �ظ�����9 - 11��ֱ��ɨ����������׺���ʽ��
//    ����ջ�е�ΨһԪ�ؼ�Ϊ�����
//    ������һ��ʾ������Ĵ��룬����ʵ�ֽ��ֶ��������׺���ʽת��Ϊ��׺���ʽ�����������Ĺ��ܣ��ֶ�������׺���ʽ����д����ת���ɺ�׺���ʽ��������c����
//
//
//    �ֶ�������׺���ʽ����д������ת��Ϊ��׺���ʽ���������Ĺ������£�
//
//    ���ȣ���Ҫ�˽���׺���ʽ�ͺ�׺���ʽ�Ķ����ת��������׺���ʽ��ָ�����λ������������֮��ı��ʽ������ 3 + 4������׺���ʽ��ָ�����λ�ڲ�����֮��ı��ʽ������ 3 4 + ��
//    ����������Ҫ��д���������׺���ʽ����������д�������ת��Ϊ��׺���ʽ�������ʹ��ջ��ʵ�֣����岽�����£� a.������ɨ����׺���ʽ����������֣���ֱ���������׺���ʽ�С� b.����������ţ�����ѹ��ջ�С� c.����������ţ���ջ�е�Ԫ�����ε������������׺���ʽ�У�ֱ�����������š��������Ų��������׺���ʽ�С� d.��������������Ƚ�����ջ������������ȼ������ջ����������ȼ����ڵ�ǰ��������򽫵�ǰ�����ѹ��ջ�У�����ջ��������������������׺���ʽ�У�Ȼ���ٱȽ���һ��ջ������������ȼ���ֱ����ǰ��������ȼ�����ջ������������ȼ�Ϊֹ�� e.���ɨ����ϣ�����ջ�л���Ԫ�أ������ε������������׺���ʽ�С�
//    �õ���׺���ʽ����Ҫ���������ֵ�������ʹ��ջ��ʵ�֣����岽�����£� a.������ɨ���׺���ʽ����������֣���ѹ��ջ�С� b.�������������򵯳�ջ��������Ԫ�ؽ������㣬����������ѹ��ջ�С� c.ɨ����Ϻ�ջ��ֻʣ��һ��Ԫ�أ���Ϊ��������
//    �����ṩһ���򵥵� C ���Գ���ʾ����

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